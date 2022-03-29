#include "MyTemplateVec.hpp"
#include "Exceptions.hpp"
#include "TemplateQSort_implement.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <iomanip>
#include <locale>

using timer = std::chrono::high_resolution_clock::time_point;
using int64 = long long int;

// gcc warns about overloading delete operators !!

void *operator new(std::size_t size) {
  std::cout << "Allocating " << size << " bytes of memory\n";
  return std::malloc(size);
}

void operator delete(void *memory, std::size_t size){
  std::cout << "Releasing " << size << " bytes of memory\n";
  std::free(memory);
}

void *operator new[](std::size_t size) {
  std::cout << "Allocating " << size << " bytes of memory\n";
  return std::malloc(size);
}

void operator delete[](void *memory, std::size_t size) {
  std::cout << "Releasing " << size << " bytes of memory\n";
  std::free(memory);
}


int main()
{
	// setlocale(LC_ALL, "Turkish");
	// // timer t1 {std::chrono::high_resolution_clock:: now()};
	// // timer t3 {std::chrono::high_resolution_clock:: now()};
	
	MyTemplateVec<std::string> newVec;
	MyTemplateVec<std::string> anotherVec {newVec};
	// newVec.push_back("ali firat");
	// newVec.push_back("rahime");
	// newVec.push_back("nisa");
	// newVec.push_back("merve");
	// newVec.push_back("linda");
	// // // timer t4 {std::chrono::high_resolution_clock:: now()};
	// std::cout << "before delete: " << newVec << "\n";
	// std::cout << newVec.pop_back() << " has been removed" << std::endl;
	// std::cout << "after delete: " << newVec << "\n";
	// std::cout << "another: " << anotherVec << "\n";

	// //std::cout << "\nlast element was: " << newVec.pop_back() << " and has been removed" << std::endl;
	// MyTemplateVec<std::string> copyVec;
	// copyVec = newVec;
	// std::cout << std::endl << "original vec: \n" << newVec << std::endl;
	// std::cout << std::endl << "copy vec: \n" << copyVec << std::endl;
	// std::cout << "size of newVec is : " << newVec.size() << std::endl;
	// std::cout << "last element is : " << newVec[3] << std::endl;
	// std::cout << "last element is : ";
	// newVec.print(3);
	// std::cout << std::endl;
	// newVec.print(std::cout, 3);
	// std::cout << std::endl;
	// //test line
	// MyTemplateVec<int> test {2};
	// test.push_back(12);
	// for(size_t i {}; i < test.size(); ++i)
	//     std::cout << "test[" << i << "]: " << test[i] << "  ";
	// std::cout << "\n";

	// int x {int {}};
	// std::cout << "x is : " << x << std::endl;

	// MyTemplateVec<std::string> stringTestVec {std::string {"heyyo there"}};

	// //original vector
	// std::vector<std::string> test2;
	// test2.resize(4);
	// for(size_t i {}; i < test2.size(); ++i)
	//     std::cout << test2[i];
	// std::cout << std::endl;

	// for(auto a {newVec.begin()}; a != newVec.end(); ++a)
	//     std::cout << *a << std::endl;

	// for(auto u:newVec)
	// {
	//     u = "changed";
	//     std::cout << u << std::endl;
	// }

	// for(std::string &x:newVec)
	//     std::cout << x << std::endl;

	// std::cout << "-----------------------------------------------------" << std::endl;
	// for(CustomIterator<std::string> i {newVec.begin()}; i != newVec.end(); ++i)
	//     std::cout << *i << std::endl;
	// std::string tryStr {"342212"};
	// std::cout << "1- tryStr val: " << tryStr << "\n";
	// MyTemplateVec<std::string> anew {tryStr, "there", "how", std::move(tryStr), "you"};
	// std::cout << anew << std::endl;
	// for(size_t i {0}; i < anew.size(); ++i)
	//     std::cout << anew[i] << std::endl;
	// std::cout << "2- tryStr val: " << tryStr << "\n";
	// MyTemplateVec intlist {5, 6, 7, 8, 9, int {5}}; //type deduction, no need to give the type name.
	// for(const auto &i:intlist)
	//     std::cout << i << std::endl;

	// std::cout << intlist << std::endl;

	// MyTemplateVec<std::string> stringVector {"yagmur", "ali", "gulsun", "veli", "hello"};
	// std::string xy {"hey there"};
	// stringVector.push_back("ello govnar");
	// stringVector.push_back(xy);
	// std::cout << stringVector << std::endl;
	// std::cout << "last element was : " << stringVector.pop_back() << " and has been removed" << std::endl;
	// std::cout << stringVector << std::endl;

	// for(const std::string &printS:stringVector)
	//     std::cout << printS << std::endl;

	// std::vector ane {4, 5, 6};
	// MyTemplateVec<std::string> popVec {"one", "two", "tree", "for", "five"};
	// std::cout << "size of popVec: " << popVec.size() << '\n';
	// std::cout << "cap of popVec: " << popVec.capacity() << '\n';
	// popVec.pop_back();
	// timer t2 {std::chrono::high_resolution_clock:: now()};
	// popVec.pop_back();
	// popVec.pop_back();
	// popVec.pop_back();
	// std::chrono::nanoseconds et1 {std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1)};
	// std::chrono::nanoseconds et2 {std::chrono::duration_cast<std::chrono::nanoseconds>(t4 - t3)};
	// std::cout << "et1 : " << et1.count() << " nanoseconds\n";
	// std::cout << "et2 : " << et2.count() << " nanoseconds\n";
	// std::cout << "et1 : " << std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count() << " seconds\n";
	// std::cout << "et2 : " << std::chrono::duration_cast<std::chrono::duration<double>>(t4 - t3).count() << " seconds\n";
	// std::cout << "size of popVec: " << popVec.size() << '\n';
	// std::cout << "cap of popVec: " << popVec.capacity() << '\n';
	// std::cout << popVec << '\n';
	// popVec.swapElements(0, 1);
	// popVec.swapElements(4, 3);
	// std::cout << popVec << '\n';

	// MyTemplateVec<std::string> avec;
	// std::cout << "avec : " << avec << '\n';
	// avec.swap(popVec);
	// std::cout << "avec : " << avec << '\n';
	// std::cout << "popvec : " << popVec << '\n';
	// std::cout << stringVector << '\n';
	// QSort(stringVector, 0, static_cast<int64>(stringVector.size() - 1));
	// std::cout << stringVector << '\n';
	// RQSort(stringVector, 0, static_cast<int64>(stringVector.size() - 1));
	// std::cout << stringVector << '\n' << '\n';

	// MyTemplateVec<std::string> stringV2 {"merve", "rahime", "ali", "linda", "fırat"};

	// std::cout << stringV2 << '\n';
	// QSort(stringV2, 0, stringV2.size() - 1);
	// std::cout << stringV2 << '\n' << '\n';
	// RQSort(stringV2, 0, stringV2.size() - 1);
	// std::cout << stringV2 << '\n' << '\n';
	// MyTemplateVec<int> intV2 {3, 4, 5, 1, 2, 2, 12, 36, 101, 9};
	// std::cout << intV2 << '\n' << '\n';
	// QSort(intV2, 0, intV2.size() - 1);
	// std::cout << "in order intV2: " << intV2 << '\n';
	// RQSort(intV2, 0, intV2.size() - 1);
	// std::cout << "reverse order intV2: " << intV2 << '\n';
	// std::string testStr {"this is a test"};
	// MyTemplateVec<std::string> strTest {"abc", "def", "klm"};
	// strTest.push_back(std::string {"hey"});
	// strTest.push_back(std::string {"hey"});
	// strTest.push_back(std::string {"hey"});
	// strTest.push_back(testStr);
	// std::cout << strTest << '\n';

	// std::vector<std::string> anyTest {10};
	// anyTest.pop_back();
	// std::cout << "size : " << anyTest.size() << "\ncapacity : " << anyTest.capacity() << '\n';
	// anyTest.shrink_to_fit();
	// std::cout << "size : " << anyTest.size() << "\ncapacity : " << anyTest.capacity() << '\n';

	// std::string x {"347"}, y {"testing"}, z {"yo"};
	// const std::string t {"non changeable"};
	// MyTemplateVec<std::string> testForStr {"str1", x, y, z, "1246", std::move(t)};
	// std::cout << testForStr << "\n";
	// testForStr[5] = "changed";
	// std::cout << testForStr << "\n";
	// MyTemplateVec<int> myInt{5, 4, 7, 6, 15, 12};
	// for (int i : myInt)
	// {
	// 	std::cout << " " << i << " ";
	// }
	// std::cout << "\n";
	// std::vector<int> vec{5, 4, 7, 6, 15, 12};
	// std::cout << *(vec.end() - 1) << "\n";
	// QSort(myInt, 0, myInt.size() - 1);
	// std::cout << myInt << "\n";
	// MyTemplateVec<int> testVector(200000ull);
	// MyTemplateVec<int> testVector2(500000ull);
	// testVector[0] = 10;
	// testVector2[0] = 20;
	// std::cout << "vector1 size: " << testVector.size() << " first element: " << testVector[0] << "\n";
	// std::cout << "vector2 size: " << testVector2.size() << " first element: " << testVector2[0] << "\n";
	// std::cout << "Address of first vector:  0x" << std::hex << std::showbase << &testVector[0] << std::dec << std::noshowbase << "\n";
	// std::cout << "Address of second vector: 0x" << std::hex << std::showbase << &testVector2[0] << std::dec << std::noshowbase << "\n";
	// timer time_point_1{std::chrono::high_resolution_clock::now()};
	// testVector.swap(testVector2);
	// timer time_point_2{std::chrono::high_resolution_clock::now()};
	// std::cout << "\nvector1 size: " << testVector.size() << " first element: " << testVector[0] << "\n";
	// std::cout << "vector2 size: " << testVector2.size() << " first element: " << testVector2[0] << "\n";
	// std::cout << "Address of first vector:  0x" << std::hex << std::showbase << &testVector[0] << std::dec << std::noshowbase << "\n";
	// std::cout << "Address of second vector: 0x" << std::hex << std::showbase << &testVector2[0] << std::dec << std::noshowbase << "\n";
	// std::cout << "Elapsed time: " << std::fixed << std::chrono::duration_cast<std::chrono::duration<double>>(time_point_2 - time_point_1).count() << "\n";


	std::string testStr {"test str"};
	MyTemplateVec<std::string> stringVectorTest {"hey there", "what are you waiting for", "hello world", "i am coming", "on my way", std::move(testStr)};
	std::cout << "teststr: " << testStr << ", vec element: " << *(stringVectorTest.end() - 1) << "\n";
	std::cout << stringVectorTest << ", size: " << stringVectorTest.size() << ", cap: " << stringVectorTest.capacity() << "\n";
	MyTemplateVec<std::string> emptyStringVector {};
	stringVectorTest.swap(emptyStringVector);
	std::cout << emptyStringVector << "\n";
	std::cout << "size of vec: " << emptyStringVector.size() << "\n";
	QSort(emptyStringVector, 0, emptyStringVector.size() - 1);
	std::cout << emptyStringVector << "\n";
	return 0;
}
