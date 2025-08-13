#include <iostream>
#include <string>
#include <iomanip>

//class definition
class Movable{
    friend std::ostream &operator<<(std::ostream &os, Movable &rhs);
private:
    size_t sz;
    int *valHolder;
    size_t id;
    static size_t count;
public:
    explicit Movable(size_t val) : sz{val}, valHolder{new int [sz] {}}, id {++count} {}
    Movable(const Movable &source);
    Movable(Movable &&source);
    ~Movable() { 
        std::cout << "Destructor called for object: " << std::setw(8) << std::setfill('0') << this->id << std::setfill(' ') << "\n";
        delete [] valHolder; 
    }

    // returns a pointer for this address. copy can't change the original address
    int *data() { return this->valHolder; }
    int &operator[](size_t index) { return this->valHolder[index]; }
    int &operator*() const { return *(this->valHolder); }
    int size() const { return sz; }
    void set(size_t index, int val) { (*this)[index] = val; }
    Movable &operator=(const Movable &rhs);
    Movable &operator=(Movable &&rhs);
    bool operator==(const Movable &rhs) const { return this->valHolder == rhs.valHolder; }
};

void *operator new(size_t size) {
    std::cout << "Allocated " << size << " bytes of memory.\n";
    return std::malloc(size);
}

void *operator new[](size_t size) {
    std::cout << "Allocated " << size << " bytes of memory.\n";
    return std::malloc(size);
}

void operator delete[](void *memory, size_t size) {
    std::cout << "Released " << size << " bytes of memory.\n";
    std::free(memory);
}

void operator delete[](void *memory) {
    std::cout << "Released memory.\n";
    std::free(memory);
}

// creating fake move func
template <typename T>
// typename keyword required before std::remove_reference<T>::type because ::type is a template argument
// std::remove_reference_t equals to typename std::remove_reference<T>::type
typename std::remove_reference<T>::type &&move2(T &&obj) {
    return static_cast<typename std::remove_reference<T>::type &&>(obj);
}

//main
int main()
{
    // Movable m1 {5};
    // m1.set(2, 4);
    // Movable m2 {4};
    // m2.set(1, 5);
    // std::cout << "m1 " << m1 << " m2 " << m2 << "\n";
    // m1 = std::move(m2);
    // std::cout << "m1 " << m1 << " m2 " << m2 << "\n";

    Movable m1 {64};

    // move test
    std::cout << "moving into new object\n";

    // Movable m2 {std::move(m1)};
    Movable m2 {move2(m1)};
    std::cout << "first object moved into new one \n";
    m2[0] = 1;

    if(m1.data() == nullptr) {
        std::cout << "Works as intended\n";
    } else {
        std::cout << "val: " << *m2.data() << "\n";
    }
    std::cout << "value: " << *m2.data() << "\n";
    m2[0] = 3;
    std::cout << "value: " << *m2.data() << "\n";
    m2[0] = 0;
    std::cout << "value: " << *m2.data() << "\n";

    return 0;
}

//friend function
std::ostream &operator<<(std::ostream &os, Movable &rhs) 
{
    std::cout << "[";
    for(size_t i {}; i != rhs.sz; ++i) {
        std::cout << rhs[i];
        if(i + 1 != rhs.sz)
            std::cout << ", ";
    }
    std::cout << "]";
    return os;
}

//class member definitions
size_t Movable::count = 0;

Movable::Movable(const Movable &source)
: sz {source.sz}, valHolder {new int[sz]}, id {++count}
{
    for(size_t i {}; i != sz; ++i) 
        valHolder[i] = source.valHolder[i];
}

Movable::Movable(Movable &&source)
: sz {source.sz}, valHolder {source.valHolder}, id {++count}
{
    source.valHolder = nullptr;
    source.sz = 0;
}

Movable &Movable::operator=(const Movable &rhs)
{
    if(this == &rhs)
        return *this;
    delete [] this->valHolder;
    this->sz = rhs.sz;
    this->valHolder = new int[this->sz];
    for(size_t i {}; i != this->sz; ++i)
        this->valHolder[i] = rhs.valHolder[i];
    return *this;
}

Movable &Movable::operator=(Movable &&rhs)
{
    delete [] this->valHolder;
    this->valHolder = rhs.valHolder;
    this->sz = rhs.sz;
    rhs.valHolder = nullptr;
    rhs.sz = 0;
    return *this;
}