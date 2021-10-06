#pragma once


class BinaryNode
{
public:
	BinaryNode();

	BinaryNode(int data, BinaryNode* left = nullptr, BinaryNode* right = nullptr);
	int getData();
	BinaryNode* find(int data);
	void insert(int data);
	void intrav();
	
	int m_data;
	BinaryNode* m_left;
	BinaryNode* m_right;

	BinaryNode* getLeft()
	{
		return m_left;
	};
	BinaryNode* getRight()
	{
		return m_right;
	};

};
