#include "Derived.hpp"

using namespace std;


int main()
{
    cout << "============================================================" << endl;
    Base base1;
    cout << "============================================================" << endl;
    Base base2(100);
    cout << "============================================================" << endl;
    Base base3 {base2};
    cout << "============================================================" << endl;
    base1 = base3;
    cout << "============================================================" << endl;
    base2.printValues();
    cout << "============================================================" << endl;
    Derived derived1;
    cout << "============================================================" << endl;
    //both the base and the derived class has the same named member function so compiler chooses derived one as default
    derived1.printValues(); //using derived class member function implicitly 
    //to be more explicit use that : derived1.Derived::printValues();
    //to call base member fuction do the following way:
    derived1.Base::printValues();   //this one calls base member function
    cout << "============================================================" << endl;
    Derived derived2(100);
    cout << "============================================================" << endl;
    derived2.Base::printValues();
    cout << "============================================================" << endl;
    derived2.printValues();
    cout << "============================================================" << endl;
    Derived derived3 {derived2};
    cout << "============================================================" << endl;
    derived1 = derived3;
    cout << "============================================================" << endl;
    
    return 0;
}