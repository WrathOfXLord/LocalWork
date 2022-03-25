#include <iostream>
#include <vector>
#include <functional>
#include <typeinfo>
#include <cstring>
#include <memory>

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

void operator delete(void *memory, std::size_t size){
  std::cout << "Releasing " << size << " bytes of memory\n";
  std::free(memory);
}

void operator delete[](void *memory, std::size_t size) {
  std::cout << "Releasing " << size << "bytes of memory\n";
  std::free(memory);
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

  int * ptr {new int[3]};
  std::cout << "value: " << ptr[0] << "\n";
  delete[] ptr;
}