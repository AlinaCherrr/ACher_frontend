#include "queuearr.hpp"

QueueArr::QueueArr(const QueueArr& rhs) {
    if (!rhs.IsEmpty()) {
        std::ptrdiff_t count = rhs.Count();
        head_ = 0;
        tail_ = count - 1;
        capacity_ = (count + 4) / 4 * 4;
        data_ = std::make_unique<Complex[]>(capacity_);
        if (rhs.head_ < rhs.tail_) {
            std::copy(rhs.data_.get() + rhs.head_, rhs.data_.get() + rhs.tail_ + 1, data_.get());
        }
        else {
            std::copy(rhs.data_.get() + rhs.head_, rhs.data_.get() + rhs.capacity_, data_.get());
            std::copy(rhs.data_.get(), rhs.data_.get() + rhs.tail_ + 1, data_.get() + rhs.capacity_ - rhs.head_);
        }
    }
}

QueueArr::QueueArr(QueueArr&& d) noexcept {
    std::swap(capacity_, d.capacity_);
    std::swap(data_, d.data_);
    std::swap(tail_, d.tail_);
    std::swap(head_, d.head_);
}

QueueArr& QueueArr::operator=(QueueArr&& d) noexcept {
    if (this != &d) {
        std::swap(capacity_, d.capacity_);
        std::swap(data_, d.data_);
        std::swap(tail_, d.tail_);
        std::swap(head_, d.head_);
    }
    return *this;
}

QueueArr& QueueArr::operator=(const QueueArr& rhs) {
    if (this != &rhs) {
        std::ptrdiff_t count = rhs.Count();
        if (!count) {
            head_ = -1;
        }
        else {
            if (capacity_ < count) {
                capacity_ = (count + 4) / 4 * 4;
                data_ = std::make_unique<Complex[]>(capacity_);
            }
            if (rhs.head_ < rhs.tail_) {
                std::copy(rhs.data_.get() + rhs.head_, rhs.data_.get() + rhs.tail_ + 1, data_.get());
            }
            else {
                std::copy(rhs.data_.get() + rhs.head_, rhs.data_.get() + rhs.capacity_, data_.get());
                std::copy(rhs.data_.get(), rhs.data_.get() + rhs.tail_ + 1, data_.get() + rhs.capacity_ - rhs.head_);
            }
            head_ = 0;
            tail_ = count - 1;
        }
    }
    return *this;
}

void QueueArr::Push(const Complex& c) {
    if (!data_) {
        capacity_ = 2;
        data_ = std::make_unique<Complex[]>(capacity_);
    }
    if (IsEmpty()) {
        head_ = 0;
        tail_ = 0;
    }
    else {
        if (head_ == (tail_ + 1) % capacity_) {
            auto new_data = std::make_unique<Complex[]>(capacity_ * 2);
            if (head_ < tail_) {
                std::copy(data_.get() + head_, data_.get() + tail_ + 1, new_data.get());
            }
            else {
                std::copy(data_.get() + head_, data_.get() + capacity_, new_data.get());
                std::copy(data_.get(), data_.get() + tail_ + 1, new_data.get() + capacity_ - head_);
            }
            std::swap(data_, new_data);
            capacity_ *= 2;
            tail_ = Count();
        }
        else {
            tail_ = (tail_ + 1) % capacity_;
        }
    }
    data_[tail_] = c;
}

void QueueArr::Pop() noexcept {
    if (!IsEmpty()) {
        if (head_ != tail_) {
            head_ = (head_ + 1) % capacity_;
        }
        else {
            head_ = -1;
        }
    }
}

Complex& QueueArr::Top()& {
    if (head_ < 0) {
        throw std::logic_error("QueueArr Is Empty!");
    }
    else {
        return data_[head_];
    }
}

const Complex& QueueArr::Top() const& {
    if (head_ < 0) {
        throw std::logic_error("QueueArr Is Empty!");
    }
    else {
        return data_[head_];
    }
}

bool QueueArr::IsEmpty() const noexcept {
    return head_ < 0;
}

void QueueArr::Clear() noexcept {
    head_ = -1;
}