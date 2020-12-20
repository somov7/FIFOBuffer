#include <iostream>
#include "FIFOBufferList.hpp"
#include "FIFOBufferArray.hpp"

const int N = 10;

int main() {
	FIFOBufferList<int> bufferList(N);
	FIFOBufferArray<int> bufferArray(N);
	for (int i = 0; i < N + 1; i++) {
		bufferList.put(i);
		bufferArray.put(i);
	}
	for (int i = 0; i < N + 1; i++) {
		auto v = bufferList.get();
		if (v.has_value()) {
			std::cout << v.value() << std::endl;
		}
		else {
			std::cout << "Buffer is empty\n";
		}
	}
	for (int i = 0; i < N + 1; i++) {
		auto v = bufferArray.get();
		if (v.has_value()) {
			std::cout << v.value() << std::endl;
		}
		else {
			std::cout << "Buffer is empty\n";
		}
	}
	return 0;
}