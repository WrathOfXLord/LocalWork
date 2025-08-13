#pragma once

#include <iostream>
#include <stack>


template <typename T>
class ThreadSafeStack {
 private:
    std::stack<T> mStack;
    std::mutex mMutex;

 public:
    void push(T &&element) {
        std::lock_guard<std::mutex> lockGuard {mMutex};
        mStack.push(std::forward<T>(element));
    }

    void pop() {
        std::lock_guard<std::mutex> lockGuard {mMutex};
        mStack.pop();
    }

    T &top() {
        std::lock_guard<std::mutex> lockGuard {mMutex};
        return mStack.top();
    }

    bool isEmpty() const {
        std::lock_guard<std::mutex> lockGuard {mMutex};
        return mStack.empty();
    }

    std::size_t size() const {
        std::lock_guard<std::mutex> lockGuard {mMutex};
        return mStack.size();
    }
};