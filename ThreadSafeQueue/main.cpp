#include <iostream>
#include "Runner.hpp"

#include <queue>

int main() {

    LinkedListTest::run(true);
    std::queue<int> q;
    q.push(32);
    q.push(44);
    q.push(36);
    q.push(69);
    std::cout << "front: " << q.front() << "\n";
    auto &fRef {q.front()};
    fRef = 18;
    
    std::cout << "front: " << q.front() << "\n";

    return 0;
}