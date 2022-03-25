#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>

#include <vector>

using std::chrono::time_point;

void *operator new[](std::size_t size) {
    std::cout << "Allocating " << size << " bytes of memory.\n";
    return std::malloc(size);
}

void *operator new(std::size_t size) {
    std::cout << "Allocating " << size << " bytes of memory.\n";
    return std::malloc(size);
}

void operator delete(void *memory, size_t size) {
    std::cout << "Releasing " << size << " bytes of memory\n";
    std::free(memory);
}

void operator delete[](void *memory, size_t size) {
    std::cout << "Releasing " << size << " bytes of memory\n";
    std::free(memory);
}

template<typename type, typename ...types> type *initializeNReturn(types &&...args){
    std::cout << "size: " << sizeof...(args) << "\n";
    return new type[sizeof...(args)] {std::move(args)...}; 
}

template<typename type>
class VariadicTest {
private:
    type *ptr;

public:
    type *data() { return ptr; }

    VariadicTest();

    template<typename ...types>
    VariadicTest(types &&...args);

    VariadicTest(const type &arg) 
    : ptr {new type[2] {arg}} {

    }


    // template<typename ...types>
    // VariadicTest(const types &...args) 
    // : ptr {new type[sizeof...(args)] {args...}} {
    //     std::cout << "size: " << sizeof...(args) << "\n";
    // }

    ~VariadicTest() { delete [] ptr; }
};

template <typename type> 
template<typename ...types>
VariadicTest<type>::VariadicTest(types &&...args)
: ptr {new type[sizeof...(args) + 1] {std::forward<types>(args)...}} {
    std::cout << "size: " << sizeof...(args) << "\n";
}

struct TimeCounter {
    time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<double> duration;
    TimeCounter()
    : start {std::chrono::steady_clock::now()} {}

    ~TimeCounter() {
        end = std::chrono::steady_clock::now();
        duration = end - start;
        std::cout << "Elapsed time: " << duration.count() << " seconds." << "\n";
    }
    
};

int main()
{
    // // constexpr size_t size {5};
    // int *ptr {initializeNReturn<int>(3, 4, 5, 7)};
    // for(size_t i {}; i != 4; ++i) {
    //     std::cout << " " << ptr[i] << " ";
    // }
    // for (size_t i = 0; i < 5; i++)
    // {
    //     for (size_t k = 0; k < 8; k++)
    //     {
    //         /* code */
    //     }
        
    // }
    
    // delete [] ptr;

    const std::string stolenStr {"stolen by v1"};
    VariadicTest<std::string> v1 {stolenStr};
    std::cout << "data: " << v1.data()[0] << "\n";
    std::cout << "stolenStr val: " << stolenStr << " - \n";

    // std::vector<std::string> vector {"hey", std::string {"there"}, std::move(stolenStr)};
    // std::cout << "vec[2]: " << vector[2] << "\n";
    // std::cout << "stolenStr val: " << stolenStr << " - \n";

    return 0;
}