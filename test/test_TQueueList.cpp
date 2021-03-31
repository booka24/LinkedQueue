#include "Queue.h"
#include <gtest.h>
#include <iostream>
TEST(linkedQueue, can_create_linkedQueue)
{
	ASSERT_NO_THROW(linkedQueue<int> qe);
}

TEST(linkedQueue, create_empty_QueueList)
{
	linkedQueue<int> qe;

	EXPECT_EQ(true, qe.isEmpty());
}

TEST(linkedQueue, can_push)
{
	linkedQueue<int> qe;

	ASSERT_NO_THROW(qe.enqueue(3));
}

TEST(linkedQueue, can_get_elem)
{
	linkedQueue<int> qe;
	qe.enqueue(4);
	qe.enqueue(2);
	qe.enqueue(1);

	EXPECT_EQ(4, qe.front());
}

TEST(linkedQueue, cant_get_if_empty)
{
	linkedQueue<int> qe;

	ASSERT_ANY_THROW(qe.front());
}

TEST(linkedQueue, can_copy_linkedQueue)
{
	linkedQueue<int> qe1;
	qe1.enqueue(1);
	ASSERT_NO_THROW(linkedQueue<int> qe2(qe1));
}

TEST(linkedQueue, can_assing_linkedQueue)
{
	linkedQueue<int> qe1;
	qe1.enqueue(1);

	linkedQueue<int> qe2;
	qe2 = qe1;

	EXPECT_EQ(1, qe2.front());
}

TEST(linkedQueue, can_get_count)
{
	linkedQueue<int> qe;
	qe.enqueue(1);
	qe.enqueue(2);
	EXPECT_EQ(2, qe.GetLength());
}

TEST(TQueueList, DOP_can_get_max_elem_DOP)
{
	linkedQueue<int> qe;
	qe.enqueue(1);
	qe.enqueue(2);
	qe.enqueue(5);
	qe.enqueue(134);
	qe.enqueue(0);
	qe.enqueue(2);
	EXPECT_EQ(134, qe.get_max());
}

TEST(TQueueList, DOP_can_get_min_elem_DOP)
{
	linkedQueue<int> qe;
	qe.enqueue(1);
	qe.enqueue(2);
	qe.enqueue(5);
	qe.enqueue(134);
	qe.enqueue(3);
	qe.enqueue(2);
	EXPECT_EQ(1, qe.get_min());
}

TEST(linkedQueue, Can_clear_queue) {
	linkedQueue<int> qe;
	qe.enqueue(5);
	qe.enqueue(4);
	qe.clearQueue();
	EXPECT_EQ(true, qe.isEmpty());
}

TEST(linkedQueue, can_find_elem_in_linkedQueue) {
	linkedQueue<int> qe;
	qe.enqueue(1);
	qe.enqueue(2);
	qe.enqueue(5);
	qe.enqueue(134);
	qe.enqueue(3);
	qe.enqueue(2);
	EXPECT_EQ(true, qe.search(134));
}
