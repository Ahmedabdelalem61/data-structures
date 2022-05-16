#include<vector>
#include<iostream>
#include<cassert>
using namespace std;

class MinHeap {
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
		if (child_pos == 0 || array[par_pos] < array[child_pos])
			return;

		swap(array[child_pos], array[par_pos]);
		heapify_up(par_pos);
	}

	void heapify() {	// O(n)
		for (int i = size / 2 - 1; i >= 0; --i)
			heapify_down(i);

		assert(is_heap(0));
	}

	void heapify_down(int parent_pos) {	// O(logn)
		int child_pos = left(parent_pos);
		int right_child = right(parent_pos);

		if (child_pos == -1) // no children
			return;
		// is right smaller than left?
		if (right_child != -1 && array[right_child] < array[child_pos])
			child_pos = right_child;

		if (array[parent_pos] > array[child_pos]) {
			swap(array[parent_pos], array[child_pos]);
			heapify_down(child_pos);
		}
	}

	bool is_heap(int parent_pos) {	// O(n)
		if (parent_pos == -1)
			return true;

		int left_child = left(parent_pos);
		int right_child = right(parent_pos);

		if (left_child != -1 && array[parent_pos] > array[left_child])
			return false;

		if (right_child != -1 && array[parent_pos] > array[right_child])
			return false;

		return is_heap(left_child) && is_heap(right_child);

		// Tip we can optimize by stopping with the first leaf node
	}

public:
	MinHeap() {
		array = new int[capacity] { };
		size = 0;
	}

	MinHeap(const vector<int> &v) {
		assert((int )v.size() <= capacity);
		array = new int[capacity] { };
		size = v.size();

		for (int i = 0; i < (int) v.size(); ++i)
			array[i] = v[i];

		heapify();

		for (int i = 0; i < (int) v.size(); ++i)
			cout<<array[i]<<" ";
		cout<<"\n";
	}

	~MinHeap() {
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

	bool is_heap_array(int *p, int n) {
		// Take our data copy. Replace. Use. Return data
		int* old_arr = array;
		int old_size = size;

		array = p;
		size = n;

		bool result = is_heap(0);

		size = old_size;
		array = old_arr;

		return result;
	}

	void pop() {
		assert(!isempty());
		array[0] = array[--size];
		heapify_down(0);
	}

	bool isempty() {
		return size == 0;
	}
};

void is_heap_array() {
	vector<int> v { 2, 17, 22, 10, 8, 37, 14, 19, 7, 6, 5, 12, 25, 30 };
	MinHeap heap(v);

	int arr[] {2, 5, 12, 7,6, 22, 14, 19, 10, 17, 8, 37, 25, 30};
	cout<<heap.is_heap_array(arr, 14)<<"\n";	// 1
	swap(arr[0], arr[5]);
	cout<<heap.is_heap_array(arr, 14)<<"\n";	// 0
}


int main() {
	is_heap_array();

	return 0;

}
