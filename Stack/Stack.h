#pragma once
class Stack
{
	int* data;
	unsigned int size;
	unsigned int count;

	// konstruktorok
	Stack();

	Stack(unsigned int size);

	// másolókonstruktor
	Stack(const Stack& stack);

	~Stack();

	void Put(int item);

	bool Get(int& item);

	void Print();

	int Count() { return count; }

	bool isEmpty() { return count == 0; }

};

