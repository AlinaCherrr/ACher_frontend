#include "queuelstpr.hpp"


QueueLstPr::~QueueLstPr()
{
    Node* tm = head_;
    while (tm != nullptr) {
        tm = head_->next;
        delete head_;
        head_ = tm;
    }
}

QueueLstPr::QueueLstPr(const QueueLstPr& rhs) 
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

QueueLstPr::QueueLstPr(QueueLstPr&& rhs) noexcept
{
    std::swap(head_, rhs.head_);
}

QueueLstPr& QueueLstPr::operator=(const QueueLstPr& rhs) {
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


QueueLstPr& QueueLstPr::operator=(QueueLstPr&& rhs) noexcept
{
    if (this != &rhs) {
        std::swap(head_, rhs.head_);
    }
    return *this;
}

void QueueLstPr::Push(const float& rhs)
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

void QueueLstPr::Pop()
{
    if (head_ != nullptr) {
        Node* tm = head_;
        head_ = tm->next;
        delete tm;
    }
}

float& QueueLstPr::Top() & {
    if (!IsEmpty()) {
        return head_->val;
    }
    else {
        throw std::logic_error("QueueLstPr - try get top form empty queue.");
    }
}


const float& QueueLstPr::Top() const & {
    if (head_ != nullptr) {
        return head_->val;
    }
    else {
        throw std::logic_error("QueueLstPr - try get top form empty queue.");
    }
}

void QueueLstPr::Clear() noexcept {
    while (!IsEmpty()) {
        Pop();
    }
}


bool QueueLstPr::IsEmpty()
{
    return head_ == nullptr;
}

