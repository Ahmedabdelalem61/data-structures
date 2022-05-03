#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
class BinarySearchTree
{
private:
public:
	int data{};
	BinarySearchTree *left{};
	BinarySearchTree *right{};
	BinarySearchTree *parent{};

	BinarySearchTree(int data) : data(data)
	{
	}
	bool find_chain(vector<BinarySearchTree *> &ancestors, int target)
	{
		ancestors.push_back(this);

		if (target == data)
			return true;

		if (target < data)
			return left && left->find_chain(ancestors, target);

		return right && right->find_chain(ancestors, target);
	}

	void insert(int target)
	{
		if (target < data)
		{
			if (!left)
			{
				left = new BinarySearchTree(target);
				left->parent = this;
			}
			else
				left->insert(target);
		}
		else if (target > data)
		{
			if (!right)
			{
				right = new BinarySearchTree(target);
				right->parent = this;
			}
			else
				right->insert(target);
		} // else: exists already
	}

	int min_value()
	{
		BinarySearchTree *cur = this;
		while (cur && cur->left)
			cur = cur->left;
		return cur->data;
	}

	BinarySearchTree *get_next(vector<BinarySearchTree *> &ancestors)
	{
		if (ancestors.size() == 0)
			return nullptr;
		BinarySearchTree *node = ancestors.back(); // last element
		ancestors.pop_back();
		return node;
	}

	pair<bool, int> successor(int target)
	{
		vector<BinarySearchTree *> ancestors;

		if (!find_chain(ancestors, target))
			return make_pair(false, -1);

		BinarySearchTree *child = get_next(ancestors);

		if (child->right)
			return make_pair(true, child->right->min_value());
		BinarySearchTree *parent = child->parent;
		while (parent && parent->right == child)
			child = parent,parent = child->parent;

		if (parent)
			return make_pair(true, parent->data);
		return make_pair(false, -1);
	}
};

int main()
{
	BinarySearchTree tree(50);
	tree.parent = nullptr;
	// tree.insert(20);
	// tree.insert(60);
	// tree.insert(10);
	// parent of 10 is 20
	// cout<<tree.left->left->parent->data;
	// cout<<tree.successor(50).second<<endl;
	// will be 60
	tree.insert(20);
	tree.insert(60);
	tree.insert(25);
	tree.insert(30);
	tree.insert(35);
	cout << tree.successor(35).second << endl;
	cout << "bye\n";

	return 0;
}
