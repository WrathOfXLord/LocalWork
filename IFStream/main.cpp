#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string input;
    ifstream readTxt {"text.txt", std::ios::in};
    if(!readTxt.is_open())
    {
        cerr << "file could not be opened" << endl;
        return -1;
    }
    
    cout << "----------------------------------------" << endl;
    cout << "using getline\n\n" << flush;

    //this method only works in windows it doesn't return true in linux not reliable
    // while(!readTxt.eof())   
    // {
    //     getline(readTxt, input);
    //     cout << input << endl;
    // }

    //use this one
    // while(readTxt >> input)
    // {
    //     cout << input << endl;
    // }

    //or this one
    while(getline(readTxt, input))
        cout << input << endl;

    readTxt.seekg(0);   //resets the state of ifstream to beginning
    cout << "----------------------------------------" << endl;
    cout << "using getc\n\n" << flush;

    char reader {};
    while(readTxt.get(reader))
    {
        cout << reader;
    }
    
    readTxt.close();
    cout << "\nprogram is done" << endl;

    return 0;
}