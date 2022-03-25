#include <iostream>
#include <string>

void print() 
{ 
    std::cout << "I am empty function and "
            "I am called at last.\n" ; 
} 

template <typename T, typename... Types> 
void print(T var1, Types &&...var2) 
{ 
    std::cout << var1 << ' '; 
    print(var2...) ; 
} 

int main()
{
    int x {0}, y {2}, z {3};
    print(x, y, z, z, z);

    return 0;
}


