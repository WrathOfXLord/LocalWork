#include <iostream>

class Test {
private:
    int data;
public:
    Test(int data = 0) : data {data} { std::cout << "\tTest Constructor" << std::endl; }
    int getData() const { return data; }
    ~Test() { std::cout << "\tTest Destructor" << std::endl; }
};

