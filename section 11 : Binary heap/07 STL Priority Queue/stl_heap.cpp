

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void test_prioirty_queue_max_heap() {
	// It acts like a max-heap
	priority_queue<int> mx_heap;
	mx_heap.push(1);
	mx_heap.push(3);
	mx_heap.push(7);
	mx_heap.push(5);
	mx_heap.push(9);

	while (!mx_heap.empty()) {
		cout << mx_heap.top() << " ";
		mx_heap.pop();
	}
	cout << "\n";
	// 9 7 5 3 1
}

void test_prioirty_queue_min_heap() {
	// It acts like a min-heap...just copy the syntax
	priority_queue <int, vector<int>, greater<int>> mn_heap;
	mn_heap.push(1);
	mn_heap.push(3);
	mn_heap.push(7);
	mn_heap.push(5);
	mn_heap.push(9);

	while (!mn_heap.empty()) {
		cout << mn_heap.top() << " ";
		mn_heap.pop();
	}
	cout << "\n";
	// 1 3 5 7 9

	// Min heap of strings
	priority_queue <string, vector<string>, greater<string>> mn_heap_str;

	mn_heap_str.push("ziad");
	mn_heap_str.push("belal");

	while (!mn_heap_str.empty()) {
		cout << mn_heap_str.top() << " ";
		mn_heap_str.pop();
	}
	cout << "\n";
	// belal ziad
}





int main() {
	test_prioirty_queue_min_heap();
	return 0;
}

