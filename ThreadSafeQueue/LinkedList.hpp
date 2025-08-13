#pragma once
#include "Node.hpp"

#include <mutex>
#include <memory>
#include <optional>
#include <ostream>

template <typename T>
class LinkedList {
    friend std::ostream &operator<<(std::ostream &out, LinkedList<T> &list) {
        std::lock_guard<std::mutex> lengthGuard {list.mLengthMutex};
        if(list.mLength == 0) {
            return out;
        }
        
        out << list.front();
        Node<T> *head {list.mHead->next};
        for(std::size_t lstLengthNoFront {list.mLength - 1}; lstLengthNoFront > 0; --lstLengthNoFront) {
            out << " <= " << *head->data;
            head = head->next;
        }
        return out;
    }
 private:
    Node<T> *mTail;
    Node<T> *mHead;
    std::size_t mLength;
    std::mutex mHeadMutex;
    std::mutex mTailMutex;
    std::mutex mLengthMutex;
 public:
    LinkedList() : mTail {nullptr}, mHead {nullptr}, mLength {} {}

    template<typename V, typename std::enable_if_t<std::is_same_v<T, std::decay_t<V>>, bool> = true>
    void push(V &&value) {
        Node<T> *newNode {new Node {std::forward<V>(value)}};
        
        std::lock_guard<std::mutex> tailGuard {mTailMutex};
        if(mTail == nullptr) {
            std::lock_guard<std::mutex> headGuard {mHeadMutex};
            mHead = newNode;
        } else {
            mTail->next = newNode;
        }
        mTail = newNode;
        std::lock_guard<std::mutex> lengthGuard {mLengthMutex};
        ++mLength;
    }

    std::unique_ptr<T> pop() {
        std::lock_guard headGuard {mHeadMutex};
        if(mHead == nullptr) {
            return std::unique_ptr<T> {};
        }
        Node<T> *poppedNode {mHead};
        mHead = mHead->next;
        std::lock_guard<std::mutex> lengthGuard {mLengthMutex};
        --mLength;
        std::unique_ptr<T> value {std::move(poppedNode->data)};
        delete poppedNode;
        return value;
    }

    ~LinkedList() {
        Node<T> *tmpPtr {};
        while(mHead) {
            tmpPtr = mHead;
            mHead = mHead->next;
            delete tmpPtr;
        }
    }

    T &front() { std::lock_guard headGuard {mHeadMutex}; return *mHead->data; }
    T &back() { std::lock_guard<std::mutex> tailGuard {mTailMutex}; return *mTail->data; }
    std::size_t length() const { std::lock_guard<std::mutex> lengthGuard {mLengthMutex}; return mLength; }

};