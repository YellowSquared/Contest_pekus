
#include <cstddef>
#include <iostream>

class RingBuffer {
private:
    size_t capacity_;
    size_t size_;
    int* data_;
    int64_t end_;
    int64_t start_;

public:
    explicit RingBuffer(size_t capacity) {
        capacity_ = capacity;
        size_ = 0;
        data_ = new int[capacity_];
        end_ = 0;
        start_ = -1;
    }

    ~RingBuffer() {
        delete[] data_;
    }

    size_t Size() const {
        return size_;
    }

    bool Empty() const {
        return size_ == 0;
    }

    bool TryPush(int element) {
        if (!(size_ == capacity_)) {
            start_ = (start_ + 1) % capacity_;
            data_[start_] = element;
            size_++;
            return true;
        }
        return false;
    }

    bool TryPop(int* element) {
        if (!Empty()) {
            *element = data_[end_];
            end_ = (end_ + 1) % capacity_;
            size_--;
            return true;
        }
        return false;
    }
};

int main() {
    RingBuffer ringbuffer(3);
    ringbuffer.TryPush(3);
    ringbuffer.TryPush(2);

    int res = 0;
    ringbuffer.TryPop(&res);
    std::cout << res << "\n";
    ringbuffer.TryPop(&res);
    std::cout << res << "\n";

    ringbuffer.TryPush(2);
    ringbuffer.TryPush(3);

    ringbuffer.TryPop(&res);
    std::cout << res << "\n";
    ringbuffer.TryPop(&res);
    std::cout << res << "\n";
}