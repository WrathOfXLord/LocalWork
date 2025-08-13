#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values(3);
    int *valuesData {values.data()};

    for(int index{}, size {static_cast<int>(values.size())}; index < size; ++index) {
        valuesData[index] = index + 3;
    }
    
    std::cout << "vector size: " << values.size() << ", capacity: " << values.capacity() << "\n"
              << "--Elements-- \n"; 
    
    for(const auto &val:values) {
        std::cout << "Element: " << val << "\n";
    }

    return EXIT_SUCCESS;
}