#include<vector>
#include<iostream>
#include<cassert>
using namespace std;

class MaxHeap {
private:
	int capacity {1000};
	int *array{};
	int size {};

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
		if (child_pos == 0 || array[par_pos] > array[child_pos])
			return;

		swap(array[child_pos], array[par_pos]);
		heapify_up(par_pos);
	}

	void heapify_down(int parent_pos) {	// O(logn)
		int child_pos = left(parent_pos);
		int right_child = right(parent_pos);

		if (child_pos == -1) // no children
			return;
		// is right bigger than left?
		if (right_child != -1 && array[right_child] > array[child_pos])
			child_pos = right_child;

		if (array[parent_pos] < array[child_pos]) {
			swap(array[parent_pos], array[child_pos]);
			heapify_down(child_pos);
		}
	}

	void heapify() {	// O(n)
		for (int i = size / 2 - 1; i >= 0; --i)
			heapify_down(i);
	}
public:

	MaxHeap() {
		array = new int[capacity] { };
		size = 0;
	}

	MaxHeap(const vector<int> &v) {
		assert((int )v.size() <= capacity);
		array = new int[capacity] { };
		size = v.size();

		for (int i = 0; i < (int) v.size(); ++i)
			array[i] = v[i];

		heapify();
	}

	~MaxHeap() {
		delete [] array;
		array = nullptr;
	}

	int top() {
		assert(!isempty());
		return array[0];
	}

	void push(int key) {
		assert(size + 1 <= capacity);
		array[size++] = key;
		heapify_up(size - 1);
	}

	void pop() {
		assert(!isempty());
		array[0] = array[--size];
		heapify_down(0);
	}

	bool isempty() {
		return size == 0;
	}

	int sz() {
		return size;
	}
};

class KthNumberProcessor {
private:
	int k;
	MaxHeap q;

public:
	KthNumberProcessor(int k): k(k){
	}

	int next(int new_num) {

		if(q.sz() < k)
			q.push(new_num);
		else if (new_num < q.top()) {
			q.pop();
			q.push(new_num);
		}
		return q.top();
	}
};

int main() {
	KthNumberProcessor processor(4);

	int num;
	while (cin >> num)
		cout << processor.next(num) << "\n";

	return 0;
}
