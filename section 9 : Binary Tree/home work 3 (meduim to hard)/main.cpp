#include <iostream>
#include <cassert>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class BinaryTree {
private:
	int data { };
	BinaryTree* left { };
	BinaryTree* right { };

public:
	BinaryTree(int data) :
			data(data) {
	}

    ~BinaryTree(){
        clear();
    }

    // checking after deleting any node from by it's detstructor
    // is left or right founded under it and delete it
    void clear(){
        if(left){
            delete left;
            left = nullptr;
        }

        if(right){
            delete right;
            right = nullptr;
        }
    }

	void print_inorder() {
		if(left)
			left->print_inorder();
		cout << data << " ";
		if(right)
			right->print_inorder();
	}

	void add(vector<int> values, vector<char> direction) {
		assert(values.size() == direction.size());
		BinaryTree* current = this;
		// iterate on the path, create all necessary nodes
		for (int i = 0; i < (int) values.size(); ++i) {
			if (direction[i] == 'L') {
				if (!current->left)
					current->left = new BinaryTree(values[i]);
				else
					assert(current->left->data == values[i]);
				current = current->left;
			} else {
				if (!current->right)
					current->right = new BinaryTree(values[i]);
				else
					assert(current->right->data == values[i]);
				current = current->right;
			}
		}
	}
	int tree_max(){
		int res = data;
        if(right){
            res = max(res,right->tree_max());
        }
        if(left){
            res = max(res,left->tree_max());
        }
        return res;
	}
    int tree_height(){
        int res = 0;
        if(left)
        res = max(left->tree_height()+1,res);
        if(right)
        res = max(right->tree_height()+1,res);
        return res;
    }

    int count_all_nodes(){
        int res = 1;
        if(right)
        res+=right->count_all_nodes();
        if(left)
        res+=left->count_all_nodes();
       return res;
    }

    int count_leaf_nodes(){
        int res = !left && !right;
        if(right)
        res+=right->count_leaf_nodes();
        if(left)
        res+=left->count_leaf_nodes();
       return res;
    }

    int is_exist(int value){
        int res = value == data;
        if(!res && left)
            res+= left->is_exist(value);
        if(!res && right)
            res+= right->is_exist(value);
        return res;
    }

    //a bit harder one about if the binary tree is perfect or not
    bool is_perfect(int h = -1){
        if(h == -1){
            h = tree_height();
        }

        if(!left && !right)
        return h == 0;

        if(!left && right || left && !right)
            return false;
        
        return left->is_perfect(h-1) && right->is_perfect(h-1);
    }
    //by math
    bool is_perfect_formual(){
        int h = tree_height();
        int n = count_all_nodes();
        return pow(2,h+1)-1 == n;
    }

    //  explaniation of what is happening here 
    /*
        whanever you have node is done print it otherwise
        push it's left with false,
        itself with true to be printed later inodrederd way
        and it's right with false  
    */
    void print_inorder_iterative() {
		stack<pair<BinaryTree*, bool> > nodes;
		nodes.push(make_pair(this, false));

		while (!nodes.empty()) {
			BinaryTree* current = nodes.top().first;
			bool is_done = nodes.top().second;
			nodes.pop();
			if (is_done)
				cout << current->data << " ";
			else {
				if (current->right)
					nodes.push(make_pair(current->right, false));

				nodes.push(make_pair(current, true));

				if (current->left)
					nodes.push(make_pair(current->left, false));
			}
		}
		cout << "\n";
	}

    void travese_left_boundary(){
        cout<<this->data<<" " ;
        if(left)
        left->travese_left_boundary();
        else if(right)
        right->travese_left_boundary();
        else{
            return;
        }
    }

    pair<int,int> tree_diameter(){
        // notice that is hard one and if you can not remember the idea comeback to the course
        pair<int,int> res ={0,0};
        if(!left && !right)
            return res;
        
        pair<int,int> left_diameter = {0,0};
        pair<int,int> right_diameter = {0,0};

        if(left)
        left_diameter = left->tree_diameter(),res.first = 1+left_diameter.second;
        if(right)
        right_diameter = right->tree_diameter(),res.first = 1+right_diameter.second;
        // updating the max diameter if its what i have or from right or left 
        res.first = max(res.first,max(left_diameter.first,right_diameter.first));

        //updating the height
        res.second = 1+ max(left_diameter.second,right_diameter.second);
        return res;
    }

    BinaryTree(string postfix){
        stack<BinaryTree*> tree;
        for(int i=0 ; i<postfix.length();i++){
            BinaryTree* cur  = new BinaryTree(postfix[i]);
            if(!isdigit(postfix[i])){
                cur->right = tree.top(),tree.pop();
                cur->left = tree.top(),tree.pop();
            }
            tree.push(cur);
        }
        BinaryTree* root = tree.top();
        this->data = root->data;
        this->left = root->left;
        this->right = root->right;
    }
};

int main() {
	BinaryTree tree(1);
	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
    tree.add( { 2, 4, 6 }, { 'L', 'L', 'R' });
    tree.add( { 2, 5, 6 }, { 'L', 'R', 'L' });
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	tree.add( { 3, 6, 10 }, { 'R', 'R', 'L' });
	// cout<<" max of the binary tree is : "<<tree.tree_max()<<endl;
    // cout<<" max height is : "<<tree.tree_height()<<endl;
    // cout<<" # of nodes is : "<<tree.count_all_nodes()<<endl;
    // cout<<" # of leaf nodes is : "<<tree.count_leaf_nodes()<<endl;
    // cout<<" # of nodes that exist : "<<tree.is_exist(6)<<endl;
    // cout<<" is the tree perfect? : "<<tree.is_perfect_formual()<<endl;
	// tree.print_inorder();
    tree.travese_left_boundary();

	return 0;
}

