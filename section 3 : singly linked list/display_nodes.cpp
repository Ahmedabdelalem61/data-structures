#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data):data(data){}
};

//printing the data of nodes with trivial way
void print(Node* head){
    while (head != nullptr )
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
//printing the data of the nodes recursively
void printdata(Node* head){
    if(head == nullptr)
    {
        cout<<endl;
        return;
    }
    // you can print it in inversed way make the cout after the recersion call
    cout<<head->data<<" ";
    printdata(head->next);
}

int main(){

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = nullptr;

    print(node1);
    printdata(node1);
    return 0;
}