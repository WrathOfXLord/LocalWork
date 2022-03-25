#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    string input {};

    cout << "Please enter hex value : ";
    cin.ignore(1, '#');
    cin  >> input;
    
    vector <unsigned int> sub_rgb (3, 0);

    for(auto i {0}; i < sub_rgb.size(); i++)
    {
        sub_rgb.at(i) = stoi(input.substr(2 * i, 2), nullptr, 16);
        cout << sub_rgb.at(i) << " ";
    }

    cout << endl;

    return 0;
}