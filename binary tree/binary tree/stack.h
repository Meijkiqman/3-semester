#pragma once

template<class T>
class Stack
{
public:
	Stack();
	T Top();
	void Push(T node);
	void Pop();
	int Size();
	bool Empty();
private:
	T data[10];
	int index;
};

template<class T>
Stack<T>::Stack()
{
	index = 0;
}

template<class T>
void Stack<T>::Pop()
{
	index--;
}

template<class T>
void Stack<T>::Push(T node)
{
	data[index] = node;
	index++;
}


template<class T>
T Stack<T>::Top()
{
	return data[index - 1];
}

template<class T>
int Stack<T>::Size()
{
	return index;
}

template<class T>
bool Stack<T>::Empty()
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