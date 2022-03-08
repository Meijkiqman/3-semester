#pragma once
class BinaryNode
{
public:
	BinaryNode();
	BinaryNode(int _data, BinaryNode* _left = nullptr, BinaryNode* _right = nullptr);

	int getData();
	BinaryNode* find(int _data);
	void insert(int _data);
	void intrav();
	BinaryNode* left;
	BinaryNode* right;
	BinaryNode* parent;

	BinaryNode* getLeft() { return left; };
	BinaryNode* getRight() { return right; };

	int data;
	

	//function for balancing BinaryTree
	void DoBalance(BinaryNode* root, int _data);
	
	//finds the height of the tree
	int height(BinaryNode* root);

	BinaryNode* RightRotation(BinaryNode* root);
	BinaryNode* LeftRotation(BinaryNode* root);

	//oppgave i eksamen 2020
	void stigende();
	void avtakende();

	double sum();

	void WidthFirstTraversal();
	void NonRecursivePreorderTraversal();

	BinaryNode* DeleteNode(BinaryNode* node);
	BinaryNode* FindInorderReplacement();

};