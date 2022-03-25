#include <iostream>
#include <locale>
#include <string>
#include <cstdio>

using namespace std;


int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Turkish");
    // std::string Ax {"hey"};
    // std::string x {argv[1] + std::string {" "} + argv[2]};
    // std::cout << "Ax : " << Ax << " x : " << x << '\n';
    int i {4}, y {4};
    std::cout << ++i << " ";
    std::cout << i++ << "\n";
    std::printf("%d ", ++y);
    std::printf("%d\n", y++);
    return 0;
}