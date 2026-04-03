#pragma once
#include <stdexcept>
#include <string>
#include <memory>
#include <utility>
#include <cstddef>

template <typename T>
class Stack {
private:
	std::unique_ptr<T[]> arr_;
	size_t size_;
	std::ptrdiff_t topIndex_;

	void resize() {
		size_t newSize = size_ * 2;
		auto newArray = std::make_unique<T[]>(newSize);

		for (std::ptrdiff_t i = 0; i <= topIndex_; ++i) {
			newArray[static_cast<size_t>(i)] = std::move(arr_[static_cast<size_t>(i)]);
		}

		arr_ = std::move(newArray);
		size_ = newSize;
	}

public:
    Stack() : arr_(std::make_unique<T[]>(10)), size_(10), topIndex_(-1) {}

	~Stack() = default;

    Stack(const Stack& other) : arr_(std::make_unique<T[]>(other.size_)), size_(other.size_), topIndex_(other.topIndex_) {
		for (std::ptrdiff_t i = 0; i <= topIndex_; ++i) {
			arr_[static_cast<size_t>(i)] = other.arr_[static_cast<size_t>(i)];
		}
	}

    Stack(Stack&& other) noexcept : arr_(std::move(other.arr_)), size_(other.size_), topIndex_(other.topIndex_) {
		other.size_ = 0;
		other.topIndex_ = -1;
	}

	Stack& operator=(Stack other) {
		std::swap(other);
		return *this;
	}

	void swap(Stack& other) noexcept {
		std::swap(arr_, other.arr_);
		std::swap(size_, other.size_);
		std::swap(topIndex_, other.topIndex_);
	}

	bool empty() const {
		return this->topIndex_ == -1;
	}

	void push(const T& value) {
		if (static_cast<size_t>(topIndex_ + 1) == size_) {
			resize();
		}

		arr_[static_cast<size_t>(++topIndex_)] = value;
	}

	void push(T&& value) {
		if (static_cast<size_t>(topIndex_ + 1) == size_) {
			resize();
		}

		arr_[static_cast<size_t>(++topIndex_)] = std::move(value);
	}

	template <typename... Args>
	void emplace(Args&&... args) {
		if (static_cast<size_t>(topIndex_ + 1) == size_) {
			resize();
		}

		arr_[static_cast<size_t>(++topIndex_)] = T(std::forward<Args>(args)...);
	}

	size_t size() const noexcept {
		return static_cast<size_t>(topIndex_ + 1);
	}

    void pop() {
		if (empty()) {
			throw std::out_of_range("Error: Stack is empty.");
		}

		--topIndex_;
	}

	T& peek() {
		if (empty()) {
			throw std::out_of_range("Error: Stack is empty.");
		}

		return arr_[static_cast<size_t>(topIndex_)];
	}

	const T& peek() const {
		if (empty()) {
			throw std::out_of_range("Error: Stack is empty.");
		}

		return arr_[static_cast<size_t>(topIndex_)];
	}

	friend std::ostream& operator<<(std::ostream& os, const Stack<T>& stack) {
		if (stack.empty()) {
			os << "[]";
			return os;
		}

		os << "[";
        for (std::ptrdiff_t i = 0; i <= stack.topIndex_; ++i) {
			os << stack.arr_[static_cast<size_t>(i)];

			if (i < stack.topIndex_) {
				os << ", ";
			}
		}
		os << "]";

		return os;
	}

	friend void swap(Stack& lhs, Stack& rhs) noexcept {
		lhs.swap(rhs);
	}

};