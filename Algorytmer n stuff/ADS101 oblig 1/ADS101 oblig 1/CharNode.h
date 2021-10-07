
#ifndef CHARNODE_II
#define CHARNODE_II



class CharNode
	{
	public:
		CharNode(char, CharNode* next = nullptr);
		CharNode* getNext();
		static int getAmount();
		char getData();
		void print();
		~CharNode();

	private:
		char m_sign;			
		static int s_amount;
		CharNode* m_next;
	};

#endif //CHARNODE_II#pragma once