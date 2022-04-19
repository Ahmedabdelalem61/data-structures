#include<iostream>
using namespace std;
struct Node
{
    Node(int data):data(data){}
    int data {};
    Node* right;
    Node* left;
    ~Node()
    {
        cout<<"the node deleted here is the destructor \n";
    };
};

// delete from memory to manage memory leak.
void clear(Node* node){
    cout<<"the node of the val "<<node->data<<" are deleted :)\n";
    delete node;
}

void printAllTree(Node* node){
     if(!node)
     return;
     cout<<"node data is : "<<node->data<<endl;
     printAllTree(node->right);
     printAllTree(node->left);
     clear(node);
}

int main(){
    //let's do it now!
    Node* root = new Node(0);
    //right part
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    //left part
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);
    Node* node8 = new Node(8);

    //conecting the nodes to it's other
    root->right = node1;
    root->left = node5;

    node1->right = node2;
    node1->left = node3;
    node3->right = node4;
    
    node5->right = node6;
    node5->left = node7;
    node7->right = node8;

    //print the tree
    printAllTree(root);

    return 0;
}