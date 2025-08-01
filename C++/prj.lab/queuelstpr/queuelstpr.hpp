#pragma once
#ifndef QUEUELSTPR_HPP 
#define QUEUELSTPR_HPP
#include <stdexcept>
#include <algorithm>
#include <cstddef>
#include <memory>
#include <iostream>

class QueueLstPr {
public:
    QueueLstPr() = default;
    ~QueueLstPr();
    QueueLstPr(const QueueLstPr& rhs);
    QueueLstPr(QueueLstPr&& rhs) noexcept;
    QueueLstPr& operator=(const QueueLstPr& rhs);
    QueueLstPr& operator=(QueueLstPr&& rhs) noexcept;

    void Push(const float& rhs);
    void Pop();
    [[nodiscard]] bool IsEmpty();
    [[nodiscard]] float& Top() &;
    [[nodiscard]] const float& Top() const &;
    void Clear() noexcept;

private:
    struct Node {
        float val = 0;
        Node* next = nullptr;
        Node() = default;
        Node(const float v) :val(v) {};
        ~Node() = default;
    };
    Node* head_ = nullptr;

};
#endif
