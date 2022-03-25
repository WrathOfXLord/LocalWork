#include <iostream>
#include <string>
#include <vector>
#include <functional>

class Printable {
public:
    void print() const;
    std::string getName() const { std::string s {"empty"};  return s; }
    void printTest(std::string &ref) const { std::cout << " " << ref << " "; }
    template<typename type, typename ...types> void print(type &arg, types &...args) const;
    template<typename type, typename ...types> void print(type &&arg, types &&...args) const;
};

void Printable::print() const
{
    std::cout << "\nempty print called because no args left in other one\n";
}

template<typename type, typename ...types> void Printable::print(type &&arg, types &&...args) const
{
    std::cout << arg;
    print(std::forward<types>(args)...);
}

int main()
{
    std::string str {"hey there "};
    char cArr[] {"hey "};
    Printable p1 {};
    p1.print("hey");
    std::string testStr {p1.getName()};
    return 0;
}