#include "DelegatingConstructors.hpp"
#include <chrono>
#include <iomanip>

using namespace std;
using timer = std::chrono::high_resolution_clock::time_point;

int main()
{
    timer t1 {chrono::high_resolution_clock::now()};
    Player p1("batman");
    timer t2 {chrono::high_resolution_clock::now()};
    chrono::duration <double> time_elapsed {duration_cast <chrono::duration<double>>(t2 - t1)};
    cout << "elapsed time is : " << setprecision(10) << time_elapsed.count() << endl;
    p1.talk("who am i ?");
    cout << "you are " << "the " << p1.getName() << "." << endl;
    p1.isDead();
    cout << "you are no longer " << p1.getName() << ", ";
    p1.setName("superman");
    cout << "you are now " << p1.getName() << "." << endl;

    return 0;
}