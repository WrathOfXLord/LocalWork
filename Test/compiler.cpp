#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <locale>
#include <iterator>
#include <cstring>
#include <list>
#include <cmath>
#include <set>
#include "TimeCounter.hpp"


// class xyz
// {
// private:
//   static int x;

// public:
//   void setVal(int x) { xyz::x = x; }
//   static int getVal() { return xyz::x; }
// };

// int xyz::x = 0;

// std::string &getString()
// {
//   static std::string testStr{"i am a string"};

//   return testStr;
// }

// void x(int value, int expectedVal)
// {
//   value = expectedVal;
//   std::cout << "value inside the function: " << value << "\n";
// }

template <typename type>
void swapByRef(type &first, type &second) {
  type tmp {std::move(first)};
  first = std::move(second);
  second = std::move(tmp);
}

template <typename type>
void swapByPtr(type *first, type *second) {
  type ptr {*first};
  *first = *second;
  *second = ptr;
}

int main(int argc, char** argv)
{
  //   int x = -0xFF;
  //   int y = 0xFF;
  //   std::cout << std::setw(5) << y << " 0x" << std::hex << std::uppercase << std::setw(8) << std::setfill('0') << y << "\n";
  //   std::cout << std::setfill(' ');
  //   std::cout << std::setw(5) << std::dec << x << " 0x" << std::hex << std::uppercase << std::setw(8) << std::setfill('0') << x << "\n";
  //   std::cout << std::setfill(' ');
  //   std::bitset<32> x1 = x;
  //   std::bitset<32> y1 = y;
  //   std::cout << std::dec << std::setw(5) << y << " " << y1.to_string() << "\n";
  //   std::cout << std::setw(6) << " " << std::setw(32) << std::setfill('|') << "|" << std::setfill(' ') << "\n";
  //   std::cout << std::dec << std::setw(5) << x << " " << x1.to_string() << "\n";  //do not use to_long or llong, it acts as unsigned int
  //   double z {-9.87654e-1};  //0.987654
  //   std::cout << std::fixed << "z is: " << z << "\n";

  //   std::stringstream ss;
  //   std::string test;
  //   ss << "0x" << std::hex << std::uppercase << std::setw(8) << std::setfill('0') << y << "\n" << std::setfill(' ');
  //   if(ss >> test)
  //     std::cout << test << "\n";
  //   else
  //     std::cerr << "failed\n";
  // std::string mainStr {std::move(getString())};
  // std::cout << mainStr << "\n";
  // std::cout << getString() << "\n";
  // getString() = "degistirildi";
  // std::cout << getString() << "\n\n";
  // int x = 5;
  // int y {std::move(x)};
  // std::cout << "x: " << x << " y: " << y << "\n";
  // std::cout << "&x: " << &x << " y: " << &y << "\n";

  // int num = 5;
  // x(num, 13);
  // std::cout << "value: " << num << "\n";

  // int arr[4000000];
  // int *ptr {new int[50000010]};
  // arr[0] = 5;
  // size_t last {sizeof(arr) / sizeof(arr[0]) - 1};
  // std::cout << "last: " << last << "\n";
  // arr[last] = 12;
  // size_t middle {(last - 1) / 2};
  // std::cout << "size of arr: " << sizeof(arr) << " bytes.\n";
  // std::cout << "first element: " << arr[0] << ", address: " << &arr[0] << "\n";
  // std::cout << "middle element: " << arr[middle] << ", address: " << &arr[middle] << "\n";
  // std::cout << "last element: " << arr[last] << ", address: " << &arr[last] << "\n";
  // std::cout << "Last address - first address: " << (&arr[last] - &arr[0]) << "\n\n"; 

  // ptr[0] = 3;
  // std::cout << "first element of heap array: " << ptr[0] << ", address: " << &ptr[0] << "\n";
  // std::cout << "last element of heap array: " << ptr[50000009] << ", address: " << &ptr[50000009] << "\n";
  // std::cout << "difference: " << (&ptr[50000009] - &ptr[0]) << "\n";
  // std::cout << "Press enter to continue: ";
  // std::cin.get();

  // delete[] ptr;

  // std::set<int> unq{5, 5, 5};
  // std::cout << "size of unq set: " << unq.size() << "\n";

  // std::cout << "hello world testing memory leak\n";
  // std::vector<int> data {342, 216, 742, 110};
  // std::cout << "address of vector: " << &data << "\n";
  // std::cout << "data address: " << data.data() << "\n";
  // std::cout << "first element: " << data.data()[0] << "\n";
  // std::cout << "last element: " << data.data()[data.size() - 1] << "\n";
  // std::vector<int> empty {};
  // std::cout << std::boolalpha << empty.empty() << "\n";
  // if(empty.data() == nullptr) {
  //   std::cout << "vector is not initialised\n";
  // }

  int x {3}, y {4};
  
  TimeCounter t1;
  
  // for(size_t i {}; i != 9'999'999; ++i) {
  //   swapByRef(x, y);
  // }
  // t1.timedelta();
  // std::cout << "x: " << x << ", y: " << y << "\n";

  for(size_t i {}; i != 9'999'999; ++i) {
    swapByPtr(&x, &y);
  }
  t1.timedelta();
  std::cout << "x: " << x << ", y: " << y << "\n";
  
  int *arr {new int[5] {3, 4, 5, 6, 7}};
  int *arrtmp {arr};
  std::cout << "address of arr: " << arr << ", arrtmp: " << arrtmp << "\n";
  arr = new int [5] {8, 9, 10, 11, 12};
  std::cout << "address of arr: " << arr << ", arrtmp: " << arrtmp << "\n";
  delete [] arr;
  delete [] arrtmp;

  char arrC[] {"hello"};
  std::cout << "size of char arr: " << sizeof(arrC) << "\n";  //normal string + 1 for null termination
  
  return 0;
}
