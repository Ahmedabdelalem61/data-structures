#include <iostream>
#include <cassert>
using namespace std;

struct Node {
	int data {};
	Node* next {};
	Node(int data) : data(data) {}
};

class LinkedList {
private:
	Node *head { };
	Node *tail { };
public:

	void print() {
		Node* temp_head = head;
		while(temp_head != nullptr) {
			cout<<temp_head->data<<" ";
			temp_head = temp_head->next;
		}
		cout<<"\n";
	}

	void insert_end(int value) {
		Node* item = new Node(value);

		if (!head)
			head = tail = item;
		else {
			tail->next = item;
			tail = item;
		}
	}
};

int main() {

	LinkedList list;

	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);
    list.insert_end(5);
	list.print();


	return 0;
}

