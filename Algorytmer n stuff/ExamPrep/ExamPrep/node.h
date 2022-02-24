#pragma once
#include <list>
class Node;
struct Edge {
	float weight;
	Node* toNode;
	Edge(float _weight, Node* _toNode) : weight(_weight), toNode(_toNode) {}
	bool operator > (const Edge& e) const { return weight < e.weight; };
};

class Node
{
public:

	char name;
	bool visited;
	std::list<Edge> edges;
	Node(char _name) : name(_name), visited(false) { };
	void InsertEdgeInNode(const Edge& edge);
};


/*#ifndef NODE_H
#define NODE_H


template<class T>
class Node
{
public:
	Node(T sign, Node* next = nullptr);
	Node<T>* getNext() const;
	void setNext(Node<T>* next);
	static int getAmount();
	T getData() const;
	~Node();
private:
	T m_sign;
	static int s_amount;
	Node<T>* m_next;
};

template <class T>
int Node<T>::s_amount;

template <class T>
Node<T>::Node(T sign, Node<T>* next) : m_sign(sign), m_next(next)
{
	s_amount++;
}

template <class T>
Node<T>* Node<T>::getNext() const
{
	return m_next;
}

template <class T>
void Node<T>::setNext(Node<T>* next)
{
	m_next = next;
}

template <class T>
int Node<T>::getAmount()
{
	return s_amount;
}

template <class T>
Node<T>::~Node()
{
	s_amount--;
}

template <class T>
T Node<T>::getData() const
{
	return 0;// m_sign;
}

#endif*/
