// Dynamic Memory Management Test Field

#include <iostream>

using namespace std;

int main()
{
    int *ptr {new int{3}};

    cout << "ptr is now : " << *ptr << endl;

    delete ptr;
    ptr = 0;    // 0 equals to nullptr

    using my_type = long long;  //using keyword is a better way to declare aliases. using > typedef
    // equivalent of using keyword with typedef is "typedef long long my_type;"
    cout << "size of my_type (long long) is : " << sizeof(my_type) << endl;

    my_type *l_ptr {new my_type[12] {2,3,4}}; //we can use uniform initialization for both allocating memory and initial value
    //first three are initialized to its own value, others are initialized to zero.

    //test field on

    //test field off

    for(auto i {0}; i < 12; ++i)
        cout << "element " << i << " is : " << l_ptr[i] << endl;  // l_ptr[i] equals to *(l_ptr + i), both do the same job

    delete [] l_ptr;
    l_ptr = 0;

    return 0;
}