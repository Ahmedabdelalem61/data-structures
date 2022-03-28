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

void print_inorder(Node* current) {
	cout << current->left->data << " ";
	cout << current->data << " ";
	cout << current->right->data << " ";

}
void print_postorder(Node* current) {
	cout << current->left->data << " ";
	cout << current->right->data << " ";
	cout << current->data << " ";
}
void print_preorder(Node* current) {
	cout << current->data << " ";
	cout << current->left->data << " ";
	cout << current->right->data << " ";
}

int main() {	// Create & Link Nodes
	Node* plus = new Node('+');
	Node* node2 = new Node('2');
	Node* node3 = new Node('3');
	plus->left = node2;
	plus->right = node3;
	print_postorder(plus);

	return 0;
}

