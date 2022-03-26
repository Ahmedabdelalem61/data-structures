#include <iostream>
#include <cassert>
using namespace std;

struct Node
{
    int data{};
    Node *next{};
    Node(int data) : data(data) {}
    ~Node()
    {
        cout << "Destroy value: " << data << " at address " << this << "\n";
    }
};

class LinkedList
{
public:
    Node *head{};
    Node *tail{};
    int length = 0;
    LinkedList()
    {
    }
    LinkedList(const LinkedList &) = delete;
    LinkedList &operator=(const LinkedList &another) = delete;

    void print()
    {
        for (Node *cur = head; cur; cur = cur->next)
            cout << cur->data << " ";
        cout << "\n";
    }

    int insert_end(int value)
    {
        Node *item = new Node(value);

        if (!head)
            head = tail = item;
        else
            tail->next = item, tail = item;
        length++;
        return value;
    }

    int insert_front(int value)
    {
        Node *item = new Node(value);

        item->next = head;
        head = item;

        if (length == 1)
            tail = head;
        length++;
        return value;
    }
    void delete_node(Node *node)
    {
        --length;
        delete node;
    }
    int delete_front()
    {
        assert(length);
        Node *cur = head->next;
        int front_val = head->data;
        delete_node(head);
        head = cur;
        return front_val;
    }
    void delete_next(Node *node)
    {
        Node *to_delete = node->next;
        node->next = node->next->next;
        delete_node(to_delete);
    }
    void delete_end()
    {
        for (Node *cur = head; cur; cur = cur->next){
            if(cur->next == tail){
                delete_next(cur);
                tail = cur;
            }
        }
    }
};

class Queue
{
    // the queue is based on linked list
public:
    LinkedList list;
    Queue(/* args */) {}
    ~Queue()
    {
        // note that you shoud handle the part of deletion of all nodes
    }
    int enqueue_rear(int val)
    {
        return list.insert_front(val);
    }

    int enqueue_front(int val)
    {
        return list.insert_end(val);
    }

    void dequeue_front()
    {
        list.delete_end();
    }

    void dequeue_rear()
    {
        list.delete_front();
    }

    bool isEmpty()
    {
        return list.length == 0;
    }
    void display()
    {
        list.print();
    }
};

int main()
{
    Queue que;
    que.enqueue_front(3);
    que.enqueue_front(2);
    que.enqueue_rear(4);
    que.enqueue_front(1);
    que.display();// 4 3 2 1
    que.dequeue_rear();
    que.display();// 3 2 1
    que.dequeue_front();
    que.display();//// 3 2
    que.dequeue_rear();
    que.display();// 2
    que.enqueue_front(1);
    que.display();// 2 1
    return 0;
}
