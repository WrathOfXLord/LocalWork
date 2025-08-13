#pragma once

#include <vector>
#include <string>

enum class Type {
    None = 0,
    Int,
    Float,
    Bool
};

struct MyPoint {
    std::string name;
    Type type;
};

class MyTestClass {
private:
    std::vector<MyPoint> points;
public:
    MyTestClass(const std::initializer_list<MyPoint> &points);
    std::vector<MyPoint> &getPoints() { return points; }
    MyPoint &operator[](size_t index) { return points[index]; }
};