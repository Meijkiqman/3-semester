#include <string>
#include <sstream>
#include <iostream>
#include "CharNode.h"

namespace ADS101 {
	int CharNode::s_Amount;

	CharNode::CharNode(char sign, CharNode* next)
		: m_sign(sign), m_next(next)
	{
		
		s_Amount++;
	}

	std::string CharNode::toString() const
	{
		std::ostringstream oss;
		oss << m_sign;
		return oss.str();
	}
	CharNode* CharNode::getNext() const
	{
		return m_next;

}

void CharNode::writeBackwards() const
	{
		if (m_next)
			m_next->writeBackwards();
		std::cout << m_sign;

	}
int CharNode::getAmount()
{
	return s_Amount;
}
CharNode::~ CharNode()
{
	s_Amount--;
}
char CharNode::getData() const
{
	return m_sign;
}
}