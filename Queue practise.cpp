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

	void dequeue() {
		if (front != -1 && rear != -1 && front <= rear)
			front++;
		return;
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

			// 2nd Way.
			/*
			if (isEmpty()) {
				front = rear = 0;
				arr[rear] = value;
			}
			else if (rear == size - 1) {
				rear = 0;
				arr[rear] = value;
			}
			else {
				arr[++rear] = value;
			}
			*/
		}
	}

	void dequeue() {
		if (!isEmpty()) {
			if (front == rear) { // Target --> the last element.
				front = rear = 0;
			}
			else {
				front = ++front % size;
			}

			// 2nd Way.
			/*
			if (front == rear) {
				front = rear = 0;
			}
			else if(front == size - 1) {
				front = 0;
			}
			else {
				front++;
			}
			*/
		}
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

int main()
{
	// Verify simple queue.
	/*
	Queue q1(3);

	q1.enqueue(5);
	q1.enqueue(10);
	q1.enqueue(15);

	q1.display();

	q1.dequeue();

	q1.display();

	cout << "Peek = " << q1.peek();
	*/
	
	// Verify circular queue.
	/*
	circularQueue c(5);

	c.enqueue(1);
	c.enqueue(2);
	c.enqueue(3);
	c.enqueue(4);
	c.enqueue(5);

	c.display(); // 1 2 3 4 5

	c.enqueue(6); // Not valid --> Queue is full.

	c.dequeue();

	c.display(); // 2 3 4 5 

	c.enqueue(6);

	c.display(); // 2 3 4 5 6

	cout << "Peek = " << c.peek();
	*/

	return 0;
}

