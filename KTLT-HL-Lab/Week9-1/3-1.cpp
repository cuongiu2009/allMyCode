#include <iostream>
using namespace std;
struct Stack {
	int* data; // dynamic array
	int top; // index of top element
	int capacity; // size of stack
};
void initArray(Stack& s) {
	s.data = new int[100];
	s.capacity = 0;
	s.top = 0;
}
bool isEmpty(Stack s) {
	if (s.top == 0)
		return true;
	return false;
}
void push(Stack& s, int value) {
	s.top++;
	s.data[s.top] = value;
	s.capacity++;
}
void pop(Stack& s) {
	if (isEmpty(s))
		return;
	else {
		int x = s.data[s.top];
		s.top--;
		s.capacity--;
	}
}
void output(Stack s) {
	while (s.top != 0) {
		cout << s.data[s.top] << " ";
		pop(s);
	}
	cout << endl;
}
void emptyStack(Stack& s) {
	while (s.capacity != 0)
		pop(s);
}
int getSizeStack(Stack s) {
	return s.capacity;
}
int main() {
	Stack s;
	initArray(s);
	push(s, 10);
	push(s, 20);
	output(s);
	cout << getSizeStack(s);
	return 0;
}