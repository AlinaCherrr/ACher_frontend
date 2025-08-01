#pragma once
#ifndef STACKLST_HPP
#define STACKLST_HPP

#include "complex/complex.hpp"
#include <cstddef>
#include <stdexcept>
#include <algorithm>


class StackLst final {
public:
    StackLst() = default;
    StackLst(const StackLst& rhs);
    StackLst(StackLst&& rhs) noexcept;
    ~StackLst();

    StackLst& operator=(const StackLst& rhs) noexcept;
    StackLst& operator=(StackLst&& rhs) noexcept;
    void Push(const Complex& rhs) noexcept;
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
        Node(const Complex& val) : val(val) {}
        ~Node() = default;

    };
    Node* head_ = nullptr;
};


#endif
