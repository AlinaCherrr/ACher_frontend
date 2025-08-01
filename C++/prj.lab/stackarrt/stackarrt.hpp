#pragma once
#ifndef STACKARRT_HPP
#define STACKARRT_HPP

#include <cstddef>
#include <memory>
#include <stdexcept>
#include <algorithm>

template <class T>
class StackArrT {
public:
    StackArrT() = default;
    StackArrT(const StackArrT& rhs);
    StackArrT(StackArrT&& rhs) noexcept;
    ~StackArrT() = default;

    StackArrT& operator=(const StackArrT& rhs);
    StackArrT& operator=(StackArrT&& rhs) noexcept;
    void Push(const T& rhs) noexcept;
    void Pop() noexcept;
    [[nodiscard]] bool IsEmpty() const noexcept;
    [[nodiscard]] T& Top()&;
    [[nodiscard]] const T& Top() const&;
    void Clear() noexcept;

private:
    std::ptrdiff_t size_ = 0;
    std::ptrdiff_t i_top_ = -1;
    std::unique_ptr<T[]> data_ = std::make_unique<T[]>(size_);
};

#endif

template<class T>
StackArrT<T>::StackArrT(const StackArrT<T>& rhs)
{
    i_top_ = rhs.i_top_;
    if (!rhs.IsEmpty()) {
        size_ = ((i_top_ + 1) / 4 + 1) * 4;
        data_ = std::make_unique<T[]>(size_);
        std::copy(rhs.data_.get(), rhs.data_.get() + i_top_ + 1, data_.get());
    }
}

template<class T>
StackArrT<T>::StackArrT(StackArrT<T>&& rhs) noexcept
{
    std::swap(size_, rhs.size_);
    std::swap(i_top_, rhs.i_top_);
    std::swap(data_, rhs.data_);
}

template<class T>
StackArrT<T>& StackArrT<T>::operator=(const StackArrT<T>& rhs)
{
    if (this != &rhs) {
        if (rhs.IsEmpty()) {
            Clear();
        }
        if (rhs.i_top_ >= size_) {
            size_ = (rhs.i_top_ + 4) / 4 * 4;
            data_ = std::make_unique<T[]>(rhs.size_);
        }
        i_top_ = rhs.i_top_;
        std::copy(rhs.data_.get(), rhs.data_.get() + i_top_ + 1, data_.get());
    }
    return *this;
}

template<class T>
StackArrT<T>& StackArrT<T>::operator=(StackArrT<T>&& rhs) noexcept
{
    if (this != &rhs) {
        if (!rhs.IsEmpty()) {
            std::swap(size_, rhs.size_);
            std::swap(i_top_, rhs.i_top_);
            std::swap(data_, rhs.data_);
        }
        else {
            Clear();
        }
    }
    return *this;
}

template<class T>
void StackArrT<T>::Push(const T& rhs) noexcept {

    if (i_top_ < 0) {
        size_ = 1;
        data_ = std::make_unique<T[]>(size_);
    }

    else if (i_top_ + 1 >= size_) {
        std::unique_ptr<T[]> new_data = std::make_unique<T[]>(size_ * 2);
        std::copy(data_.get(), data_.get() + size_, new_data.get());
        std::swap(data_, new_data);
        size_ *= 2;
    }

    data_[++i_top_] = rhs;

}

template<class T>
void StackArrT<T>::Pop() noexcept {
    if (!IsEmpty()) {
        i_top_ -= 1;
    }
}


template<class T>
bool StackArrT<T>::IsEmpty() const noexcept {
    return(i_top_ < 0);
}

template<class T>
T& StackArrT<T>::Top()& {
    if (i_top_ < 0) {
        throw std::logic_error("StackArr - try get top form empty stack.");
    }
    return data_[i_top_];
}

template<class T>
const T& StackArrT<T>::Top() const& {
    if (i_top_ < 0) {
        throw std::logic_error("StackArr - try get top form empty stack.");
    }
    return data_[i_top_];
}

template<class T>
void StackArrT<T>::Clear() noexcept {
    i_top_ = -1;
};
