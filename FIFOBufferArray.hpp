#pragma once

#include <optional>
#include <memory>

template <typename T>
class FIFOBufferArray {
private:
	size_t head, tail, size, maxSize;
	std::unique_ptr<T[]> data;
public:
	FIFOBufferArray(size_t maxSize) :
		head(0), tail(0), size(0), maxSize(maxSize), data(std::make_unique<T[]>(size)) {}
	bool empty() {
		return size == 0;
	}
	void put(T value) {
		data[tail] = value;
		tail = (tail + 1) % maxSize;
		if (size == maxSize) {
			head = (head + 1) % maxSize;
		}
		else {
			size++;
		}
	}
	std::optional<T> get() {
		if (empty()) {
			return std::nullopt;
		}
		T value = data[head];
		head = (head + 1) % maxSize;
		size--;
		return value;
	}
};