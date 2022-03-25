#pragma once
#include <iostream>
#include <string>
#include <cstdlib>

class Number {
private:
    double var;
public:
    Number(const double varName = {} ) : var {varName} {}
    auto root(size_t root, double val);
    auto raise(double val, double exp);
};

auto Number::root(size_t root, double val)
{
    if(root == 0)
        throw "Root Cannot Be Zero";
    if(root % 2 == 0 && val < 0)
        throw "Negative Value Inside Root";
    
    auto equation = [root, val](double x) -> double {
        double mltply {x};
        for(size_t i {1}; i < root; ++i) {
            mltply *=x;
        }
        return mltply - val;
    };

    auto derive = [&equation, &val](double x) -> long double {
        constexpr const long double delta {1.0e-6};
        long double xl {val - delta};
        long double xu {val + delta};
        return (equation(xu) - equation(xl)) / (xu - xl);
    };

    long double xPrev {1};
    long double xNext {xPrev - equation(xPrev) / derive(equation(xPrev))};
    long double E {((xNext - xPrev)/xPrev < 0)?(-(xNext - xPrev)/xPrev):((xNext - xPrev)/xPrev)};
    while(E >= 1.0e-15) {
        xPrev = xNext;
        xNext = xPrev - equation(xPrev) / derive(equation(xPrev));
        E = ((xNext - xPrev)/xPrev < 0)?(-(xNext - xPrev)/xPrev):((xNext - xPrev)/xPrev);
    }
    
    return xNext;
}

long double raise(double val, double exp)
{
    
    if(val == 0)
        return 0;
    if(exp == 0) {
        if(val < 0)
            return -1;
        return 1;
    }

    double result {};
    if(val < 0) {
        if(val > -1) {

        } else {
            
        }
    }

}