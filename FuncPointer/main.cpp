#include <iostream>

using namespace std;

double multiplyWith3(double value)
{
    return value * 3;
}

double givenValue(double (*fx)(double), double val)
{
    return fx(val);
}

int main()
{
    double (*f)(double);
    f = multiplyWith3;
    

    cout << "result with func ptr: " << f(3) << endl;
    cout << "result with func: " << givenValue(multiplyWith3, 2) << endl;
    cout << "result with func: " << givenValue(f, 4) << endl;
    return 0;
}