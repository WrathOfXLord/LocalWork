#pragma once

#include <memory>

template <typename T>
struct Node {
    using type_pointer = T *;
    using type_reference = T &;
    using Node_ptr = Node<T> *;
    using Node_ref = Node<T> &;

    std::unique_ptr<T> data;
    Node<T> *next;

    // Node(type_pointer data) : data {data}, next {} {}
    explicit Node(T &&data) : data {new T {std::forward<T>(data)}}, next {} {}

    bool operator==(const Node_ref rhs) const { return *data == *rhs.data; };
    bool operator!=(const Node_ref rhs) const { return *data != *rhs.data; };
    type_reference operator*() { return *data; }
    const type_reference operator*() const { return *data; }
};