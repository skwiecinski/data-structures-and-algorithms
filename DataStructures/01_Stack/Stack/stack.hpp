#pragma once
#include <iostream>
#include <stdexcept>
#include <string>

template <typename T>
class Stack {
private:
	int size_;
	int topIndex_;
	T* arr_;

    void resize() {
		size_ *= 2;

		T* newArray = new T[size_];
		for (int i = 0; i <= topIndex_; i++) {
			newArray[i] = arr_[i];
		}

		delete[] arr_;
		arr_ = newArray;
	}

public:
	Stack(){
		size_ = 10;
		topIndex_ = -1;
		this->arr_ = new T[size_];
	}

	~Stack() {
		delete[] arr_;
	}

	bool empty() const {
		return this->topIndex_ == -1;
	}

    void push(const T& value) {
		if (topIndex_ == size_ - 1) {
			resize();
		}

		arr_[++topIndex_] = value;
	}

	int size() const {
		return (topIndex_ + 1);
	}

    T pop() {
		if (empty()) {
			throw std::out_of_range("Error: Stack is empty.");
		}

		T value = arr_[topIndex_];
		topIndex_--;
		return value;
	}

    const T& peek() const {
		if (empty()) {
			throw std::out_of_range("Error: Stack is empty.");
		}

		return arr_[topIndex_];
	}

	friend std::ostream& operator<<(std::ostream& os, const Stack<T>& stack) {
		if (stack.empty()) {
			os << "[]";
			return os;
		}

		os << "[";
		for (int i = 0; i <= stack.topIndex_; i++) {
			os << stack.arr_[i];

			if (i < stack.topIndex_) {
				os << ", ";
			}
		}
		os << "]";

        return os;
	}
};