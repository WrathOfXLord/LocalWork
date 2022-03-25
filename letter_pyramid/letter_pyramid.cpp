#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Enter a string for letter pyramid : ";

    string input;
    cin >> input;

    const size_t input_size {input.size()};

    for(size_t i {0}; i < input_size; i++)
    {
        for(size_t j {input_size - 1}; j > i; --j)
        {
            cout << " ";
        }

        size_t k {0};
        
        for(auto j {input_size - (i + 1)}; j < input_size; ++j)
        {
            cout << input.at(k);
            ++k;
        }


        for(auto j {input_size - i}; j < input_size ; ++j)
        {
            cout << input.at(k - 2);
            --k;
        }

        cout << endl;
    } 

    return 0;
}