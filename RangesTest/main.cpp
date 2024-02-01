#include <iostream>
#include <ranges>
#include <vector>
#include <functional>

class MyClass {
    friend std::ostream &operator<<(std::ostream &out, const MyClass &obj) {
        return out << obj.value;
    }
public:
    int value;

    MyClass(int val) : value(val) {}
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &list) {
    if(list.size() == 0)
        return out;
    out << "|";
    for(const T& val: list) {
        out << val.value << "|";
    }
    return out;
}

// template <typename V, typename F>
// concept Invocable = requires (V &view, F func) {
//     std::function<F> funcWrapper {func};
// };

// template <typename T, Invocable Func>
// std::ostream &operator<<(std::ostream &out, const std::ranges::transform_view<T, Func> &view) {
//     auto begin {std::ranges::begin(view)};
//     auto end {std::ranges::end(view)};
//     if(begin == end)
//         return out;
//     out << "|";
//     for(const auto& val: view) {
//         out << val << "|";
//     }
//     return out;
// }

void testfun(){
    std::cout << "test\n";
}


int main()
{
    std::vector<MyClass> objects {1, 2, 3};

    // Her MyClass nesnesinin değerini iki katına çıkaran map
    // [[maybe_unused]]

    auto testFun = [](MyClass& obj) -> MyClass& {
        // Burada obj.value değeri doğrudan değiştirilir.
        obj.value *= 2;
        return obj;  // Referans olarak geri döndürülür.
    };

    auto square_view = std::views::transform(objects, [](MyClass& obj) -> MyClass& {
        // Burada obj.value değeri doğrudan değiştirilir.
        obj.value *= 2;
        return obj;  // Referans olarak geri döndürülür.
    });

    // std::vector<int> transformed_values(square_view.begin(), square_view.end());

    // // Dönüştürülmüş değerleri topla
    // auto sum = std::ranges::reduce(transformed_values, std::plus<int>());

    // std::cout << square_view << "\n";

    return EXIT_SUCCESS;
}