#include "pch.h"

#include <string>
#include <stdexcept>

#include "../Stack/Stack.hpp"

TEST(StackTest, BasicPushPop) {
    Stack<int> s;
    EXPECT_TRUE(s.empty()); 

    s.push(10);
    s.push(20);
    s.push(30);

    EXPECT_FALSE(s.empty());
    EXPECT_EQ(s.pop(), 30);
    EXPECT_EQ(s.pop(), 20);
    EXPECT_EQ(s.pop(), 10);
    EXPECT_TRUE(s.empty());
}

TEST(StackTest, PeekBehavior) {
    Stack<int> s;
    s.push(99);

    EXPECT_EQ(s.peek(), 99);
    EXPECT_FALSE(s.empty()); 

    s.pop();
    EXPECT_TRUE(s.empty());
}

TEST(StackTest, DynamicResizing) {
    Stack<int> s;

    for (int i = 1; i <= 100; i++) {
        s.push(i);
    }

    for (int i = 100; i >= 1; i--) {
        ASSERT_EQ(s.pop(), i);
    }

    EXPECT_TRUE(s.empty());
}

TEST(StackTest, ExceptionHandling) {
    Stack<int> s;

    EXPECT_THROW(s.pop(), std::out_of_range);
    EXPECT_THROW(s.peek(), std::out_of_range);
}

TEST(StackTest, StringTemplates) {
    Stack<std::string> s;
    s.push("String");
    s.push("testing");

    EXPECT_EQ(s.pop(), "testing");
    EXPECT_EQ(s.pop(), "String");
}