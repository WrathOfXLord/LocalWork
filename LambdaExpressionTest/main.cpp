#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;




int main()
{

    int x {3}, y {2};

    auto fy = [&x, y](void) mutable -> void { 
        x = 10, y = 3;
        cout << "x is : " << x << "\n";
        cout << "y is : " << y << "\n";
    };
    {
        //inside capture:
        //[&var], captures "var" variable by reference
        //[var], captures "var" variable by value
        //[&], captures all variables by references
        //[=], captures all variables by value
        //[&, var], captures all variables by references, but "var" by value
        //[=, &var], captures all variables by value but "var" by reference

        //a lambda: [capture] - (arguments) - specifier - return type(optional, you can return inside lambda body)
        auto f = [=](void) mutable -> void { 
            x = 10, y = 3;
            cout << "x is : " << x << "\n";
            cout << "y is : " << y << "\n\n";
        };
        f();
        cout << "\nx is : " << x << "\n";
        cout << "y is : " << y << "\n";
    }
    fy();
    cout << "\nx is : " << x << "\n";
    cout << "y is : " << y << "\n";

    return 0;
}