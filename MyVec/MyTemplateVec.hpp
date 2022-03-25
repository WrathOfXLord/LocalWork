#pragma once
#include "Exceptions.hpp"
#include "TemplateIterator.hpp"
#include <iostream>
#include <string>

//pointer for any type
template <typename type> using ptr = type *;

template <typename type> class MyTemplateVec {
    friend std::ostream &operator<<(std::ostream &streamlhs, const MyTemplateVec<type> &rhs)   // cout << aVector; operator<<(cout, aVector);
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

private:
    size_t _sizeVec;
    size_t _capacity;
    type *collection;

public:
    MyTemplateVec();
    explicit MyTemplateVec(size_t _sizeVec);
    MyTemplateVec(size_t _sizeVec, const type &init);
    MyTemplateVec(const MyTemplateVec &source);
    MyTemplateVec(MyTemplateVec &&source);
    template<typename ...types> MyTemplateVec(type &&arg1, types &&... args);

    ~MyTemplateVec();

    MyTemplateVec &operator=(const MyTemplateVec &rhs);
    MyTemplateVec &operator=(MyTemplateVec &&rhs);
    type &operator[](size_t index);
    inline size_t size() const { return _sizeVec; }
    inline size_t capacity() const { return _capacity; }
    void push_back(const type &val);
    void push_back(type &&val);
    type pop_back();
    void swap(MyTemplateVec &rhs);
    void swapElements(size_t index1, size_t index2);
    void print(size_t rank) const;
    std::ostream &print(std::ostream &out, size_t rank) const;
    bool fit_to_shrink();

    CustomIterator<type> begin() noexcept { return CustomIterator {this->collection}; }
    CustomIterator<type> end() noexcept { return CustomIterator {this->collection + this->_sizeVec}; }
    
};

//variadic constructor for multiple argument initialisation via universal reference
template<typename type> template<typename ...types> MyTemplateVec<type>::MyTemplateVec(type &&arg1, types &&... args)
try: _sizeVec {sizeof...(args) + 1}, _capacity {2 * (_sizeVec)}, collection {new type[_capacity] {arg1, std::forward<types>(args)...}}
{

} catch(const std::bad_alloc &ex) {
    std::cerr << "Memory Allocation Failure. Terminating...\n";
    throw std::bad_alloc(); 
}


//default constructor
template <typename type> MyTemplateVec<type>::MyTemplateVec()
try: _sizeVec {0}, _capacity {2}, collection {new type [_capacity] {}}
{

} catch(const std::bad_alloc &ex) {
    std::cerr << "Memory Allocation Failure. Terminating...\n";
    throw std::bad_alloc(); 
}

//constructor with size
template <typename type> MyTemplateVec<type>::MyTemplateVec(size_t _sizeVec)
try: _sizeVec {_sizeVec}, _capacity {2 * _sizeVec}, collection {new type [_capacity] {}}
{

} catch(const std::bad_alloc &ex) {
    std::cerr << "Memory Allocation Failure. Terminating...\n";
    throw std::bad_alloc(); 
}

//constructor with size and initial value
template <typename type> MyTemplateVec<type>::MyTemplateVec(size_t _sizeVec, const type &init)
try: _sizeVec {_sizeVec}, _capacity {2 * _sizeVec}, collection {new type [_capacity]}
{
    for(size_t i {0}; i < this->_capacity; ++i)
    {
        if(i < _sizeVec) {
            this->collection[i] = init;
            continue;
        }
        
        this->collection[i] = type {};
    }
} catch(const std::bad_alloc &ex) {
    std::cerr << "Memory Allocation Failure. Terminating...\n";
    throw std::bad_alloc(); 
}

//copy constructor for const lvalue
template <typename type> MyTemplateVec<type>::MyTemplateVec(const MyTemplateVec &source)
try: _sizeVec {source._sizeVec}, _capacity {source._capacity}, collection {new type [source._capacity]}
{
    for(size_t i {0}; i < this->_capacity; ++i)
    {
        if(i < _sizeVec) {
            this->collection[i] = source.collection[i];
            continue;
        }
        
        this->collection[i] = type {};
    }
} catch(const std::bad_alloc &ex) {
    std::cerr << "Memory Allocation Failure. Terminating...\n";
    throw std::bad_alloc(); 
}

//move constructor for rvalue
template <typename type> MyTemplateVec<type>::MyTemplateVec(MyTemplateVec &&source)
: _sizeVec {source._sizeVec}, _capacity {source._capacity}, collection {source.collection}
{
    source.collection = nullptr;
}

//destructor
template <typename type> MyTemplateVec<type>::~MyTemplateVec()
{
    delete [] collection;
}


