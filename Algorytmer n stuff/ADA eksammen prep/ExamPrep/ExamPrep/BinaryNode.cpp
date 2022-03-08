#include "BinaryNode.h"
#include <iostream>
#include "TStack.h"
#include "TQueue.h"

BinaryNode::BinaryNode()
{
	data = 0;
}

BinaryNode::BinaryNode(int _data, BinaryNode* _left, BinaryNode* _right) : data(_data)
{
	data = _data;
	left: _left;
	right = _right;
}

int BinaryNode::getData()
{
	return data;
}

BinaryNode* BinaryNode::find(int _data)
{
	if (data == _data)
	{
		return this;
	}
	else if (_data < data && left != nullptr) // if _data is smaller than this->data and the left is not null, return the right find
	{
		return left->find(_data);
	}
	else if (_data > data && right != nullptr) //if _data is bigger than this -> data, return the right find
	{
		return right->find(_data);
	}
	//if none return, return a nullpr
	return nullptr;

}

void BinaryNode::insert(int _data)
{
	if (_data < data)
	{
		if (left)
		{
			left->insert(_data);
		}
		else
		{
			left = new BinaryNode(_data);
		}
	}
	else if (_data > data)
	{
		if (right)
		{
			right->insert(_data);
		}
		else
		{
			right = new BinaryNode(_data);
		}
	}
	DoBalance(this, _data);
}

void BinaryNode::intrav()
{
	if (left)
	{
		left->intrav();
	}
	std::cout << data << std::endl;
	if (right)
	{
		right->intrav();
	}
}

void BinaryNode::DoBalance(BinaryNode* root, int _data)
{
	//if right height is larger than left it returns negative
	int balance = height(root->getLeft()) - height(root->getRight());
	//left is taller than right
	//data is smaller than left
	if (balance > 1 && _data < root->getLeft()->data)
	{
		//unbalanced
		RightRotation(root);
	}
	//right is taller than left
	//data is larger than left
	if (balance < -1 && _data > root->getRight()->data)
	{
		LeftRotation(root);
	}
	//left is taller than right 
	//data is larger than left

	if (balance > 1 && -data > root->getLeft()->data)
	{
		//unbalanced
		root->left = LeftRotation(root->getLeft());
		RightRotation(root);
	}
	//right is taller than left
	//data is smaller tha right
	if (balance < -1 && _data < root->getRight()->data)
	{
		//unbalanced
		root->right = RightRotation(root->getRight());
		LeftRotation(root);
	}
}

int BinaryNode::height(BinaryNode* root)
{
	if (!root)
	{
		return 0;
	}
	int a;
	int b;
	if (root->getLeft())
	{
		a = 1 + height(root->getLeft());
	}
	if (root->getRight())
	{
		b = 1 + height(root->getRight());
	}
	if (a >= b)
	{
		return a;
	}
	else
	{
		return b;
	}

	return 0;
}

BinaryNode* BinaryNode::RightRotation(BinaryNode* root)
{
	BinaryNode* temp1 = root->getLeft();
	BinaryNode* temp2 = temp1->getRight();

	temp1->right = root;
	root->left = temp2;

	return temp1;
}


BinaryNode* BinaryNode::LeftRotation(BinaryNode* root)
{
	BinaryNode* temp1 = root->getRight();
	BinaryNode* temp2 = temp1->getLeft();

	root->left = temp1;
	temp1->right = temp2;

	return temp1;
}

void BinaryNode::stigende()
{
	if (left)
		left->stigende();
	std::cout << data << std::endl;

	if (right)
	{
		right->stigende();
	}
}

void BinaryNode::avtakende()
{
	if (right)
	{
		right->avtakende();
	}
	std::cout << data << std::endl;
	if (left)
	{
		left->avtakende();
	}
}

double BinaryNode::sum()
{
	double totalsum = data;
	if (left)
	{
		totalsum += left->sum();
	}
	if (right)
	{
		totalsum += right->sum();
	}
	return totalsum;

}

BinaryNode* BinaryNode::DeleteNode(BinaryNode* node)
{
	if (right) 
	{
		if (node->right) 
		{
			if (node != right) 
			{
				node->right->parent = node->parent;
			}
			else 
			{
				node->right->parent = parent;
			}
			if (node != right) 
			{
				node->parent->left = node->right;
				node->right = right;
				right->parent = node;
			}
			node->left = left;
			if (left) {
				left->parent = node;
			}
		}
		if (node) 
		{
			node->parent = parent;
		}
		if (parent) 
		{
			if (parent->left == this) 
			{
				parent->left = node;
			}
			else if (parent->right == this) 
			{
				parent->right = node;
			}
		}

	}
	return this;
}

void BinaryNode::NonRecursivePreorderTraversal()
{
	BinaryNode* p = this;
	TStack<BinaryNode*> stack;

	do 
	{
		while (p != nullptr) 
		{
			std::cout << data << ", ";
			stack.Push(p);
			p = p->left;
		}
		if (!stack.Empty()) 
		{
			stack.Pop();
			p = p->right;
		}
	} 
	while (!stack.Empty() || p != nullptr);
	std::cout << std::endl;
}