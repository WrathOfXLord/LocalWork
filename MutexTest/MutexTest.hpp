#pragma once

#include <iostream>
#include <mutex>
#include <thread>
#include <list>

std::list<int> myList;
std::mutex m;

void addToList(const int &x) {
    m.lock();
    myList.push_front(x);
    m.unlock();
}

void size() {
    m.lock();
    std::size_t size {myList.size()};
    m.unlock();
    std::cout << "size of the list: " << size << "\n";
}

void run() {
    std::thread t1 {addToList, 4};
    std::thread t2 {addToList, 11};

    t1.join();
    t2.join();
}