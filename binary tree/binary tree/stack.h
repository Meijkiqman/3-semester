#pragma once


class Stack
{
public:
	Stack();
	void Top();
	void Push(int node);
	void Pop();
	int Size();
	bool Empty();
private:
	int data[10];
	int index;
};

Stack::Stack()
{
	index = 0;
}

void Stack::Pop()
{
	index--;
}

void Stack::Push(int node)
{
	data[index] = node;
	index++;
}

int Stack::Size()
{
	return data[index - 1];
}

int Stack::Size()
{
	return index;
}

bool Stack::Empty()
{
	if (index == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}