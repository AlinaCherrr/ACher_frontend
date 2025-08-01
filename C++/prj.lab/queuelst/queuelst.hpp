#pragma once
#ifndef QUEUELST_HPP
#define QUEUELST_HPP
#include "complex/complex.hpp"
#include <stdexcept>
#include <algorithm>
#include <memory>
#include <cstddef>

class QueueLst final {
public:
    QueueLst() = default;
    QueueLst(const QueueLst& rhs);
    QueueLst(QueueLst&& rhs) noexcept;
    ~QueueLst();

    QueueLst& operator=(const QueueLst& rhs);
    QueueLst& operator=(QueueLst&& rhs) noexcept;
    void Push(const Complex& rhs);
    void Pop() noexcept;
    [[nodiscard]] bool IsEmpty() const noexcept;
    [[nodiscard]] Complex& Top() &;
    [[nodiscard]] const Complex& Top() const &;
    void Clear() noexcept;

private:
    struct Node {
        Complex val;
        Node* next = nullptr;
        Node() = default;
        ~Node() = default;
        Node(const Complex& value) :val(value) {}
    };
    Node* head_ = nullptr;
    Node* tail_ = nullptr;
};

#endif
