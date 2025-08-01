#include <queuelstprt/queuelstprt.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "unittest.hpp"
#include <cstdint>

#define TYPES int, double, std::string

TEST_CASE_TEMPLATE_DEFINE("queuelstprt", T, queuelstprt) {

    std::vector<T> data;
    FillData(8, data);
    T a3 = data[0];
    T a1 = data[1];
    T a4 = data[2];
    T a2 = data[3];

    QueueLstPrT<T> q;
    CHECK_EQ(1, q.IsEmpty());

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

    QueueLstPrT<T> q2;
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

    T c1 = data[4];
    T c2 = data[5];
    T c3 = data[6];
    T c4 = data[7];

    QueueLstPrT<T> queue;
    QueueLstPrT<T> queue4;

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

    QueueLstPrT<T> copu_queue_1(queue);
    QueueLstPrT<T> queue2 = queue;
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

    QueueLstPrT<T> copu_queue_2(queue);
    QueueLstPrT<T> queue3 = queue;

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


TEST_CASE_TEMPLATE_INVOKE(queuelstprt, TYPES);
