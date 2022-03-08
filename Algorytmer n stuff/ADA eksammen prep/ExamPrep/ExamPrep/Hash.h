#pragma once
#include <iostream>
#include<list>

struct Test
{
	int key;
	std::string s;
	bool operator == (const Test& t2) const { return key == t2.key; }
};

template<>
class std::hash<Test>
{
public:
	size_t operator() (const Test& t) const
	{
		return t.key % 7;
	}
	bool operator() (const Test& t1, const Test& t2)
	{
		return t1.key == t2.key;
	}
};

class Hash
{
public:
	Hash(int x);
	Hash();
	void insertItem(int key);
	void deleteItem(int key);
	int hashFunction(int x);
	void displayHash();

	int Bucket;
	std::list<int>* table;

	void testHash();
	void TestUnorderedset();
	void TestUnorderedMultiset();

};