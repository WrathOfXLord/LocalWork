#ifndef _TESTCLASS_HPP_
#define _TESTCLASS_HPP_
#include <ostream>

class TestClass {
private:
    int val;
public:
    TestClass(int val = 0) : val {val} {}
    int getVal() const { return val; }
    void setVal(int val) { this->val = val; }

    TestClass operator+(const TestClass &rhs) const { return TestClass(this->val + rhs.val); }
    TestClass &operator+=(const TestClass &rhs) { this-> val += rhs.val; return *this; }

};

std::ostream &operator<<(std::ostream &out, const TestClass &rhs) {
    out << rhs.getVal();
    return out;
}
#endif