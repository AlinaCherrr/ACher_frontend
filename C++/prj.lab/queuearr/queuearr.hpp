#pragma once
#ifndef QUEUEARR_HPP
#define QUEUEARR_HPP

#include <iostream>
#include <memory>
#include <algorithm>
#include <cstddef>
#include <stdexcept>
#include "complex/complex.hpp"

class QueueArr final {
public:
    QueueArr() = default;
    QueueArr(const QueueArr& rhs);
    ~QueueArr() = default;
    QueueArr& operator=(const QueueArr& rhs);
    QueueArr& operator=(QueueArr&& d) noexcept;
    QueueArr(QueueArr&& d) noexcept;

    void Push(const Complex& c);
    void Pop() noexcept;
    void Clear() noexcept;
    [[nodiscard]] Complex& Top()&;
    [[nodiscard]] const Complex& Top() const&;
    bool IsEmpty() const noexcept;

private:
    std::ptrdiff_t capacity_ = 0;
    std::ptrdiff_t head_ = -1;
    std::ptrdiff_t tail_ = -1;
    std::unique_ptr<Complex[]> data_ = nullptr;
    std::ptrdiff_t Count() const {
        return IsEmpty() ? 0 : (tail_ + capacity_ - head_) % capacity_ + 1;
    };
};

#endif