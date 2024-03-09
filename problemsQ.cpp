#include <iostream>
using namespace std;

class Queue {
private:
	int front;
	int rear;
	int size;
	int* arr;

public:
	Queue(int size) : size(size), front(-1), rear(-1) {
		arr = new int[size];
	}

	void enqueue(int value) {
		if (rear != size - 1) {
			if (rear == -1 && front == -1) {
				front++;
				arr[++rear] = value;
			}
			else {
				arr[++rear] = value;
			}
		}
	}

	int dequeue() {
		if (front != -1 && rear != -1 && front <= rear) {
			return arr[front++];
		}
		return -1;
	}

	int peek() {
		if (front != -1 && rear != -1 && front <= rear)
			return arr[front];
		return -1;
	}

	void display() {
		if (front != -1 && rear != -1 && front <= rear) {
			for (int i = front; i <= rear; i++)
				cout << arr[i] << ' ';
			cout << endl;
		}
	}
};

class circularQueue {
private:
	int size;
	int front;
	int rear;
	int* arr;

public:
	circularQueue(int size) : size(size), front(-1), rear(-1) {
		arr = new int[size];
	}

	bool isFull() {
		return (front == 0 && rear == size - 1) || (front == rear + 1);
	}

	bool isEmpty() {
		return (front == -1 && rear == -1);
	}

	void enqueue(int value) {
		if (!isFull()) {
			if (isEmpty()) {
				front = rear = 0;
				arr[rear] = value;
			}
			else {
				rear = ++rear % size;
				arr[rear] = value;
			}
		}
	}

	int dequeue() {
		if (!isEmpty()) {
			int res = arr[front];
			if (front == rear) { // Target --> the last element.
				front = rear = 0;
			}
			else {
				front = ++front % size;
			}
			return res;
		}
		return -1;
	}

	int peek() {
		if (!isEmpty())
			return arr[front];
		return -1;
	}

	void display() {
		if (!isEmpty()) {
			int i = front;
			while (i != rear) {
				cout << arr[i] << ' ';
				i = (++i) % size;
				if (i == rear)
					cout << arr[i];
			}
			cout << endl;
		}
	}
};



// Problem #2
class Stack {
private:
	circularQueue q;
	int added;

	void insertAtfront(int value) {
		int sz = added;
		q.enqueue(value);
		while (sz--)
			q.enqueue(q.dequeue());
		added++;
	}

public:
	Stack(int size) : q(size) {

	}

	void push(int value) {
		insertAtfront(value);
	}

	int pop() {
		--added;
		return q.dequeue();
	}

	int peek() {
		return q.peek();
	}

	bool isEmpty() {
		return q.isEmpty();
	}
};

int main()
{



	return 0;
}

