#include "charnode.h"
#include <iostream>

int CharNode::s_amount;

CharNode::CharNode(char sign, CharNode* next)
	:m_sign(sign), m_next(next)
{
	s_amount++;
}

CharNode* CharNode::getNext()
{
	return m_next;
}

int CharNode::getAmount()
{
	return s_amount;
}

CharNode::~CharNode()
{
	s_amount;
}

char CharNode::getData()
{
	return m_sign;
}

void CharNode::print()
{
	std::cout << m_sign << ", ";
}
