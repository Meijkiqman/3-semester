#ifndef TSTACK_H
#define TSTACK_H


template<typename T>
class TStack

{
public:
	TStack();
	void Push(T*);
	void Pop();
	T* Top();
	int Size();
	void Empty();
private:
	T* data;
	
};
template <typename T>
TStack<T>::TStack()
{

}
template <typename T>
void TStack<T>::Push(T* name)
{
	data = name;
}

template <typename T>
void TStack<T>::Pop()
{
	T* out = data;
	data = out->getNext();
	delete out;
}
template <typename T>
T* TStack<T>::Top()
{
	return data;
}

template <typename T>
int TStack<T>::Size()
{
	return data->getAmount();
}

template <typename T>
void TStack<T>::Empty()
{

}
#endif // !STACK_H
