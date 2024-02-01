#include <iostream>
#include <string>
#include <type_traits>

//
template<typename T> struct rem_ref { using type = T; };

//
template<typename T> struct rem_ref <T&> { using type = T; };

//
template<typename T> struct rem_ref <T&&> { using type = T; };

template <typename T>
rem_ref<T>::type &&setAsMovable(T &&arg) {
    return static_cast<rem_ref<T>::type &&>(arg);
}



int main() {

    std::string str1 {"hello"}, str2 {};
    std::cout << "before move str1: " << str1 << ", str2: " << str2 << "\n";

    str2 = setAsMovable(str1);
    std::cout << "after move str1: " << str1 << ", str2: " << str2 << "\n";


    bool areSame {std::is_same_v<rem_ref<int&>::type, int>};

    std::cout << "are the same: " << areSame << "\n";

    return 0;
}