#pragma once
#ifndef QUEUELSTPRT_HPP 
#define QUEUELSTPRT_HPP
#include <stdexcept>
#include <algorithm>
#include <cstddef>
#include <memory>
#include <iostream>

template<class T>
class QueueLstPrT {
public:
    QueueLstPrT() = default;
    ~QueueLstPrT();
    QueueLstPrT(const QueueLstPrT& rhs);
    QueueLstPrT(QueueLstPrT&& rhs) noexcept;
    QueueLstPrT& operator=(const QueueLstPrT& rhs);
    QueueLstPrT& operator=(QueueLstPrT&& rhs) noexcept;

    void Push(const T& rhs);
    void Pop();
    [[nodiscard]] bool IsEmpty();
    [[nodiscard]] T& Top()&;
    [[nodiscard]] const T& Top() const&;
    void Clear() noexcept;

private:
    struct Node {
        T val;
        Node* next = nullptr;
        Node() = default;
        Node(const T v) :val(v) {};
        ~Node() = default;
    };
    Node* head_ = nullptr;

};
#endif

template<class T>
 QueueLstPrT<T>::~QueueLstPrT()
{
     Node* tm = head_;
     while (tm != nullptr) {
         tm = head_->next;
         delete head_;
         head_ = tm;
     }
}

template<class T>
 QueueLstPrT<T>::QueueLstPrT(const QueueLstPrT<T>& rhs)
{
     if (rhs.head_ != nullptr) {
         if (this != &rhs) {
             Node* newNode = new Node(rhs.head_->val);
             Node* cur = newNode;
             head_ = newNode;
             Node* current = rhs.head_->next;
             while (current != nullptr) {
                 Node* newNode = new Node(current->val);
                 current = current->next;
                 cur->next = newNode;
                 cur = newNode;
             }
         }
     }
     else {
         head_ = nullptr;
     }
}

template<class T>
 QueueLstPrT<T>::QueueLstPrT(QueueLstPrT<T>&& rhs) noexcept
{
     std::swap(head_, rhs.head_);
}

template<class T>
 QueueLstPrT<T>& QueueLstPrT<T>::operator=(const QueueLstPrT<T>& rhs)
{
     if (rhs.head_ == nullptr) {
         while (head_ != nullptr) {
             Pop();
         }
     }
     else {
         if (head_ == nullptr) {
             Node* new_node = new Node;
             head_ = new_node;
         }
         Node* cur = head_;
         Node* current = rhs.head_;
         Node* tm = nullptr;
         Node* tm2 = nullptr;
         while (current != nullptr) {
             cur->val = current->val;
             if (cur->next == nullptr && current->next != nullptr) {
                 Node* newNode = new Node;
                 cur->next = newNode;
             }
             current = current->next;
             if (current == nullptr) {
                 tm = cur->next;
                 cur->next = nullptr;

             }
             cur = cur->next;
         }
         while (tm != nullptr) {
             tm2 = tm;
             tm = tm->next;
             delete tm2;
         }
     }
     return *this;
}

template<class T>
QueueLstPrT<T>& QueueLstPrT<T>::operator=(QueueLstPrT<T>&& rhs) noexcept
{
     if (this != &rhs) {
         std::swap(head_, rhs.head_);
     }
     return *this;
}

template<class T>
 void QueueLstPrT<T>::Push(const T& rhs)
{
     Node* new_node = new Node(rhs);
     Node* cur = head_;
     Node* prev = nullptr;

     if (cur == nullptr) {
         head_ = new_node;
     }
     else {
         while (cur != nullptr) {
             if (rhs > cur->val) {
                 prev = cur;
                 if (cur->next == nullptr) {
                     cur->next = new_node;
                     break;
                 }
                 cur = cur->next;
             }
             else {
                 if (cur == head_) {
                     head_ = new_node;
                 }
                 else {
                     prev->next = new_node;
                 }
                 new_node->next = cur;
                 break;
             }
         }
     }
}

template<class T>
 void QueueLstPrT<T>::Pop()
{
     if (head_ != nullptr) {
         Node* tm = head_;
         head_ = tm->next;
         delete tm;
     }
}

template<class T>
 bool QueueLstPrT<T>::IsEmpty()
{
     return head_ == nullptr;
}

template<class T>
 T& QueueLstPrT<T>::Top()&
{
     if (!IsEmpty()) {
         return head_->val;
     }
     else {
         throw std::logic_error("QueueLstPr - try get top form empty queue.");
     }
}

template<class T>
 const T& QueueLstPrT<T>::Top() const&
{
     if (!IsEmpty()) {
         return head_->val;
     }
     else {
         throw std::logic_error("QueueLstPr - try get top form empty queue.");
     }
}

template<class T>
 void QueueLstPrT<T>::Clear() noexcept
{
     while (!IsEmpty()) {
         Pop();
     }
}
