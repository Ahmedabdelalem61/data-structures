#include <iostream>
#include <cassert>
#include <climits>
#include <vector> 
#include <algorithm>
#include <sstream>
#include <deque>
using namespace std;

struct Node
{
	int data{};
	Node *left{};
	Node *right{};
	Node(int data) : data(data)
	{
	}
};

void generate_binary_tree_using_inorder_preorder(Node *root, deque<int> preorder, vector<int> inorder)
{
	if (preorder.size() == 0)
		return;
	vector<int> l_v;
	vector<int> r_v;
	int mid = 0, NewRootData = preorder.front();
	preorder.pop_front();
	Node * left = new Node(NewRootData);
	Node * right = new Node(NewRootData);
	root->left = left;
	root->right = right;
	cout<<" preorder size : "<<preorder.size()<<endl;
	root->data = NewRootData;
	cout<<" root data "<<root->data<<endl;
	for (int i = 0; i < inorder.size(); i++)
	{
		if (NewRootData == inorder[i])
		{
			{
				mid = i;
				break;
			}
		}
	}
	for (int i = 0; i < mid; i++)
	{
		l_v.push_back(inorder[i]);
	}
	generate_binary_tree_using_inorder_preorder(left, preorder, l_v);
	for (int i = mid + 1; i < inorder.size(); i++)
	{
		r_v.push_back(inorder[i]);
	}
	generate_binary_tree_using_inorder_preorder(right, preorder, r_v);
}
int main()
{
	Node *root = new Node(1);
	deque<int> preorder;
	preorder.push_back(1);
	preorder.push_back(2);
	preorder.push_back(4);
	preorder.push_back(5);
	preorder.push_back(3);
	vector<int > inorder;
	inorder.push_back(4);
	inorder.push_back(2);
	inorder.push_back(5);
	inorder.push_back(1);
	inorder.push_back(3);
	generate_binary_tree_using_inorder_preorder(root, preorder,inorder);
	cout << " left leaf of the root : " << root->left->left->data << endl;
	return 0;
}
