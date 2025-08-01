#pragma once
#ifndef STACKLSTT_HPP
#define STACKLSTT_HPP


#include <cstddef>
#include <memory>
#include <stdexcept>
#include <algorithm>


template<class T>
class StackLstT final {
public:
    StackLstT() = default;
    StackLstT(const StackLstT& rhs);
    StackLstT(StackLstT&& rhs) noexcept;
    ~StackLstT();

    StackLstT& operator=(const StackLstT& rhs) noexcept;
    StackLstT& operator=(StackLstT&& rhs) noexcept;
    void Push(const T& rhs) noexcept;
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
        Node(const T& val) : val(val) {}
        ~Node() = default;

    };
    Node* head_ = nullptr;
};




template<class T>
StackLstT<T>::StackLstT(const StackLstT& rhs)
{
    if (rhs.head_ != nullptr) {
        Node* newNode = new Node(rhs.head_->val);
        head_ = newNode;
        Node* rn = rhs.head_->next;
        Node* cur = newNode;
        while (rn != nullptr) {
            Node* newNode = new Node(rn->val);
            cur->next = newNode;
            rn = rn->next;
            cur = newNode;
        }
    }
    else {
        head_ = nullptr;
    }
}

template<class T>
StackLstT<T>::StackLstT(StackLstT&& rhs) noexcept
{
    std::swap(head_, rhs.head_);
}

template<class T>
StackLstT<T>::~StackLstT()
{
    while (head_ != nullptr) {
        Node* temp = head_;
        head_ = head_->next;
        delete temp;
        temp = nullptr;
    }
}

template<class T>
StackLstT<T>& StackLstT<T>::operator=(const StackLstT& rhs) noexcept
{
    if (rhs.head_ == nullptr) {
        head_ = nullptr;
    }
    else {
        if (this != &rhs) {
            Node* rhs_cur = rhs.head_;
            Node* cur = head_;
            Node* tail = cur;
            if (cur == nullptr) {
                Node* newNode = new Node;
                cur = newNode;
                head_ = newNode;
                tail = cur;
            }
            while (rhs_cur != nullptr) {
                if (cur == nullptr) {
                    Node* newNode = new Node;
                    cur = newNode;
                    tail->next = newNode;
                    tail = newNode;
                }

                cur->val = rhs_cur->val;
                rhs_cur = rhs_cur->next;

                if (rhs_cur == nullptr) {
                    tail = cur;
                    tail->next = nullptr;
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
StackLstT<T>& StackLstT<T>::operator=(StackLstT&& rhs) noexcept
{
    if (this != &rhs) {
        std::swap(head_, rhs.head_);
    }
    return *this;
}

template<class T>
void StackLstT<T>::Push(const T& rhs) noexcept
{
    Node* newNode = new Node(rhs);
    newNode->next = head_;
    head_ = newNode;
    newNode = nullptr;
}

template<class T>
void StackLstT<T>::Pop() noexcept
{
    if (head_ != nullptr) {
        Node* temp = head_;
        head_ = temp->next;
        delete temp;
        temp = nullptr;
    }
}

template<class T>
bool StackLstT<T>::IsEmpty() const noexcept
{
    return head_ == nullptr;
}

template<class T>
T& StackLstT<T>::Top()&
{
    if (!IsEmpty()) {
        return head_->val;
    }
    else {
        throw std::logic_error("StackLst - try get top form empty stack.");
    }
}

template<class T>
const T& StackLstT<T>::Top() const&
{
    if (!IsEmpty()) {
        return head_->val;
    }
    else {
        throw std::logic_error("StackLst - try get top form empty stack.");
    }
}

template<class T>
void StackLstT<T>::Clear() noexcept
{
    while (!IsEmpty()) {
        Pop();
    }
}


#endif
