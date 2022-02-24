#include"charnode.h"
#include <iostream>
#include <sstream>

int CharNode::s_amount;

CharNode::CharNode(char sign, CharNode* next) : m_sign(sign), m_next(next)
{
	s_amount++;
}



CharNode* CharNode::getNext() const
{
	return m_next;
}

int CharNode::getAmount()
{
	return s_amount;

}

CharNode::~CharNode()
{
	s_amount--;
}


void CharNode::Print()
{
	std::cout << m_sign <<  ", " <<  std::endl;
}