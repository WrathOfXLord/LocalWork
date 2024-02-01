#pragma once
#include "Exceptions.hpp"
#include "TemplateIterator.hpp"
#include <iostream>
#include <string>

template <typename Type> class MyTemplateVec {

    friend std::ostream &operator<<(std::ostream &streamlhs, const MyTemplateVec<Type> &rhs)   // cout << aVector; operator<<(cout, aVector);
    {
        streamlhs << "[";
        for(size_t i {0}; i < rhs._sizeVec; ++i)
        {
            rhs.print(streamlhs, i);
            if(i + 1 != rhs._sizeVec)
                streamlhs << ", ";
        }
        streamlhs << "]";

        return streamlhs;
    }

    // //might be needed for sfinae
    // template<typename... types>
    // using AllSame = std::enable_if_t<std::conjunction_v<std::is_same<Type, types>...>>;

private:
    size_t _sizeVec;
    size_t _capacity;
    Type *collection;

public:
    MyTemplateVec();
    explicit MyTemplateVec(size_t _sizeVec);
    MyTemplateVec(size_t _sizeVec, const Type &init);
    MyTemplateVec(const MyTemplateVec &source);
    MyTemplateVec(MyTemplateVec &&source);


    template<typename... types,
        typename = std::enable_if_t<(sizeof...(types) > 0) && (std::is_same_v<Type, std::decay_t<types>> && ...)>
    >
    MyTemplateVec(types &&... args)
    try: _sizeVec {sizeof...(args)}, _capacity {2 * (_sizeVec)}, collection {new Type[_capacity] {std::forward<types>(args)...}}
    {

    } catch(const std::bad_alloc &ex) {
        std::cerr << "Memory Allocation Failure. Terminating...\n";
        throw std::bad_alloc(); 
    }

    // multi args constructor end

    ~MyTemplateVec();

    MyTemplateVec &operator=(const MyTemplateVec &rhs);
    MyTemplateVec &operator=(MyTemplateVec &&rhs);
    Type &operator[](size_t index);
    inline size_t size() const { return _sizeVec; }
    inline size_t capacity() const { return _capacity; }
    void push_back(const Type &val);
    void push_back(Type &&val);
    Type pop_back();
    void swap(MyTemplateVec &rhs);
    void swapElements(size_t index1, size_t index2);
    void print(size_t rank) const;
    std::ostream &print(std::ostream &out, size_t rank) const;
    bool fit_to_shrink();
    void reserve(size_t size);

    constexpr inline Type *data() noexcept { return this->collection; }

    CustomIterator<Type> begin() noexcept { return CustomIterator {this->collection}; }
    CustomIterator<Type> end() noexcept { return CustomIterator {this->collection + this->_sizeVec}; }
    
};


//default constructor
template <typename Type> MyTemplateVec<Type>::MyTemplateVec()
: _sizeVec {0}, _capacity {0}, collection {nullptr}
{

}

//constructor with size
template <typename Type> MyTemplateVec<Type>::MyTemplateVec(size_t _sizeVec)
try: _sizeVec {_sizeVec}, _capacity {2 * _sizeVec}, collection {new Type [_capacity] {}}
{

} catch(const std::bad_alloc &ex) {
    std::cerr << "Memory Allocation Failure. Terminating...\n";
    throw std::bad_alloc(); 
}

//constructor with size and initial value
template <typename Type> MyTemplateVec<Type>::MyTemplateVec(size_t _sizeVec, const Type &init)
try: _sizeVec {_sizeVec}, _capacity {2 * _sizeVec}, collection {new Type [_capacity]}
{
    for(size_t i {0}; i < this->_capacity; ++i)
    {
        if(i < _sizeVec) {
            this->collection[i] = init;
            continue;
        }
        
        this->collection[i] = Type {};
    }
} catch(const std::bad_alloc &ex) {
    std::cerr << "Memory Allocation Failure. Terminating...\n";
    throw std::bad_alloc(); 
}

//copy constructor for const lvalue
template <typename Type> MyTemplateVec<Type>::MyTemplateVec(const MyTemplateVec &source)
try: _sizeVec {source._sizeVec}, _capacity {source._capacity}, collection {new Type [source._capacity]}
{
    for(size_t i {0}; i < this->_capacity; ++i)
    {
        if(i < _sizeVec) {
            this->collection[i] = source.collection[i];
            continue;
        }
        
        this->collection[i] = std::move(Type {});
    }
} catch(const std::bad_alloc &ex) {
    std::cerr << "Memory Allocation Failure. Terminating...\n";
    throw std::bad_alloc(); 
}

//move constructor for rvalue
template <typename Type> MyTemplateVec<Type>::MyTemplateVec(MyTemplateVec &&source)
: _sizeVec {source._sizeVec}, _capacity {source._capacity}, collection {source.collection}
{
    source.collection = nullptr;
}

//destructor
template <typename Type> MyTemplateVec<Type>::~MyTemplateVec()
{
    delete [] collection;
}


//copy assignment operator overload
template<typename Type> MyTemplateVec<Type> &MyTemplateVec<Type>::operator=(const MyTemplateVec<Type> &rhs)
{
    if(this == &rhs)
        return *this;
    if(this->_capacity != 0)
        delete [] this->collection;
    this->_sizeVec = rhs._sizeVec;
    this->_capacity = rhs._capacity;
    this->collection = new Type [this->_capacity];
    for(size_t i {}; i < this->_capacity; ++i)
    {
        if(i < this->_sizeVec) {
            this->collection[i] = rhs.collection[i];
            continue;
        }
        this->collection[i] = Type {};
    }
    return *this;
}

