#include <iostream>
#include <string>
#include <algorithm>

template <typename type> 
inline type compare(const type &val1, const type &val2);


int main()
{

    std::string x {"hello"}, y {"hey"};
    std::cout << "comparison result of compare(x, y) : " << compare(x, y) << std::endl;

    return 0;
}


template <typename type> type compare(const type &val1, const type &val2) //typename and class are equivalent each other inside template
{
    return (val1 > val2)? val1 : val2;
}
