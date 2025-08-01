#pragma once
#ifndef DYNARRT_HPP
#define DYNARRT_HPP

#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <cstddef>
#include <iosfwd>
#include <memory>

template<class T>
class DynArrT {
public:
    DynArrT() = default;
    DynArrT(std::ptrdiff_t size);
    ~DynArrT() = default;
    DynArrT(const DynArrT& rhs);
    DynArrT(DynArrT&& rhs) noexcept;

    DynArrT& operator=(const DynArrT& rhs);
    DynArrT& operator=(DynArrT&& rhs) noexcept;

    [[nodiscard]] std::ptrdiff_t Size() const noexcept;
    void Resize(const std::ptrdiff_t size);

    [[nodiscard]] T& operator[](const std::ptrdiff_t i);
    [[nodiscard]] const T& operator[](const std::ptrdiff_t i) const;

private:
    std::ptrdiff_t size_ = 0;
    std::ptrdiff_t capacity_ = 0;
    std::unique_ptr<T[]> data_;
};

#endif

template<class T>
DynArrT<T>::DynArrT(std::ptrdiff_t size)
{
    if (size > 0) {
        size_ = size;
        capacity_ = size;
        data_ = std::make_unique<T[]>(capacity_);
    }
    else if (size < 0) {
        throw std::invalid_argument("Negative array size\n");
    }
    else if (size == 0) {
        throw std::invalid_argument("Array of zero size\n");
    }
}

template<class T>
DynArrT<T>::DynArrT(const DynArrT<T>& rhs)
{
    size_ = rhs.size_;
    capacity_ = rhs.capacity_;
    data_ = std::make_unique<T[]>(capacity_);
    std::copy(rhs.data_.get(), rhs.data_.get() + rhs.size_, data_.get());
}

template<class T>
DynArrT<T>::DynArrT(DynArrT<T>&& rhs) noexcept
{
    std::swap(capacity_, rhs.capacity_);
    std::swap(size_, rhs.size_);
    std::swap(data_, rhs.data_);
}

template<class T>
DynArrT<T>& DynArrT<T>::operator=(const DynArrT<T>& rhs)
{
    if (this != &rhs) {
        if (rhs.size_ > capacity_) {
            capacity_ = rhs.capacity_;
            data_ = std::make_unique<T[]>(capacity_);
        }
        std::copy(rhs.data_.get(), rhs.data_.get() + rhs.size_, data_.get());
        size_ = rhs.size_;
    }
    return *this;
}

template<class T>
DynArrT<T>& DynArrT<T>::operator=(DynArrT<T>&& rhs) noexcept
{
    if (this != &rhs) {
        std::swap(capacity_, rhs.capacity_);
        std::swap(size_, rhs.size_);
        std::swap(data_, rhs.data_);
    }
    return *this;
}

template<class T>
std::ptrdiff_t DynArrT<T>::Size() const noexcept
{
    return size_;
}

template<class T>
void DynArrT<T>::Resize(const std::ptrdiff_t size)
{
    if (size > 0) {
        if (size > capacity_) {
            auto buf = std::make_unique<T[]>(size);
            std::copy(data_.get(), data_.get() + size_, buf.get());
            std::swap(data_, buf);
            capacity_ = size;
        }
        size_ = size;
    }
    else if (size < 0) {
        throw std::invalid_argument("Negative array size\n");
    }
    else {
        throw std::invalid_argument("Array of zero size\n");
    }
}

template<class T>
T& DynArrT<T>::operator[](const std::ptrdiff_t i)
{
    if (i < 0) {
        throw std::invalid_argument("Negative index\n");
    }
    else if (i >= size_) {
        throw std::out_of_range("Index out of range\n");
    }
    else {
        return data_[i];
    }
}

template<class T>
const T& DynArrT<T>::operator[](const std::ptrdiff_t i) const
{
    if (i < 0) {
        throw std::invalid_argument("Negative index\n");
    }
    else if (i >= size_) {
        throw std::out_of_range("Index out of range\n");
    }
    else {
        return data_[i];
    }
}
