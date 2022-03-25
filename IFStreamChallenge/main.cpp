#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Student.hpp"
#include "Students.hpp"
#include "ReadFile.hpp"



using namespace std;

int main()
{
    Students collection;
    
    try { 
        ReadFile studentFile {"answer.txt", collection}; 
    } catch(FileIsNotOpenedException &ex) {
        std::cerr << ex.what() << std::endl;
    } 

    cout << collection << endl;  

    return 0;
}
