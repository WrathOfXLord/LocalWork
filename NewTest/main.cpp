#include <iostream>

using namespace std;

int main()
{
    int *data {new int [1]};
    *data = 25;

    int arr[1] {0};
    cout << arr[0] << endl;
    cout << "data is now : " << *data << endl;
    delete data;
    return 0;
}