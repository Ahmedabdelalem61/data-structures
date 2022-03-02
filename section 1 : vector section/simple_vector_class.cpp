#include <iostream>
#include <cassert>
using namespace std;

class Vector {
private:
	int *arr { nullptr };
	int size { 0 };
	int capacity { };

	void expand_capacity();
public:
	Vector(int size);

	~Vector();
	int get_size();

	int get(int idx);

	void set(int idx, int val);

	void print();

	int find(int value);

    int get_front();

    int get_back();

    void push_back(int value);

	void righ_rotation();

	void righ_rotation(int n);

	void left_rotation();

	int pop(int index);

};


void Vector::expand_capacity() {
	capacity *= 2;
	cout << "Expand capacity to " << capacity << "\n";
	int *arr2 = new int[capacity] { };
	for (int i = 0; i < size; ++i)
		arr2[i] = arr[i];

	swap(arr, arr2);
	delete[] arr2;
}

Vector::Vector(int size) :
		size(size) {
	if (size < 0)
		size = 1;
	capacity = size + 10;
	arr = new int[capacity] { };
}

Vector::~Vector() {
	delete[] arr;
	arr = nullptr;
}

int Vector::get_size() {
	return size;
}

int Vector::get(int idx) {
	assert(0 <= idx && idx < size);
	return arr[idx];
}

void Vector::set(int idx, int val) {
	assert(0 <= idx && idx < size);
	arr[idx] = val;
}

void Vector::print() {
	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

int Vector::find(int value) {
	for (int i = 0; i < size; ++i)
		if (arr[i] == value)
			return i;
	return -1;
}

int Vector::get_front() {
	return arr[0];
}

int Vector::get_back() {
	return arr[size - 1];
}

void Vector::push_back(int value) {
	if (size == capacity)
		expand_capacity();
	arr[size++] = value;
}

void Vector::righ_rotation(){
	int last_element = get_back();
	for(int i=size-1; i>=0 ;i--){
		if(i==0){
			arr[0] = last_element;
		}else{
				arr[i] = arr[i-1];
		}
	}
}
void Vector::righ_rotation(int n){
	n%=size;//to ignore the cycles
	while (n--)
	{
		righ_rotation();
	}
}
void Vector::left_rotation(){
		int first_element = get_front();
		for(int i=0;i<size-1;i++){
				arr[i] = arr[i+1];
		}
		arr[size-1] = first_element;
	}
int Vector::pop(int index){
	if(index>=0 && index<size){
		int poped_val = arr[index];
		for(int i = index+1 ;i < size;i++){
			arr[i-1] = arr[i];
		}
		size--;
		return poped_val;
	}
}
int main() {

	Vector v(10);
	for (int i = 0; i < 10; ++i)
		v.set(i, i);
	v.righ_rotation(2);
	//v.left_rotation();
	v.print();
	cout<<v.pop(9)<<endl;
	v.print();

	// v.print();
	// cout<<v.find(5)<<" "<<v.find(55);
    // v.push_back(10);
    // cout<<endl;
    // v.print();

	return 0;
}