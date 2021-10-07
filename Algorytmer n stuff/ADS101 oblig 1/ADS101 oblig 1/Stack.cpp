#include "stack.h"


Stack::Stack()
{

}

void Stack::Push(CharNode* name)
{
	data = name;
}

void Stack::Pop()
{
	CharNode* out = data;
	data = out->getNext();
	delete out;
}
 CharNode* Stack::Top()
{
	 return data;
}

 int Stack::Size()
 {
	 return data->getAmount();
 }

 void Stack::Empty()
 {
	 
 }

