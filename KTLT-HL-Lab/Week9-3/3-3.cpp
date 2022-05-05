#include <iostream>
using namespace std;
struct Queue
{
	int* data;
	int in;//rear
	int out;//front
	int capacity;
};
void initQueue(Queue& q, int n) {
	q.capacity = n;
	q.in = 0;
	q.out = 0;
	q.data = new int[n];
}
void enQuene(Queue& q, int value) {
	if (q.in == q.capacity)
		cout << "full" << endl;
	else {
		q.data[q.in] = value;
		q.in++;
	}
}
void deQueue(Queue& q) {
	if (q.in == q.out)
		cout << "Underflow" << endl;
	else {
		q.data[q.out] = 0;
		q.out++;
	}
}
int sizeOfQueue(Queue q) {
	return q.capacity;
}
bool isEmpty(Queue q) {
	if (q.capacity == 0)
		return true;
	return false;
}
void emptyQueue(Queue& q) {
	while (q.capacity > 0) {
		deQueue(q);
		q.capacity--;
	}
}
int main() {
	Queue q;
	initQueue(q, 3);
	enQuene(q, 3);
	enQuene(q, 3);
	enQuene(q, 3);
	enQuene(q, 4);
	int size = q.capacity;
	while (size > 0) {
		cout << q.data[q.out] << " ";
		size--;
	}
	return 0;
}