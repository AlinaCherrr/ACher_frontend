#include "dynarr.hpp"

DynArr::DynArr(const std::ptrdiff_t size) {
    if (size > 0) {
        size_ = size;
        capacity_ = size;
        data_ = std::make_unique<float[]>(capacity_);
        std::fill(data_.get(), data_.get() + size, 0);
    }
    else if (size < 0) {
        throw std::invalid_argument("Negative array size\n");
    }
    else if (size == 0) {
        throw std::invalid_argument("Array of zero size\n");
    }
}

//DynArr::~DynArr() { delete[] data_; }

DynArr::DynArr(const DynArr& rhs) {
    size_ = rhs.size_;
    capacity_ = rhs.capacity_;
    data_ = std::make_unique<float[]>(capacity_);
    std::copy(rhs.data_.get(), rhs.data_.get() + rhs.size_, data_.get());
}

DynArr::DynArr(DynArr&& rhs) noexcept
{
    std::swap(capacity_, rhs.capacity_);
    std::swap(size_, rhs.size_);
    std::swap(data_, rhs.data_);
}

DynArr& DynArr::operator=(DynArr&& rhs) noexcept {
    if (this != &rhs) {
        std::swap(capacity_, rhs.capacity_);
        std::swap(size_, rhs.size_);
        std::swap(data_, rhs.data_);
    }
    return *this;
}

DynArr& DynArr::operator=(const DynArr& rhs) {
    if (this != &rhs) {
        if (rhs.size_ > capacity_) {
            capacity_ = rhs.capacity_;
            data_ = std::make_unique<float[]>(capacity_);
        }
        std::copy(rhs.data_.get(), rhs.data_.get() + rhs.size_, data_.get());
        size_ = rhs.size_;
    }
    return *this;
}


std::ptrdiff_t DynArr::Size() const noexcept {
    return size_;
}


void DynArr::Resize(const std::ptrdiff_t size) {
    if (size > 0) {
        if (size > size_ && size <= capacity_) {
            std::fill(data_.get() + size_, data_.get() + size, 0);
        }
        else if (size > capacity_) {
            auto buf = std::make_unique<float[]>(size);
            std::copy(data_.get(), data_.get() + size_, buf.get());
            std::fill(buf.get() + size_, buf.get() + size, 0);
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


float& DynArr::operator[](const std::ptrdiff_t i) {
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

const float& DynArr::operator[](const std::ptrdiff_t i) const {
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
