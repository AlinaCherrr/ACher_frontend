#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include <queuelstpr/queuelstpr.hpp>

TEST_CASE("queuelstpr ctor") {
    QueueLstPr q;
    CHECK_EQ(1, q.IsEmpty());

    float a1 = 12.3;
    float a2 = 24.99;
    float a3 = 1.5;
    float a4 = 13.01;

    q.Push(a1);
    CHECK_EQ(0, q.IsEmpty());
    CHECK_EQ(a1, q.Top());

    q.Push(a2);
    CHECK_EQ(a1, q.Top());

    q.Push(a3);
    CHECK_EQ(a3, q.Top());

    q.Push(a4);
    CHECK_EQ(a3, q.Top());

    q.Pop();
    CHECK_EQ(a1, q.Top());

    q.Clear();
    CHECK_EQ(1, q.IsEmpty());

    QueueLstPr q2;
    CHECK_EQ(1, q2.IsEmpty());

    q2 = q;
    CHECK_EQ(1, q2.IsEmpty());

    q.Push(a1);
    q.Push(a2);

    q2 = q;
    CHECK_EQ(0, q2.IsEmpty());
    CHECK_EQ(a1, q2.Top());

    q2.Push(a3);
    q2.Push(a3);
    q2.Push(a3);
    q2.Push(a3);
    CHECK_EQ(a3, q2.Top());

    q = q2;
    CHECK_EQ(0, q.IsEmpty());
    CHECK_EQ(a3, q.Top());

    q2.Pop();
    q2.Pop();
    q2.Pop();

    q = q2;

    float c1 = 1.2;
    float c2 = 1.7;
    float c3 = 1.8;
    float c4 = 1.9;

    QueueLstPr queue;
    QueueLstPr queue4;

    queue4.Push(c4);
    CHECK_EQ(0, queue4.IsEmpty());
    CHECK_EQ(c4, queue4.Top());

    CHECK_EQ(1, queue.IsEmpty());
    CHECK_THROWS(queue.Top());
    queue.Pop();
    CHECK_EQ(1, queue.IsEmpty());

    queue.Push(c1);
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c1, queue.Top());

    queue4 = queue;
    CHECK_EQ(0, queue4.IsEmpty());
    CHECK_EQ(c1, queue4.Top());

    queue.Push(c2);
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c1, queue.Top());

    queue4 = queue;
    CHECK_EQ(0, queue4.IsEmpty());
    CHECK_EQ(c1, queue4.Top());

    queue4.Pop();
    CHECK_EQ(0, queue4.IsEmpty());
    CHECK_EQ(c2, queue4.Top());

    queue.Push(c3);
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c1, queue.Top());

    queue.Push(c4);
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c1, queue.Top());

    QueueLstPr copu_queue_1(queue);
    QueueLstPr queue2 = queue;
    queue4 = queue;

    queue.Pop();
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c2, queue.Top());

    queue.Pop();
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c3, queue.Top());

    queue.Pop();
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c4, queue.Top());

    queue.Pop();
    CHECK_EQ(1, queue.IsEmpty());
    CHECK_THROWS(queue.Top());

    queue.Push(c1);
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c1, queue.Top());

    queue.Push(c2);
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c1, queue.Top());

    queue.Clear();
    CHECK_EQ(1, queue.IsEmpty());
    CHECK_THROWS(queue.Top());

    QueueLstPr copu_queue_2(queue);
    QueueLstPr queue3 = queue;

    queue.Push(c1);
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c1, queue.Top());

    queue.Push(c2);
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c1, queue.Top());


    SUBCASE("copu_queue_1") {
        CHECK_EQ(0, copu_queue_1.IsEmpty());
        CHECK_EQ(c1, copu_queue_1.Top());

        copu_queue_1.Pop();
        CHECK_EQ(0, copu_queue_1.IsEmpty());
        CHECK_EQ(c2, copu_queue_1.Top());

        copu_queue_1.Pop();
        CHECK_EQ(0, copu_queue_1.IsEmpty());
        CHECK_EQ(c3, copu_queue_1.Top());

        copu_queue_1.Pop();
        CHECK_EQ(0, copu_queue_1.IsEmpty());
        CHECK_EQ(c4, copu_queue_1.Top());

        copu_queue_1.Pop();
        CHECK_EQ(1, copu_queue_1.IsEmpty());
        CHECK_THROWS(copu_queue_1.Top());

        copu_queue_1.Push(c1);
        CHECK_EQ(0, copu_queue_1.IsEmpty());
        CHECK_EQ(c1, copu_queue_1.Top());

        copu_queue_1.Push(c2);
        CHECK_EQ(0, copu_queue_1.IsEmpty());
        CHECK_EQ(c1, copu_queue_1.Top());

        copu_queue_1.Clear();
        CHECK_EQ(1, copu_queue_1.IsEmpty());
        CHECK_THROWS(copu_queue_1.Top());

        copu_queue_1.Push(c1);
        CHECK_EQ(0, copu_queue_1.IsEmpty());
        CHECK_EQ(c1, copu_queue_1.Top());

        copu_queue_1.Push(c2);
        CHECK_EQ(0, copu_queue_1.IsEmpty());
        CHECK_EQ(c1, copu_queue_1.Top());
    }

    SUBCASE("copu_queue_2") {
        CHECK_EQ(1, copu_queue_2.IsEmpty());
        CHECK_THROWS(copu_queue_2.Top());
        copu_queue_2.Pop();
        CHECK_EQ(1, copu_queue_2.IsEmpty());

        copu_queue_2.Push(c1);
        CHECK_EQ(0, copu_queue_2.IsEmpty());
        CHECK_EQ(c1, copu_queue_2.Top());

        copu_queue_2.Push(c2);
        CHECK_EQ(0, copu_queue_2.IsEmpty());
        CHECK_EQ(c1, copu_queue_2.Top());

        copu_queue_2.Push(c3);
        CHECK_EQ(0, copu_queue_2.IsEmpty());
        CHECK_EQ(c1, copu_queue_2.Top());

        copu_queue_2.Push(c4);
        CHECK_EQ(0, copu_queue_2.IsEmpty());
        CHECK_EQ(c1, copu_queue_2.Top());

        copu_queue_2.Pop();
        CHECK_EQ(0, copu_queue_2.IsEmpty());
        CHECK_EQ(c2, copu_queue_2.Top());

        copu_queue_2.Pop();
        CHECK_EQ(0, copu_queue_2.IsEmpty());
        CHECK_EQ(c3, copu_queue_2.Top());

        copu_queue_2.Pop();
        CHECK_EQ(0, copu_queue_2.IsEmpty());
        CHECK_EQ(c4, copu_queue_2.Top());

        copu_queue_2.Pop();
        CHECK_EQ(1, copu_queue_2.IsEmpty());
        CHECK_THROWS(copu_queue_2.Top());

        copu_queue_2.Push(c1);
        CHECK_EQ(0, copu_queue_2.IsEmpty());
        CHECK_EQ(c1, copu_queue_2.Top());

        copu_queue_2.Push(c2);
        CHECK_EQ(0, copu_queue_2.IsEmpty());
        CHECK_EQ(c1, copu_queue_2.Top());

        copu_queue_2.Clear();
        CHECK_EQ(1, copu_queue_2.IsEmpty());
        CHECK_THROWS(copu_queue_2.Top());

        copu_queue_2.Push(c1);
        CHECK_EQ(0, copu_queue_2.IsEmpty());
        CHECK_EQ(c1, copu_queue_2.Top());

        copu_queue_2.Push(c2);
        CHECK_EQ(0, copu_queue_2.IsEmpty());
        CHECK_EQ(c1, copu_queue_2.Top());
    }

    SUBCASE("queue2") {
        CHECK_EQ(0, queue2.IsEmpty());
        CHECK_EQ(c1, queue2.Top());

        queue2.Pop();
        CHECK_EQ(0, queue2.IsEmpty());
        CHECK_EQ(c2, queue2.Top());

        queue2.Pop();
        CHECK_EQ(0, queue2.IsEmpty());
        CHECK_EQ(c3, queue2.Top());

        queue2.Pop();
        CHECK_EQ(0, queue2.IsEmpty());
        CHECK_EQ(c4, queue2.Top());

        queue2.Pop();
        CHECK_EQ(1, queue2.IsEmpty());
        CHECK_THROWS(queue2.Top());

        queue2.Push(c1);
        CHECK_EQ(0, queue2.IsEmpty());
        CHECK_EQ(c1, queue2.Top());

        queue2.Push(c2);
        CHECK_EQ(0, queue2.IsEmpty());
        CHECK_EQ(c1, queue2.Top());

        queue2.Clear();
        CHECK_EQ(1, queue2.IsEmpty());
        CHECK_THROWS(queue2.Top());

        queue2.Push(c1);
        CHECK_EQ(0, queue2.IsEmpty());
        CHECK_EQ(c1, queue2.Top());

        queue2.Push(c2);
        CHECK_EQ(0, queue2.IsEmpty());
        CHECK_EQ(c1, queue2.Top());

        queue2.Pop();
        CHECK_EQ(0, queue2.IsEmpty());
        CHECK_EQ(c2, queue2.Top());
    }

    CHECK_EQ(1, queue3.IsEmpty());
    CHECK_THROWS(queue3.Top());
    queue3.Pop();
    CHECK_EQ(1, queue3.IsEmpty());

    queue3.Push(c1);
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c1, queue3.Top());

    queue3.Push(c2);
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c1, queue3.Top());

    queue3.Push(c3);
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c1, queue3.Top());

    queue3.Push(c4);
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c1, queue3.Top());

    queue3.Pop();
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c2, queue3.Top());

    queue3.Pop();
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c3, queue3.Top());

    queue3.Pop();
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c4, queue3.Top());

    queue3.Pop();
    CHECK_EQ(1, queue3.IsEmpty());
    CHECK_THROWS(queue3.Top());

    queue3.Push(c1);
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c1, queue3.Top());

    queue3.Push(c2);
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c1, queue3.Top());

    queue3.Clear();
    CHECK_EQ(1, queue3.IsEmpty());
    CHECK_THROWS(queue3.Top());

    queue3.Push(c1);
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c1, queue3.Top());

    queue3.Push(c2);
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c1, queue3.Top());

    CHECK_EQ(0, queue4.IsEmpty());
    CHECK_EQ(c1, queue4.Top());

    queue4.Pop();
    CHECK_EQ(0, queue4.IsEmpty());
    CHECK_EQ(c2, queue4.Top());

    queue4.Pop();
    CHECK_EQ(0, queue4.IsEmpty());
    CHECK_EQ(c3, queue4.Top());

    queue4.Pop();
    CHECK_EQ(0, queue4.IsEmpty());
    CHECK_EQ(c4, queue4.Top());

    queue4.Pop();
    CHECK_EQ(1, queue4.IsEmpty());
    CHECK_THROWS(queue4.Top());

    queue4.Push(c1);
    CHECK_EQ(0, queue4.IsEmpty());
    CHECK_EQ(c1, queue4.Top());

    queue4.Push(c2);
    CHECK_EQ(0, queue4.IsEmpty());
    CHECK_EQ(c1, queue4.Top());

    queue4.Clear();
    CHECK_EQ(1, queue4.IsEmpty());
    CHECK_THROWS(queue4.Top());

    queue4.Push(c1);
    CHECK_EQ(0, queue4.IsEmpty());
    CHECK_EQ(c1, queue4.Top());

    queue4.Push(c2);
    CHECK_EQ(0, queue4.IsEmpty());
    CHECK_EQ(c1, queue4.Top());

    queue4.Push(c3);
    queue4.Push(c4);
    CHECK_EQ(0, queue4.IsEmpty());
    CHECK_EQ(c1, queue4.Top());

    queue4 = queue3;
    CHECK_EQ(0, queue4.IsEmpty());
    CHECK_EQ(c1, queue4.Top());

    queue4.Pop();
    CHECK_EQ(0, queue4.IsEmpty());
    CHECK_EQ(c2, queue4.Top());




}
