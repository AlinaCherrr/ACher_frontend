#include "stacklst/stacklst.hpp"
#include <memory>

StackLst::StackLst(const StackLst& rhs) {
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

StackLst::StackLst(StackLst&& rhs) noexcept
{
    std::swap(head_, rhs.head_);
}

StackLst& StackLst::operator=(StackLst&& rhs) noexcept
{
    if (this != &rhs) {
        std::swap(head_, rhs.head_);
    }
    return *this;
}

StackLst::~StackLst() {
    while (head_ != nullptr) {
        Node* temp = head_;
        head_ = head_->next;
        delete temp;
        temp = nullptr;
    }
    
}


StackLst& StackLst::operator=(const StackLst& rhs) noexcept {
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


void StackLst::Push(const Complex& rhs) noexcept {
    Node* newNode = new Node(rhs);
    newNode->next = head_;
    head_ = newNode;
    newNode = nullptr;
}

void StackLst::Pop() noexcept {
    if (head_ != nullptr) {
        Node* temp = head_;
        head_ = temp->next;
        delete temp;
        temp = nullptr;
    }
}


bool StackLst::IsEmpty() const noexcept {
    return head_ == nullptr;
}


Complex& StackLst::Top() & {
    if (!IsEmpty()) {
        return head_->val;
    }
    else {
        throw std::logic_error("StackLst - try get top form empty stack.");
    }
}


const Complex& StackLst::Top() const &{
    if (!IsEmpty()) {
        return head_->val;
    }
    else {
        throw std::logic_error("StackLst - try get top form empty stack.");
    }
}

void StackLst::Clear() noexcept {
    while (!IsEmpty()) {
        Pop();
    }
}