//copy assignment operator overload
template<typename type> MyTemplateVec<type> &MyTemplateVec<type>::operator=(const MyTemplateVec<type> &rhs)
{
    if(this == &rhs)
        return *this;
    if(this->_capacity != 0)
        delete [] this->collection;
    this->_sizeVec = rhs._sizeVec;
    this->_capacity = rhs._capacity;
    this->collection = new type [this->_capacity];
    for(size_t i {}; i < this->_capacity; ++i)
    {
        if(i < this->_sizeVec) {
            this->collection[i] = rhs.collection[i];
            continue;
        }
        this->collection[i] = type {};
    }
    return *this;
}

//move assignment operator overload
template<typename type> MyTemplateVec<type> &MyTemplateVec<type>::operator=(MyTemplateVec<type> &&rhs)
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
template<typename type> type &MyTemplateVec<type>::operator[](size_t index)
{
    if(index >= this->_sizeVec)
        throw VectorIndexOutOfRangeException {};
    return this->collection[index];
}

//add lvalue elements to the end
template<typename type> void MyTemplateVec<type>::push_back(const type &val)
{
    if(this->_sizeVec + 1 < this->_capacity)
    {
        this->collection[this->_sizeVec] = val;
        ++this->_sizeVec;
    } else {
        type *tempCollection {this->collection};
        this->collection = new type[2 * (this->_sizeVec + 1)];
        for(size_t i {}; i < this->_sizeVec; ++i)
            this->collection[i] = tempCollection[i];
        delete [] tempCollection;
        this->collection[this->_sizeVec] = val;
        ++this->_sizeVec;
        this->_capacity = 2 * this->_sizeVec;
        for(size_t i {this->_sizeVec}; i < this->_capacity; ++i)
            this->collection[i] = type {};
    }
}

//add rvalue elements to the end
template<typename type> void MyTemplateVec<type>::push_back(type &&val)
{
    if(this->_sizeVec + 1 < this->_capacity)
    {
        this->collection[this->_sizeVec] = std::move(val);
        ++this->_sizeVec;
    } else {
        type *tempCollection {this->collection};
        this->collection = new type[2 * (this->_sizeVec + 1)];
        for(size_t i {}; i < this->_sizeVec; ++i)
            this->collection[i] = tempCollection[i];
        delete [] tempCollection;
        this->collection[this->_sizeVec] = std::move(val);
        ++this->_sizeVec;
        this->_capacity = 2 * this->_sizeVec;
        for(size_t i {this->_sizeVec}; i < this->_capacity; ++i)
            this->collection[i] = type {};
    }
}

//remove last element and return
template <typename type> type MyTemplateVec<type>::pop_back()
{
    if(_sizeVec == 0)
        throw EmptyVectorException {};
    
    type temp {this->collection[_sizeVec - 1]};
    this->collection[_sizeVec - 1] = type {};
    --this->_sizeVec;
    
    if(3 * this->_sizeVec + 1 < this->_capacity)
    {
        type *tempCollection {this->collection};
        this->collection = new type [2 * this->_sizeVec];
        for(size_t i {}; i != 2 * this->_sizeVec; ++i)
        {
            if(i != this->_sizeVec)
            {
                this->collection[i] = tempCollection[i];
                continue;
            }
            this->collection[i] = type {};
        }
        this->_capacity = 2 * _sizeVec;
        delete [] tempCollection;
    }
    return temp;
}

//swaps 2 vectors each other with the same data type
template <typename type> void MyTemplateVec<type>::swap(MyTemplateVec<type> &rhs)
{
    MyTemplateVec<type> temp {std::move(*this)};
    *this = std::move(rhs);
    rhs = std::move(temp);
    // size_t tmpSize {this->_sizeVec}, tmpCap {this->_capacity};
    // ptr<type> tmpCollection {this->collection};
    // this->collection = rhs.collection;
    // this->_capacity = rhs._capacity;
    // this->_sizeVec = rhs._sizeVec;
    // rhs.collection = tmpCollection;
    // rhs._capacity = tmpCap;
    // rhs._sizeVec = tmpSize;  
}

//swaps vector elements' indexes
template <typename type> void MyTemplateVec<type>::swapElements(size_t index1, size_t index2)
{
    if(index1 == index2)
        return;
    type temp {std::move((*this)[index1])};;
    (*this)[index1] = std::move((*this)[index2]);
    (*this)[index2] = std::move(temp);
}

//print element at the given rank
template <typename type> void MyTemplateVec<type>::print(size_t rank) const
{
    if(rank >= _sizeVec)
        throw RankOutOfBoundsException {};
    if(this->_sizeVec == 0){
        std::cerr << "Vector contains no data" << std::endl;
        return;
    }
    std::cout << "[" << this->collection[rank] << "]";
}

//read element into given ostream
template <typename type> std::ostream &MyTemplateVec<type>::print(std::ostream &out, size_t rank) const
{
    if(rank >= _sizeVec)
        throw RankOutOfBoundsException {};
    if(this->_sizeVec == 0){
        std::cerr << "Vector contains no data" << std::endl;
        return out;
    }
    out << "[" << this->collection[rank] << "]";
    return out;
}