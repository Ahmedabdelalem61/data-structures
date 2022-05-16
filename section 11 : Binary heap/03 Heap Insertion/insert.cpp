#include<vector>
#include<iostream>
#include<cassert>
using namespace std;

class MinHeap {
private:
	int *array { };
	int size { };
	int capacity { 1000 };

	int left(int node) {
		int p = 2 * node + 1;
		if (p >= size)
			return -1;
		return p;
	}
	int right(int node) {
		int p = 2 * node + 2;
		return p >= size ? -1 : p;
	}
	int parent(int node) {
		return node == 0 ? -1 : (node - 1) / 2;
	}

	void heapify_up(int child_pos) {
		// stop when parent is smaller (or no parent)
		int par_pos = parent(child_pos);
		if (child_pos == 0 || array[par_pos] < array[child_pos])
			return;

		swap(array[child_pos], array[par_pos]);
		heapify_up(par_pos);
	}

public:
	MinHeap() {
		array = new int[capacity] { };
		size = 0;
	}

	~MinHeap() {
		delete[] array;
		array = nullptr;
	}

	void push(int key) {
		assert(size + 1 <= capacity);
		array[size++] = key;
		heapify_up(size - 1);
	}

	int top() {
		assert(!isempty());
		return array[0];
	}

	bool isempty() {
		return size == 0;
	}
};

int main() {
	MinHeap heap;
	vector<int> v { 2, 17, 22, 10, 8, 37, 14, 19, 7, 6, 5, 12, 25, 30 };

	for (int i = 0; i < v.size(); ++i)
		heap.push(v[i]);

	return 0;

}
