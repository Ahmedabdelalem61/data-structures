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

void print_inorder(Node* current) {
	if(!current)
		return;
	print_inorder(current->left);
	cout << current->data << " ";
	print_inorder(current->right);
}

void print_preorder(Node* current) {
	if(!current)
		return;
	cout << current->data << " ";
	print_preorder(current->left);
	print_preorder(current->right);

}

int main() {
	// (2 + 3) * (9 - 8 / 4)

	Node* plus = new Node('+');
	plus->left = new Node('2');
	plus->right = new Node('3');

	Node* div = new Node('/');
	div->left = new Node('8');
	div->right = new Node('4');

	Node* minus = new Node('-');
	minus->left = new Node('9');
	minus->right = div;

	Node* multiply = new Node('*');
	multiply->left = plus;
	multiply->right = minus;

	print_postorder(multiply);

	return 0;
}

