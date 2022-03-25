#include "Test.hpp"
#include <memory>
#include <vector>
#include <cstring>



// Function prototypes
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
void fill(std::vector<std::shared_ptr<Test>> &vec, int num);
void display(const std::vector<std::shared_ptr<Test>> &vec);


int main() {
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    std::cout << "How many data points do you want to enter: ";
    int num;
    std::cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
    return 0;
}


std::unique_ptr<std::vector<std::shared_ptr<Test>>> make()  //or simply auto make() {...}
{
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void fill(std::vector<std::shared_ptr<Test>> &vec, int num)
{
    int input {};
    vec.resize(num);
    for(size_t i {0}; i < vec.size(); ++i)
    {
        std::cout << "Enter data point [" << i + 1 << "]: ";
        std::cin >> input;
        vec.at(i) = std::make_shared<Test>(std::move(Test {input}));
    }
}

void display(const std::vector<std::shared_ptr<Test>> &vec)
{
    for(size_t i {0}; i < vec.size(); ++i)
    {
        std::cout << "Test Element [" << i + 1 << "] = " << vec.at(i)->getData() << std::endl;
    }
}

