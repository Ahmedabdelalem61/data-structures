#include <iostream>
#include <cassert>
using namespace std;

struct Node {
	char data { };
	Node* left { };
	Node* right { };
	Node(char data) :
			data(data) {
	}
};

void print_postorder(Node* current) {
	if(!current)
		return;
	print_postorder(current->left);
	print_postorder(current->right);
	cout << current->data << " ";
}

int main() {
	// (2+3) * 4 tree
	// Build plus subtree
	Node* plus = new Node('+');
	Node* node2 = new Node('2');
	Node* node3 = new Node('3');
	plus->left = node2;
	plus->right = node3;

	// Build/connect root to + *
	Node* multiply = new Node('*');
	Node* node4 = new Node('4');
	multiply->left = plus;
	multiply->right = node4;

	print_postorder(multiply);

	return 0;
}

