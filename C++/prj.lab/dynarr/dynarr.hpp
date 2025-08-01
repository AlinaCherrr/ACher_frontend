#pragma once
#ifndef DYNARR_HPP
#define DYNARR_HPP

#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <cstddef>
#include <iosfwd>
#include <memory>


class DynArr {
public:
    DynArr() = default;
    DynArr(std::ptrdiff_t size);
    ~DynArr() = default;
    DynArr(const DynArr& rhs);
    DynArr(DynArr&& rhs) noexcept;

    DynArr& operator=(const DynArr& rhs);
    DynArr& operator=(DynArr&& rhs) noexcept;

    [[nodiscard]] std::ptrdiff_t Size() const noexcept;
    void Resize(const std::ptrdiff_t size);

    [[nodiscard]] float& operator[](const std::ptrdiff_t i);
    [[nodiscard]] const float& operator[](const std::ptrdiff_t i) const;

private:
    std::ptrdiff_t size_ = 0;
    std::ptrdiff_t capacity_ = 0;
    std::unique_ptr<float[]> data_ = 0;
};

#endif