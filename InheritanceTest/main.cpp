#include "DerivedAsPrivate.hpp"
#include "DerivedAsProtected.hpp"
#include "DerivedAsPublic.hpp"

using namespace std;

int main()
{
    //BASE 
    Base newBase;
    cout << "==============================================================" << endl;
    cout << "freeForAll public member is : " << newBase.freeForAll << endl;
    cout << "==============================================================" << endl;
    cout << "getPublicAsPublic was called : " << newBase.getPublicAsPublic() << endl;
    cout << "==============================================================" << endl;
    cout << "getPrivateAsPublic was called : " << newBase.getPrivateAsPublic() << endl;
    cout << "==============================================================" << endl;
    cout << "getProtectedAsPublic was called : " << newBase.getProtectedAsPublic() << endl;
    cout << "==============================================================" << endl;
    

    //DERIVED PUBLIC SIDE
    cout << endl;
    cout << endl;
    DerivedAsPublic newPublic;
    cout << "==============================================================" << endl;
    cout << "Public Derived freeForAll public member is : " << newPublic.freeForAll << endl;
    cout << "==============================================================" << endl;
    cout << "Public Derived getPublicAsPublic was called : " << newPublic.getPublicAsPublic() << endl;
    cout << "==============================================================" << endl;
    cout << "Public Derived getPrivateAsPublic was called : " << newPublic.getPrivateAsPublic() << endl;
    cout << "==============================================================" << endl;
    cout << "Public Derived getProtectedAsPublic was called : " << newPublic.getProtectedAsPublic() << endl;
    cout << "==============================================================" << endl;
    cout << "Public Derived getNewAsPublic was called : " << newPublic.getNewAsPublic() << endl;
    cout << "==============================================================" << endl;


    //DERIVED PROTECTED SIDE
    cout << endl;
    cout << endl;
    DerivedAsProtected newProtected;
    //following inherited member methods cannot be accessed outside of derived class becaused we derived as protected so
    //all data and member methods came from base class (except private ones) are now protected from outside
    //we need to implement public member methods for derived class if we want to access those from the outside
    //private members are still private and also cannot be accessed from derived class 
    //so we need to use base class' public or protected getter functions to implement public getter functions for derived class 
    //and access base class' private members from outside
    // cout << "==============================================================" << endl;
    // cout << "Public Derived freeForAll public member is : " << newProtected.freeForAll << endl;
    // cout << "==============================================================" << endl;
    // cout << "Public Derived getPublicAsPublic was called : " << newProtected.getPublicAsPublic() << endl;
    // cout << "==============================================================" << endl;
    // cout << "Public Derived getPrivateAsPublic was called : " << newProtected.getPrivateAsPublic() << endl;
    // cout << "==============================================================" << endl;
    // cout << "Public Derived getProtectedAsPublic was called : " << newProtected.getProtectedAsPublic() << endl;
    // cout << "==============================================================" << endl;
    cout << "==============================================================" << endl;
    cout << "Protected Derived getNewAsProtected was called : " << newProtected.getNewAsProtected() << endl;
    cout << "==============================================================" << endl;


    //DERIVED PRIVATE SIDE
    cout << endl;
    cout << endl;
    DerivedAsPrivate newPrivate;
    //following inherited member methods cannot be accessed outside of derived class becaused we derived as private
    //so we need to implement public getter member method to access from outside
    //private data members came from base class cannot be accessed even in derived class, 
    //if base class has any public or protected getter member methods we can use them to access base class' private data from derived class
    //to access from outside we need to implement public member getter method for derived class
    // cout << "==============================================================" << endl;
    // cout << "Public Derived freeForAll public member is : " << newPrivate.freeForAll << endl;
    // cout << "==============================================================" << endl;
    // cout << "Public Derived getPublicAsPublic was called : " << newPrivate.getPublicAsPublic() << endl;
    // cout << "==============================================================" << endl;
    // cout << "Public Derived getPrivateAsPublic was called : " << newPrivate.getPrivateAsPublic() << endl;
    // cout << "==============================================================" << endl;
    // cout << "Public Derived getProtectedAsPublic was called : " << newPrivate.getProtectedAsPublic() << endl;
    // cout << "==============================================================" << endl;
    // cout << "Public Derived getNewAsPublic was called : " << newPrivate.getNewAsPublic() << endl;
    // cout << "==============================================================" << endl;

    return 0;
}