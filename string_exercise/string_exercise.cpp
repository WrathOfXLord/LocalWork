#include <iostream>
#include <string>
using namespace std;

void cpp_strings() {
    
    string unformatted_full_name {"StephenHawking"};
    string first_name{unformatted_full_name, 0, 7};
    string last_name {unformatted_full_name, 7};
    string formatted_full_name {first_name + last_name};

    formatted_full_name.insert(7, " ");
    
    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE YOUR CODE BELOW THIS LINE----
    
    
    
    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    
    cout << "formatted full name is : " << formatted_full_name << endl;
}

int main()
{
    cpp_strings();
    return 0;
}