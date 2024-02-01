#pragma once

#include "MyTemplateVec.hpp"
#include <iostream>
#include <vector>

class Test {
    inline static int id = 1;
    private:
    int mId;
    friend std::ostream &operator<<(std::ostream &os, const Test &rhs) {
        return os << rhs.mId;
    }
public:
    Test(): mId {id} {
        std::cout << "default (" << id << ")\n";
        ++id;
    }

    Test(const Test &): mId {id} {
        std::cout << "copy constructor (" << id << ")\n";
        ++id;
    }

    Test(Test &&): mId {id} {
        std::cout << "move constructor (" << id << ")\n";
        ++id;
    }

    Test &operator=([[maybe_unused]]const Test &rhs) {
        std::cout << "copy assignment\n";
        return *this;
    }
    Test &operator=([[maybe_unused]]Test &&rhs) {
        std::cout << "move assignment\n";
        return *this;
    }

    static inline void resetId() { Test::id = 1; }
};

void run() {
    Test t1 {};
    Test t2 {t1};
    Test t3 {};
    Test t4 {};
    Test::resetId();
    std::cout << "------------\n";

    MyTemplateVec<Test> tList (t3, t2, t1, Test {});
    std::cout << "------------\n";
    Test::resetId();
    MyTemplateVec<Test> vList {};
    vList.reserve(10);
    std::cout << "list: " << tList << "\n";

    std::cout << "------------\n";
}