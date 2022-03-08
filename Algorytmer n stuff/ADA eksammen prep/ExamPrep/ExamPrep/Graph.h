#pragma once
#include <list>
#include "node.h"
#include <vector>

struct Path
{
	std::list<Edge*> edges;
	double totalCost = 0;
	bool operator > (const Path& p) const { return totalCost > p.totalCost; }

};

struct cell
{
	Node* node;
	double f;
	double g;
	double h;

};

class Graph
{
public:
	Graph();
	std::list<Node*> nodes;
	Node* findNode(char name);
	void insertNode(char name);
	void insertEdge(char fromNode, char toNode, float weight);
	float minSpanningTree();
	void Dijkstra(char fromNode, char toNode);
	void AStar(char fromNode, char toNode);
};