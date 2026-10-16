#ifndef RING_BUFFER_LOGGER_HPP
#define RING_BUFFER_LOGGER_HPP

#include <vector>
#include <mutex>
#include <string>
#include <queue>
#include <atomic>

template <typename T>
class RingBuffer {
private:
    std::vector<T> buffer;
    size_t head;
    size_t tail;
    size_t max_size;
    bool full;
    std::mutex mtx;

public:
    explicit RingBuffer(size_t size) : buffer(size), head(0), tail(0), max_size(size), full(false) {}

    void put(const T& item) {
        std::lock_guard<std::mutex> lock(mtx);
        buffer[head] = item;
        if (full) {
            tail = (tail + 1) % max_size;
        }
        head = (head + 1) % max_size;
        full = (head == tail);
    }

    bool get(T& item) {
        std::lock_guard<std::mutex> lock(mtx);
        if (!full && head == tail) {
            return false;
        }
        item = buffer[tail];
        full = false;
        tail = (tail + 1) % max_size;
        return true;
    }

    bool empty() {
        std::lock_guard<std::mutex> lock(mtx);
        return (!full && (head == tail));
    }
};

class TelemetryLogger {
private:
    RingBuffer<std::string> log_queue;
    std::atomic<bool> running;

public:
    explicit TelemetryLogger(size_t capacity) : log_queue(capacity), running(true) {}

    void log(const std::string& message) {
        log_queue.put(message);
    }

    void stop() {
        running = false;
    }

    bool fetch(std::string& message) {
        return log_queue.get(message);
    }

    bool is_running() const {
        return running.load();
    }
};

#endif
