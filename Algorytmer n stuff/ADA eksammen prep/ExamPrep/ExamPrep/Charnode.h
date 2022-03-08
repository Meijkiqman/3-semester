#ifndef CHARNODE_H
#define CHARNODE_H

#include <string>

class CharNode
{
public:
	CharNode(char sign = '0', CharNode* next = nullptr);
	CharNode* getNext() const;
	static int getAmount();
	char getData() const;
	void Print();
	~CharNode();
private:
	char m_sign;
	static int s_amount;
	CharNode* m_next;
};


#endif

