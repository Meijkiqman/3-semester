#pragma once
#ifndef CHARNODE_H
#define CHARONDE_H

#include<string>
namespace ADS101 {



	template <class T>
	class Node
	{
	public: Node(T sign, Node* next = nullptr);
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
	Node<T>::Node(T sign, Node<T>* next)
		: m_sign(sign), m_next(next)
	{
		s_amount++;
	}

	template <class T>
	Node<T>* Node<T>::getNext() const
	{
		return m_next;
	}

	template<class T>

	void Node<T>::setNext(Node<T>* next)
	{
		m_next = next;
	}

	template<class T>
	int Node<T>::getAmount()
	{
		return s_amount;
	}

	template <class T>
	Node<T>::~Node()
	{
		return s_amount;
	}
	template <class T>
	T Node<T>::getData() const
	{
		return m_sign;
	}

}

#endif // !
