#include "DeepCopy.hpp"

//Constructors

Deep::Deep(size_t size, int initialVal)
: size{size}, data{new int [size]}
{
    for(size_t i {0}; i < size; ++i){
        data[i] = initialVal;
    }
    cout << endl;
}

Deep::Deep(const Deep &source)
: size {source.size}, data {new int[source.size]}
{
    for(size_t i {0}; i < source.size; ++i)
        data[i] = source.data[i]; 
}

//or we could have simply used delegating constructor for copy constructor if we knew initial value for each element of data.

// Deep::Deep(const Deep &source)
// : Deep {source.size, XX} //XX stands for initial value for each element
// {

// }

Deep::~Deep()
{
    delete [] this->data;
    this->data = nullptr;
}

//returns the starting address of taken memory from the heap
int *Deep::getData()
{
    return this->data;
}

void Deep::setData(int val)
{
    for(size_t i {0}; i < this->size; ++i)
        this->data[i] = val;
}

size_t Deep::getSize()
{
    return this->size;
}

void printWithCopy(Deep source)
{
    cout << "Data is : [ ";
    for(size_t i {0}; i < source.getSize(); ++i)
        cout << source.getData()[i] << " ";
    cout << "]" << endl;
}

void printWithReference(Deep &source)
{
    cout << "Data is : [ ";
    for(size_t i {0}; i < source.getSize(); ++i)
    cout << source.getData()[i] << " ";
    cout << "]" << endl;
}