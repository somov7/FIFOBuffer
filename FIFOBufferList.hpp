#pragma once

#include <optional>
#include <memory>

template <typename T>
class FIFOBufferList {
private:
	size_t size, maxSize;
	class ListNode {
	public:
		T value;
		std::shared_ptr<ListNode> next;
		ListNode(T value) :
			value(value), next(nullptr) {}
	};
	std::shared_ptr<ListNode> head, tail;
public:
	FIFOBufferList(size_t maxSize) : size(0), maxSize(maxSize), head(nullptr), tail(nullptr) {}
	bool empty() {
		return size == 0;
	}
	void put(T value) {
		std::shared_ptr<ListNode> node = std::make_shared<ListNode>(value);
		if (size == 0) {
			head = tail = node;
			size++;
		}
		else {
			tail->next = node;
			tail = tail->next;
			if (size == maxSize) {
				head = head->next;
			}
			else {
				size++;
			}
		}
	}
	std::optional<T> get() {
		if (empty()) {
			return std::nullopt;
		}
		T value = head->value;
		head = head->next;
		size--;
		return value;
	}
};