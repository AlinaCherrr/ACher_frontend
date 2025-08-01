#include "stackarr/stackarr.hpp"
#include <stdexcept>
#include <algorithm>

StackArr::StackArr(const StackArr& rhs)
{
    i_top_ = rhs.i_top_;
    if (!rhs.IsEmpty()) {
        size_ = ((i_top_ + 1) / 4 + 1) * 4;
        data_ = std::make_unique<Complex[]>(size_);
        std::copy(rhs.data_.get(), rhs.data_.get() + i_top_ + 1, data_.get());
    }
}

StackArr::StackArr(StackArr&& rhs) noexcept
{
    std::swap(size_, rhs.size_);
    std::swap(i_top_, rhs.i_top_);
    std::swap(data_, rhs.data_);
}

//StackArr::~StackArr()
//{
//    delete[] data_;
//    data_ = nullptr;
//}

StackArr& StackArr::operator=(const StackArr& rhs)
{
    if (this != &rhs) {
        if (rhs.IsEmpty()) {
            Clear();
        }
        if (rhs.i_top_ >= size_) {
            size_ = (rhs.i_top_ + 4) / 4 * 4;
            data_ = std::make_unique<Complex[]>(rhs.size_);
        }
        i_top_ = rhs.i_top_;
        std::copy(rhs.data_.get(), rhs.data_.get() + i_top_ + 1, data_.get());
    }
    return *this;
}

StackArr& StackArr::operator=(StackArr&& rhs) noexcept
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

void StackArr::Push(const Complex& rhs) noexcept {

    if (i_top_ < 0) {
        size_ = 1;
        data_ = std::make_unique<Complex[]>(size_);
    }
    
    else if (i_top_ + 1 >= size_) {
        std::unique_ptr<Complex[]> new_data = std::make_unique<Complex[]>(size_ * 2);
        std::copy(data_.get(), data_.get() + size_, new_data.get());
        std::swap(data_, new_data);
        size_ *= 2;
    }

    data_[++i_top_] = rhs;

}

//void StackArr::Pop() noexcept {
//    if (i_top_ > -1) {
//        if (size_ / i_top_ > 2 && size_ > 8) {
//            size_ /= 2;
//            Complex* newData = new Complex[size_];
//            std::copy(data_, data_ + size_, newData);
//            delete[] data_;
//            data_ = newData;
//            newData = nullptr;
//        }
//        i_top_--;
//    }
//}
void StackArr::Pop() noexcept {
    if (!IsEmpty()) {
        i_top_ -= 1;
    }
}


bool StackArr::IsEmpty() const noexcept {
    return(i_top_ < 0);
}

Complex& StackArr::Top() & {
    if (i_top_ < 0) {
        throw std::logic_error("StackArr - try get top form empty stack.");
    }
    return data_[i_top_];
}

const Complex& StackArr::Top() const & {
    if (i_top_ < 0) {
        throw std::logic_error("StackArr - try get top form empty stack.");
    }
    return data_[i_top_];
}

void StackArr::Clear() noexcept {
    i_top_ = -1;
}
