#include <iostream>
#include <cassert>
using namespace std;

class Stack {
private:
	int size { };
	int top { };
	int* array { };
public:
	Stack(int size) :
			size(size), top(-1) {
		array = new int[size];
	}

	~Stack() {
		delete[] array;
	}

	void push(int x) {
		assert(!isFull());
		array[++top] = x;
	}

	int pop() {
		assert(!isEmpty());
		return array[top--];
	}

	int peek() {
		assert(!isEmpty());
		return array[top];
	}

	int isFull() {
		return top == size - 1;
	}

	int isEmpty() {
		return top == -1;
	}

	void display() {
		for (int i = top; i >= 0; i--)
			cout << array[i] << " ";
		cout << "\n";
	}

    	void displayReversed() {
		for (int i = 0; i <= top; i++)
			cout << array[i] << " ";
		cout << "\n";
	}
    
    void astroidExplosion(int arr[],int len){
        Stack res = Stack(len);
        bool isExploded = false;
        for(int i=0;i<len;i++){
            int astroid = arr[i];
            while (!res.isEmpty() &&  res.peek() > 0   && astroid < 0 )
            {
                if( -astroid == res.peek()){
                    res.pop();
                    isExploded = true;
                    break;
                }
                else if( -astroid > res.peek()) // look up for more explosions
                {
                    res.pop();
                    continue;
                }
            }
            if(!isExploded){
                res.push(astroid);
            }
        }
        res.displayReversed();
    }
};

int main() {


	Stack stk(3);
	stk.push(10);
	stk.push(20);
	stk.push(30);

	if (!stk.isFull())
		stk.push(50);
	else
		cout << "Full Stack\n";
	stk.display();	// 30 20 10
	cout << stk.peek() << "\n";	// 30

	while (!stk.isEmpty()) {
		cout << stk.peek() << " ";
		stk.pop();
	} // 30 20 10

	return 0;
}
