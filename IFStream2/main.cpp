#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char *input {new char [250] {0}};
    ifstream readTxt {"text.txt", std::ifstream::in};
    if(!readTxt.is_open())
    {
        cerr << "file could not be opened" << endl;
        return -1;
    }
    
    cout << "----------------------------------------" << endl;
    cout << "using getline\n\n" << flush;

    while(!readTxt.eof())
    {
        readTxt.getline(input, 249);
        cout << input << endl;
    }

    delete [] input;

    readTxt.seekg(0);   //resets the state of ifstream to beginning
    cout << "----------------------------------------" << endl;
    cout << "using getc\n\n" << flush;

    input = new char [256] {0};
    for(size_t i {0}; readTxt.get(input[i]); ++i)
    {
        cout << input[i];
    }

    delete [] input;
    
    readTxt.close();
    cout << "\nprogram is done" << endl;

    return 0;
}