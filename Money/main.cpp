#include "Money.hpp"
#include <iomanip>

using namespace std;

int main()
{
    Money m1 {5};
    Money m2 {2};
    Money m3 ;
    Money m4 {1, "USD"};
    Money m5 {1, "EUR"};
    m3 = m1 + m2;
    cout << "money of m3 is : " << m3.getMoney() << endl;
    cout << "m3 < m2 is : " << std::boolalpha << (m3 < m2) << endl;
    cout << "m2 < m4 is : " << std::boolalpha << (m2 < m4) << endl;
    cout << "m5 < m4 is : " << std::boolalpha << (m5 < m4) << endl;
    return 0;
}