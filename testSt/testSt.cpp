#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string input {};
    cout << "enter input : " ;
    cin >> input;

    vector <string> sub (3, 0);             //to store divided rgb strings
    vector <unsigned int> decimal(3, 0);    //to store rgb values
    
    for(auto i {0}; i < sub.size(); i++)
    {
        if(i % 2 == 1)  //binary read, reads 0,2,4
            continue;
        sub.at(2 * i) = input.substr(i, i + 1);
    }

    for(auto it {0}; it < decimal.size(); it++)
    {
        decimal.at(it) = stoul(sub.at(it), nullptr, 16);
        cout << decimal.at(it) << " ";
    }
    cout << endl;

   
    
    return 0;
}