//move assignment operator overload
template<typename Type> MyTemplateVec<Type> &MyTemplateVec<Type>::operator=(MyTemplateVec<Type> &&rhs)
{
    if(this == &rhs)
        return *this;
    if(this->_capacity != 0)
        delete [] this->collection;
    this->_sizeVec = rhs._sizeVec;
    this->_capacity = rhs._capacity;
    this->collection = rhs.collection;
    rhs.collection = nullptr;
    return *this;
}


//subscript operator to reach elements, throws exception if out of range
template<typename Type> Type &MyTemplateVec<Type>::operator[](size_t index)
{
    if(index >= this->_sizeVec)
        throw VectorIndexOutOfRangeException {};
    return this->collection[index];
}

//add lvalue elements to the end
template<typename Type> void MyTemplateVec<Type>::push_back(const Type &val)
{
    if(this->_capacity == 0) {
        ++this->_sizeVec;
        this->_capacity = 3 * this->_sizeVec;
        this->collection = new Type[this->_capacity] {};
        this->collection[0] = val;
    } else if(this->_sizeVec + 1 <= this->_capacity) {
        this->collection[this->_sizeVec] = val;
        ++this->_sizeVec;
    } else {
        Type *tempCollection {this->collection};
        this->collection = new Type[2 * (this->_sizeVec + 1)] {};
        for(size_t i {}; i < this->_sizeVec; ++i)
            this->collection[i] = std::move(tempCollection[i]);
        delete [] tempCollection;
        this->collection[this->_sizeVec] = val;
        ++this->_sizeVec;
        this->_capacity = 2 * this->_sizeVec;
    }
}

//add rvalue elements to the end
template<typename Type> void MyTemplateVec<Type>::push_back(Type &&val)
{
    if(this->_capacity == 0) {
        ++this->_sizeVec;
        this->_capacity = 3 * this->_sizeVec;
        this->collection = new Type[this->_capacity] {};
        this->collection[0] = std::move(val);
    } else if(this->_sizeVec + 1 <= this->_capacity) {
        this->collection[this->_sizeVec] = std::move(val);
        ++this->_sizeVec;
    } else {
        Type *tempCollection {this->collection};
        this->collection = new Type[2 * (this->_sizeVec + 1)] {};
        for(size_t i {}; i < this->_sizeVec; ++i)
            this->collection[i] = std::move(tempCollection[i]);
        delete [] tempCollection;
        this->collection[this->_sizeVec] = std::move(val);
        ++this->_sizeVec;
        this->_capacity = 2 * this->_sizeVec;
    }
}

//remove last element and return
template <typename Type> [[nodiscard]] Type MyTemplateVec<Type>::pop_back()
{
    if(_sizeVec == 0)
        throw EmptyVectorException {};
    
    Type temp {std::move(this->collection[_sizeVec - 1])};
    this->collection[_sizeVec - 1] = std::move(Type {});
    --this->_sizeVec;
    return temp;
}

//swaps 2 vectors each other with the same data Type
template <typename Type> void MyTemplateVec<Type>::swap(MyTemplateVec<Type> &rhs)
{
    MyTemplateVec<Type> temp {std::move(*this)};
    *this = std::move(rhs);
    rhs = std::move(temp);
}

//swaps vector elements' indexes
template <typename Type> void MyTemplateVec<Type>::swapElements(size_t index1, size_t index2)
{
    if(index1 == index2)
        return;
    Type temp {std::move((*this)[index1])};;
    (*this)[index1] = std::move((*this)[index2]);
    (*this)[index2] = std::move(temp);
}

//print element at the given rank
template <typename Type> void MyTemplateVec<Type>::print(size_t rank) const
{
    if(rank >= _sizeVec)
        throw RankOutOfBoundsException {};
    if(this->_sizeVec == 0){
        std::cerr << "Vector contains no data\n";
        return;
    }
    std::cout << "[" << this->collection[rank] << "]";
}

//read element into given ostream
template <typename Type> std::ostream &MyTemplateVec<Type>::print(std::ostream &out, size_t rank) const
{
    if(rank >= _sizeVec)
        throw RankOutOfBoundsException {};
    if(this->_sizeVec == 0){
        std::cerr << "Vector contains no data\n";
        return out;
    }
    out << "[" << this->collection[rank] << "]";
    return out;
}

template <typename Type> bool MyTemplateVec<Type>::fit_to_shrink() {
    if(_capacity == _sizeVec) {
        return false;
    }
    Type *tmp {this->collection};
    collection = new Type[this->_sizeVec];
    for(size_t index {}; index != _sizeVec; ++index) {
        collection[index] = std::move(tmp[index]); 
    }
    _capacity = _sizeVec;
    delete [] tmp;
    return true;
}

template <typename Type> void MyTemplateVec<Type>::reserve(size_t size) {
    if(size <= this->_capacity)
        return;

    Type *tmp {this->collection};
    this->collection = new Type[size] {};
    if(tmp != nullptr) {
        for(size_t index {}; index != this->_sizeVec; ++index) {
            this->collection[index] = std::move(tmp[index]);
        }
        delete [] tmp;
    }

    this->_capacity = size;
}