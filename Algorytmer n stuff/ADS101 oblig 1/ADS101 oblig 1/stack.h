#ifndef STACK_H
#define STACK_H

#include "CharNode.h"

class Stack

{
public:
	Stack();
	void Push(CharNode*);
	void Pop();
	CharNode* Top();
	int Size();
	void Empty();
private:
	CharNode* data;
};

#endif // !STACK_H
