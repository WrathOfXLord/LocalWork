#include <iostream>
#include <ios> //used to get stream size
#include <limits> //used to get numeric limits

using std::cout;
using std::cin;
using std::endl;
using std::streamsize;
using std::numeric_limits;

int main()
{
    cout << "Hey There " << endl;
    cout << "\nEnter your inputs: ";
    int x {0}, y {0};
    cin >> x;
    //std::fflush(stdin);
    //fflush(stdin); //might be undefined, be careful while using
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore for clearing buffer, "numeric_limits<streamsize>::max()"" is for how many chars will be ignored
    cout << endl << "Please Enter next input: ";          //until we see new line character
    cin >> y;
    cout << "Your inputs were " << x << " and " << y << endl;



    return 0;
}