#include <iostream>

using std::cout;
using std::endl;

void func_a();
void func_b();
void func_c();

int main()
{
    cout << "main is now executing" << endl;
    func_a();
    cout << "main is now finishing" << endl;
    return 0;
}

void func_a()
{
    cout << "func_a is now executing" << endl;
    func_b();
    cout << "func_a is now finishing" << endl;
}

void func_b()
{
    cout << "func_b is now executing" << endl;
    try {
        func_c();

    } catch(std::string &exception) {
        std::cerr << exception << " caught by catch block" << endl;
    }
    
    cout << "func_b is now finishing" << endl;
}

void func_c()
{
    cout << "func_c is now executing" << endl;
    throw std::string {"exception"};
    cout << "func_c is now finishing" << endl;
}