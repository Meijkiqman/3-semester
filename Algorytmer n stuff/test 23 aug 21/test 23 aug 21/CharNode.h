#pragma once
#ifndef CHARNODE_II
#define CHARNODE_II

#include <string>

namespace ADS101 {
	class CharNode
	{
	public:
		CharNode(char sign = '0', CharNode* next = nullptr);
		std::string toString() const;
		CharNode* getNext() const;
		void writeBackwards() const;
		static int getAmount();
		char getData() const;
		~CharNode();

	private:
		char m_sign;			// Data-del
		static int s_Amount;
		CharNode* m_next;	//Datastrukur-del
	};


}
#endif //CHARNODE_II#pragma once