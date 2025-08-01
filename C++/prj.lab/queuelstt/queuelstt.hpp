#pragma once
#ifndef QUEUELSTT_HPP
#define QUEUELSTT_HPP
#include <stdexcept>
#include <algorithm>
#include <memory>
#include <cstddef>

template<class T>
class QueueLstT final {
public:
    QueueLstT() = default;
    QueueLstT(const QueueLstT& rhs);
    QueueLstT(QueueLstT&& rhs) noexcept;
    ~QueueLstT();

    QueueLstT& operator=(const QueueLstT& rhs);
    QueueLstT& operator=(QueueLstT&& rhs) noexcept;
    void Push(const T& rhs);
    void Pop() noexcept;
    [[nodiscard]] bool IsEmpty() const noexcept;
    [[nodiscard]] T& Top()&;
    [[nodiscard]] const T& Top() const&;
    void Clear() noexcept;

private:
    struct Node {
        T val;
        Node* next = nullptr;
        Node() = default;
        ~Node() = default;
        Node(const T& value) :val(value) {}
    };
    Node* head_ = nullptr;
    Node* tail_ = nullptr;
};

#endif



template<class T>
QueueLstT<T>::QueueLstT(const QueueLstT<T>& rhs)
{
    if (rhs.head_ != nullptr) {
        if (this != &rhs) {
            Node* newNode = new Node(rhs.head_->val);
            head_ = newNode;
            tail_ = newNode;
            Node* current = rhs.head_->next;
            while (current != nullptr) {
                Node* newNode = new Node(current->val);
                current = current->next;
                tail_->next = newNode;
                tail_ = newNode;
            }
        }
    }
    else {
        head_ = nullptr;
        tail_ = nullptr;
    }
}

template<class T>
QueueLstT<T>::QueueLstT(QueueLstT<T>&& rhs) noexcept
{
    std::swap(head_, rhs.head_);
    std::swap(tail_, rhs.tail_);
}

template<class T>
QueueLstT<T>::~QueueLstT()
{
    while (head_ != nullptr) {
        Node* temp = head_;
        head_ = head_->next;
        delete temp;
        temp = nullptr;
    }
}

template<class T>
QueueLstT<T>& QueueLstT<T>::operator=(const QueueLstT<T>& rhs)
{
    if (rhs.head_ == nullptr) {
        head_ = nullptr;
        tail_ = nullptr;
    }
    else {
        if (this != &rhs) {
            Node* rhs_cur = rhs.head_;
            Node* cur = head_;
            if (cur == nullptr) {
                Node* newNode = new Node;
                cur = newNode;
                head_ = newNode;
                tail_ = newNode;
            }
            while (rhs_cur != nullptr) {
                if (cur == nullptr) {
                    Node* newNode = new Node;
                    cur = newNode;
                    tail_->next = newNode;
                    tail_ = newNode;
                }

                cur->val = rhs_cur->val;
                rhs_cur = rhs_cur->next;

                if (rhs_cur == nullptr) {
                    tail_ = cur;
                    tail_->next = nullptr;
                }
                cur = cur->next;
            }
            while (cur != nullptr) {
                Node* temp = cur;
                cur = cur->next;
                delete temp;
            }
        }
    }
    return *this;
}

template<class T>
QueueLstT<T>& QueueLstT<T>::operator=(QueueLstT<T>&& rhs) noexcept
{
    if (this != &rhs) {
        std::swap(head_, rhs.head_);
        std::swap(tail_, rhs.tail_);
    }
    return *this;
}

template<class T>
void QueueLstT<T>::Push(const T& rhs)
{
    Node* newNode = new Node(rhs);
    if (head_ == nullptr) {
        head_ = newNode;
        tail_ = newNode;
    }
    else {
        tail_->next = newNode;
        tail_ = newNode;
    }
}

template<class T>
void QueueLstT<T>::Pop() noexcept
{
    if (head_ != nullptr) {
        Node* temp = head_;
        head_ = head_->next;
        delete temp;
    }
}

template<class T>
bool QueueLstT<T>::IsEmpty() const noexcept
{
    return head_ == nullptr;
}

template<class T>
T& QueueLstT<T>::Top()&
{
    if (!IsEmpty()) {
        return head_->val;
    }
    else {
        throw std::logic_error("QueueLst - try get top form empty queue.");
    }
}

template<class T>
const T& QueueLstT<T>::Top() const&
{
    if (!IsEmpty()) {
        return head_->val;
    }
    else {
        throw std::logic_error("QueueLst - try get top form empty queue.");
    }
}

template<class T>
void QueueLstT<T>::Clear() noexcept
{
    while (!IsEmpty()) {
        Pop();
    }
}

