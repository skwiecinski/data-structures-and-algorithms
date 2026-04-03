#include "pch.h"
#include <string>
#include <stdexcept>
#include "../Stack/Stack.hpp"

template <typename T>
T getAndPop(Stack<T>& s) {
    T val = s.peek();
    s.pop();
    return val;
}

TEST(StackTest, BasicPushPop) {
    Stack<int> s;
    EXPECT_TRUE(s.empty());

    s.push(10);
    s.push(20);
    s.push(30);

    EXPECT_FALSE(s.empty());

    EXPECT_EQ(s.peek(), 30);
    s.pop();

    EXPECT_EQ(s.peek(), 20);
    s.pop();

    EXPECT_EQ(s.peek(), 10);
    s.pop();

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

    EXPECT_EQ(s.size(), 100);

    for (int i = 100; i >= 1; i--) {
        ASSERT_EQ(s.peek(), i);
        s.pop();
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

    EXPECT_EQ(s.peek(), "testing");
    s.pop();
    EXPECT_EQ(s.peek(), "String");
    s.pop();
}

TEST(StackTest, CopyConstructor) {
    Stack<int> s1;
    s1.push(1);
    s1.push(2);

    Stack<int> s2 = s1; 

    s1.pop();

    EXPECT_EQ(s2.size(), 2); 
    EXPECT_EQ(s2.peek(), 2);
}

TEST(StackTest, EmplaceBehavior) {
    Stack<std::string> s;
    s.emplace(5, 'A'); 

    EXPECT_EQ(s.peek(), "AAAAA");
}