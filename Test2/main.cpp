#include <iostream>
#include <vector>
#include <functional>
#include <typeinfo>
#include <cstring>
#include <memory>
#include <optional>
#include <limits>

#include "../BLUEPRINTS/timer_blueprint/TimeCounter.hpp"


std::function<int(int val)> closureTest(int num)
{
  return [num](int val)
  {
    return num * val;
  };
};

auto closureWithLambda(int num)
{
  return [num](int val) -> int
  {
    return num * val;
  };
}

template <typename any>
std::ostream &refTest(std::ostream &out, any &ref)
{
  std::cout << "type of var: " << typeid(ref).name() << "\n";
  if (std::strcmp(typeid(ref).name(), "int") == 0)
  {
    std::cout << "yes type of var is int\n";
  }
  out << ref << " ";
  return out;
}

class Type1
{
};


void *operator new(std::size_t size) {
  std::cout << "Allocating " << size << " bytes of memory\n";
  return std::malloc(size);
}

void *operator new[](std::size_t size) {
  std::cout << "Allocating " << size << " bytes of memory\n";
  return std::malloc(size);
}

// void operator delete(void *memory, std::size_t size){
//   std::cout << "Releasing " << size << " bytes of memory\n";
//   std::free(memory);
// }

// void operator delete[](void *memory, std::size_t size) {
//   std::cout << "Releasing " << size << "bytes of memory\n";
//   std::free(memory);
// }

template <std::floating_point T>
int64_t floor(T val) {
  if(val < 0)
    return static_cast<int64_t>(--val);
  return static_cast<int64_t>(val);
}

template <typename T>
int64_t binSearch(T *arr, int64_t size, T &&value) {
  if(size <= 0) {
    throw std::runtime_error {"Invalid size!"};
  }
  int64_t mid {}, start {0}, end {size - 1};
  while(start <= end) {
    mid = start + (end - start) / 2;
    if(arr[mid] == value) {
      return mid;
    }
    if (arr[mid] > value) {
      end = mid - 1;
    } else {
      start = mid + 1;
    } 
  }
  return -1;
}

template <typename T>
int64_t linSearch(T *arr, int64_t size, T &&value) {
  if(size <= 0) {
    throw std::runtime_error {"Invalid size!"};
  }
  for(int64_t index {}; index < size; ++index) {
    if(arr[index] == value)
      return index;
  }
  return -1;
}

template <typename type, typename Function>
std::optional<type> reducer(const std::vector<type> &container, Function &&callback) {
  std::optional<type> opt {};

  if(!container.size())
    return opt;

  auto item {container.begin()};
  for(auto element {container.begin()}, end {container.end()}; element != end; ++element) {
    if(callback(*element, *item))
      item = element;
  }
  opt = *item;
  return opt;
}

bool max(int val1, int val2) {
  return val1 > val2;
}

class RefTest {
public:
  int dataInt {5};
  char dataChar {'x'};

  RefTest getCopy() { return *this; }
  RefTest &getRef() { return *this; }
};

double abs(double val) {
  if(val > 0)
    return 0 - val;
  return val;
}

int main()
{
  // int arr[5] {3,4,5,6,7};
  // int *ptr {arr};
  // std::cout << "ptr: " << *ptr << "\n";
  // ptr += 2;
  // std::cout << "ptr: " << *ptr << "\n";

  // auto val = closureTest(5);
  // std::cout << "result of closureTest: " << val(12) << "\n";

  // auto val2 = closureWithLambda(5);
  // std::cout << "type of lambda closure: " << typeid(val(2)).name() << "\n";
  // std::cout << "result of lambda closure: " << val2(12) << "\n";

  // int value{5}, &valRef{value};

  // refTest(std::cout, valRef) << "is the value\n";

  // int * ptr {new int[3]};
  // std::cout << "value: " << ptr[0] << "\n";
  // delete[] ptr;

  // int arr[] {3, 4, 5, 6, 7, 26, 44, 77, 98, 111, 232, 634, 3436, 3536};
  // size_t size {sizeof(arr)/sizeof(arr[0])};
  // int index {};
  // TimeCounter t {};
  // // index = binSearch(arr, size, 3536);
  // index = linSearch(arr, size, 3536);
  // t.timedelta();
  // std::cout << index << "\n";
  // std::cout << floor(3.0) << "\n";

  // std::vector<int> values {3, 4, 5, 7, 6, 12, 9, 2};
  // std::optional<int> value {
  //   reducer(values, [](int val1, int val2) {
  //     return val1 < val2;
  //   })
  // };

  // int arr[] {1, 2, 3};
  // std::cout << "address of arr: " << arr << "\n";
  

  // std::cout << value.value() << "\n";

  // int x {std::numeric_limits<int>::max()};
  // x += 1;
  // std::cout << x << "\n";
  
  // std::cout << x << "\n";

  RefTest &&ref {RefTest {}};
  RefTest cpy {ref.getCopy()};
  ref.dataChar = 'A';
  ref.dataInt = 3;
  
  std::cout << "ref values1: " << ref.dataInt << " - " << ref.dataChar << "\n";
  std::cout << "cpy values: " << cpy.dataInt << " - " << cpy.dataChar << "\n";
  ref.getRef().dataInt = 7;
  std::cout << "ref values2: " << ref.dataInt << " - " << ref.dataChar << "\n";
  RefTest &ref3 {ref.getRef()};
  ref3.dataInt = 46;
  std::cout << "ref values3: " << ref.dataInt << " - " << ref.dataChar << "\n";

  double MAX_ERROR {1e-11};
  double x {1e-9}, y {1e-9};

  if(abs(x - y) <= MAX_ERROR) {
    std::cout << "values are equal. value: " << std::fixed << x << std::scientific << " (" << x << ")\n";
  }



  return EXIT_SUCCESS;
}