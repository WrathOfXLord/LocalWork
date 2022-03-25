#include <iostream>
#include <array>
#include <vector>
#include <iomanip>

template <typename type, size_t size1, size_t size2>
std::ostream &operator<<(std::ostream &out, std::array<std::array<type, size1>, size2> &rhs) {
    for(const auto &arr1d:rhs) {
        out << "|";
        for(const auto &e:arr1d) {
            out << std::setw(5) << e << " ";
        }
        out << "   |\n";
    }

    return out;
}

template <typename type>
std::ostream &insertToStream(std::ostream &out, const type *data, size_t size) {
    if(data == nullptr || size == 0)
        return out;
    out << " ";
    for(size_t e {0}; e != size; ++e) {
        out << data[e] << " ";
    }
    return out;
}

template <typename type>
const type &max(const type &first, const type &second) {
    return (first > second)?first:second;
}

template <typename type>
type knapsackRecursion(type *val, type *Wt, type weight, size_t size) {
    if(weight == 0 || size == 0)
        return 0;
    else if(Wt[size - 1] > weight)
        return knapsackRecursion(val, Wt, weight, size - 1);
    else
        return max( val[size - 1] + knapsackRecursion(val, Wt, weight - Wt[size - 1], size - 1),
                    knapsackRecursion(val, Wt, weight, size - 1) );
    
}

template <typename type>
type knapsackDynamic(type *val, type *Wt, type weight, const size_t &size) {
    type storage[size + 1][static_cast<int>(weight) + 1] {};
    for(int x {}; x <= (int)size; ++x) {
        for(int w {}; w <= weight; ++w) {
            if(x == 0 || w == 0)
                storage[x][w] = 0;
            else if(Wt[x - 1] <= w)
                storage[x][w] = max(val[x - 1] + storage[x - 1][w - Wt[x - 1]],
                                    storage[x - 1][w]);
            else
                storage[x][w] = storage[x - 1][w];
        }
    }
    return storage[size][weight];
}

int main() {
    std::array<std::array<int, 3>, 3> myArr {{{2, 4, 5}, {4, 5, 6}, {8, 7, 9}}};

    std::cout << myArr << "\n";

    std::vector<int> weights {  3,  5, 10,  15,  20,  25,  30,  40};
    std::array values      {192, 35, 60, 100, 110,  20, 160, 120};
    int val {};
    for(const auto &e:values) {
        val += e;
    }
    std::cout << "sum: " << val << "\n";

    // std::vector<int> weights  {10,  20,  30};
    // std::array<int, 3> values       {60, 100, 120};

    // for(size_t element {}; element != myArr.size(); ++element) {
    //     insertToStream(std::cout, myArr.data()[element].data(), 3) << "\n";
    // }

    // std::cout << "\n";
    // insertToStream(std::cout, weights.data(), myVec.size());

    // const char *arr[] {"hey there", "world", "testing"};
    // std::cout << "\n";
    // insertToStream(std::cout, arr, 3);
    // std::cout << "\nsize of arr[2]: " << sizeof(arr) << "\n";
    int value {knapsackRecursion(values.data(), weights.data(), 50, values.size())};
    std::cout << "knapsack value with recursion: " << value << "\n";
    int value2 {knapsackDynamic(values.data(), weights.data(), 50, values.size())};
    std::cout << "knapsack value with DP: " << value2 << "\n";
    

    return EXIT_SUCCESS;
}