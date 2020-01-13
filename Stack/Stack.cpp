#include "Stack.h"
#include <cstddef>
#include <stdio.h>

Stack::Stack() : data(nullptr), size(0), count(0) {}

Stack::Stack(unsigned int size)
{
	data = nullptr;
	this->size = size;
	count = 0;
	
	if (size != 0)
	{
		data = new int[size];
	}
}
// beleteszünk egy itemet a tárolóba
void Stack::Put(int item)
{
	if (count >= size)
	{
		int* temp = new int[count + 1];
		
		for (unsigned int i = 0; i < count; i++)
		{
			temp[i] = data[i];
		}

		temp[count] = item;
		++count;
		delete[] data;
		data = temp;
	}
	else
	{
		data[count] = item;
		++count;
	}
}

bool Stack::Get(int& item)
{
	if (count == 0)
	{
		fprintf(stderr, "Data request from an empty stack.\n");
		return false;
	}
	
	item = data[0];
	--count;

	if (size <= count)
	{
		if (count == 0)
		{
			delete[] data;
			data = nullptr;
			return true;
		}
		int* temp = new int[count];
		for (unsigned int i = 0; i < count; i++)
		{
			temp[i] = data[i + 1];
		}

		delete[] data;
		data = temp;
	}
	else
	{
		for (unsigned int i = 0; i < count; i++)
		{
			data[i] = data[i + 1];
		}
	}
	return true;
}

Stack::~Stack()
{
	delete[] data;
}
