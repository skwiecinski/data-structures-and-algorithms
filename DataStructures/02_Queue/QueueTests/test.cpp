#include "pch.h"

#include "../Queue/queue.hpp"

TEST(QueueTest, BasicOperations) {
    Queue<int> q(5);
    q.push(10);
    q.push(20);

    EXPECT_EQ(q.size(), 2);
    EXPECT_EQ(q.front(), 10);
    q.pop();
    EXPECT_EQ(q.front(), 20);
    EXPECT_EQ(q.size(), 1);
}

TEST(QueueTest, CircularBehavior) {
    Queue<int> q(3);
    q.push(1);
    q.push(2);
    q.push(3); 

    q.pop(); 
    q.push(4);

    EXPECT_EQ(q.front(), 2);
    EXPECT_EQ(q.back(), 4);
    EXPECT_EQ(q.size(), 3);
}

TEST(QueueTest, AutoResize) {
    Queue<int> q(2);
    q.push(1);
    q.push(2);
    EXPECT_NO_THROW(q.push(3)); 

    EXPECT_EQ(q.size(), 3);
    EXPECT_GE(q.capacity(), 4);
    EXPECT_EQ(q.front(), 1);
}

TEST(QueueTest, CopyConstructor) {
    Queue<std::string> q1;
    q1.push("A");
    q1.push("B");

    Queue<std::string> q2 = q1; 
    q1.pop();

    EXPECT_EQ(q2.size(), 2);
    EXPECT_EQ(q2.front(), "A");
    EXPECT_EQ(q1.front(), "B"); 
}

TEST(QueueTest, MoveSemantics) {
    Queue<int> q1;
    q1.push(100);

    Queue<int> q2 = std::move(q1); 

    EXPECT_EQ(q2.front(), 100);
    EXPECT_TRUE(q1.empty());
}

TEST(QueueTest, ExceptionHandling) {
    Queue<int> q;
    EXPECT_THROW(q.pop(), std::out_of_range);
    EXPECT_THROW(q.front(), std::out_of_range);
}

TEST(QueueTest, EmplaceTest) {
    struct Point {
        int x, y;
        Point(int x = 0, int y = 0) : x(x), y(y) {}
        bool operator==(const Point& other) const { return x == other.x && y == other.y; }
    };

    Queue<Point> q;
    q.emplace(10, 20); 

    EXPECT_EQ(q.front().x, 10);
    EXPECT_EQ(q.front().y, 20);
}