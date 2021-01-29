#include <gtest/gtest.h>

#include "../Deque.h"

TEST(DequeTests, DefaultConstructorTest) {
  Deque d;
  EXPECT_TRUE(d.empty());
}

TEST(DequeTests, PushFrontTest) {
  Deque d;
  int size_before = d.size();

  d.push_front(12);

  ASSERT_EQ(d.front(), 12);
  ASSERT_EQ(d.size(), size_before + 1);
}

TEST(DequeTests, PushBackTest) {
  Deque d;
  int size_before = d.size();

  d.push_front(12);

  ASSERT_EQ(d.back(), 12);
  ASSERT_EQ(d.size(), size_before + 1);
}

TEST(DequeTests, PopFrontTest) {
  Deque d;
  int size_before = d.size();

  d.push_front(12);
  d.pop_front();

  ASSERT_EQ(d.size(), size_before);
}

TEST(DequeTests, PopBackTest) {
  Deque d;
  int size_before = d.size();

  d.push_back(12);
  d.pop_back();

  ASSERT_EQ(d.size(), size_before);
}

TEST(DequeTests, IndexReturnTest) {
  Deque d;

  d.push_front(12);

  ASSERT_EQ(d.front(), d.at(0));
}

TEST(DequeTests, CapacityReserveTest) {
  Deque d;

  int capacity_before = d.capacity();

  d.reserve(2 * d.capacity());

  ASSERT_EQ(d.capacity(), 2 * capacity_before);
}

TEST(DequeTests, SizeChangeTest) {
  Deque d;

  int size_before = d.size();

  d.push_front(5);

  ASSERT_EQ(d.size(), size_before + 1);
}

TEST(DequeTests, FrontElementTest) {
  Deque d;

  d.push_back(4);
  d.push_front(5);

  ASSERT_EQ(d.front(), d.at(0));
}

TEST(DequeTests, BackElementTest) {
  Deque d;

  d.push_back(4);
  d.push_front(5);

  ASSERT_EQ(d.back(), d.at(1));
}