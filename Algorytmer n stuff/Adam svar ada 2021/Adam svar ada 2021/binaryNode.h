#pragma once
class BinaryNode
{
private:
	char m_data;
	int m_frekvens;
	BinaryNode* m_left;
	BinaryNode* m_right;
public:
	explicit BinaryNode(char data) : m_data{ data }, m_left{ nullptr },
	m_right{ nullptr }, m_frekvens{ 1 } { }
	void Insert(char data);
	void print() const;
	void printSorted();
};