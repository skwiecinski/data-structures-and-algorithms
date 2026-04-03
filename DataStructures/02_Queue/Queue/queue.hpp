#pragma once
#include <string>
#include <stdexcept>
#include <initializer_list>
#include <utility>
#include <algorithm>
#include <memory> 

template <typename T>
class Queue {
private:
    std::unique_ptr<T[]> arr_; 
    size_t count_;             
    size_t capacity_;
    size_t front_;
    size_t back_;

public:
    explicit Queue(size_t initial_capacity = 10)
        : arr_(std::make_unique<T[]>(initial_capacity)),
        count_(0),
        capacity_(initial_capacity),
        front_(0),
        back_(initial_capacity - 1) {}

    Queue(const Queue& other)
        : arr_(std::make_unique<T[]>(other.capacity_)),
        count_(other.count_),
        capacity_(other.capacity_),
        front_(0),
        back_(other.count_ > 0 ? other.count_ - 1 : other.capacity_ - 1) {
        for (size_t i = 0; i < count_; ++i) {
            arr_[i] = other.arr_[(other.front_ + i) % other.capacity_];
        }
    }

    Queue(Queue&& other) noexcept
        : arr_(nullptr), count_(0), capacity_(0), front_(0), back_(0) {
        swap(other);
    }

    Queue& operator=(Queue other) { 
        swap(other);
        return *this;
    }

    void swap(Queue& other) noexcept {
        using std::swap;
        swap(arr_, other.arr_);
        swap(count_, other.count_);
        swap(capacity_, other.capacity_);
        swap(front_, other.front_);
        swap(back_, other.back_);
    }

    T& front() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        } 
        return arr_[front_];
    }

    const T& front() const {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        } 
        return arr_[front_];
    }

    T& back() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return arr_[back_];
    }

    const T& back() const {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return arr_[back_];
    }

    void pop() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        front_ = (front_ + 1) % capacity_;
        count_--;
    }

    void push(const T& value) {
        if (count_ == capacity_) {
            resize(capacity_ * 2);
        }
        back_ = (back_ + 1) % capacity_;
        arr_[back_] = value;
        count_++;
    }

    template <typename... Args>
    void emplace(Args&&... args) {
        if (count_ == capacity_) {
            resize(capacity_ * 2);
        }
        back_ = (back_ + 1) % capacity_;
        arr_[back_] = T(std::forward<Args>(args)...);
        count_++;
    }

    void clear() noexcept {
        count_ = 0;
        front_ = 0;
        back_ = capacity_ - 1;
    }

    size_t size() const noexcept { return count_; }
    size_t capacity() const noexcept { return capacity_; }
    bool empty() const noexcept { return count_ == 0; }

    void resize(size_t new_capacity) {
        if (new_capacity < count_) {
            new_capacity = count_;
        }
        auto new_arr = std::make_unique<T[]>(new_capacity);

        for (size_t i = 0; i < count_; ++i) {
            new_arr[i] = std::move(arr_[(front_ + i) % capacity_]);
        }

        arr_ = std::move(new_arr);
        capacity_ = new_capacity;
        front_ = 0;
        back_ = (count_ == 0) ? capacity_ - 1 : count_ - 1;
    }

    bool operator==(const Queue& other) const {
        if (count_ != other.count_) {
            return false;
        }
        for (size_t i = 0; i < count_; ++i) {
            if (!(arr_[(front_ + i) % capacity_] == other.arr_[(other.front_ + i) % other.capacity_])) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Queue& other) const { return !(*this == other); }

    friend std::ostream& operator<<(std::ostream& os, const Queue& q) {
        os << "[";
        for (size_t i = 0; i < q.count_; ++i) {
            os << q.arr_[(q.front_ + i) % q.capacity_];
            if (i < q.count_ - 1) {
                os << ", ";
            }
        }
        return os << "]";
    }
};

template <typename T>
void swap(Queue<T>& lhs, Queue<T>& rhs) noexcept {
    lhs.swap(rhs);
}