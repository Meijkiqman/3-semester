#include "Graph.h"
#include<queue>
#include <iostream>
Graph::Graph()
{

}

Node* Graph::findNode(char name)
{
	for (auto& node : nodes )
	{
		if (node->name == name)
		{
			return node;
		}
	}
	return nullptr;
}

void Graph::insertNode(char name)
{
	Node* n = new Node(name);
	for (auto& node : nodes)
	{
		if (node->name == name)
		{
			//har allerede noden return
		}
	}
	nodes.push_back(n);
}

void Graph::insertEdge(char fromNode, char toNode, float weight)
{
	auto _toNode = findNode(toNode);
	Edge e(weight, _toNode);

	auto _fromNode = findNode(fromNode);
	_fromNode->InsertEdgeInNode(e);
}

float Graph::minSpanningTree()
{
	float sum = 0;
	std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> apq;
	for (auto node : nodes)
	{
		node->visited = false;
	}
	Edge edge(0, nodes.front());
	apq.push(edge);

	while (!apq.empty())
	{
		edge = apq.top();
		apq.pop();
		Node* p = edge.toNode;
		if (!p->visited)
		{
			p->visited = true;

			sum += edge.weight;
			for (auto it : p->edges)
			{
				apq.push(it);
			}
		}
	}

	return sum;
}

void Graph::Dijkstra(char fromNode, char toNode)
{
	std::priority_queue<Path, std::vector<Path>, std::greater<Path>> apq;
	std::priority_queue<Path> dpq;
	for (auto node : nodes)
	{
		node->visited = false;
	}

	Node* startNode = findNode(fromNode);
	Node* endNode = findNode(toNode);

	Path startPath;
	Edge startEdge(0, startNode);

	startPath.edges.push_back(&startEdge);
	startPath.totalCost = 0;

	apq.push(startPath);

	while (!apq.empty() && !endNode->visited)
	{
		//gets the shortest path from apq, top should be the shortest path
		auto path = apq.top();
		apq.pop();
		//this is A
		Node* node;
		if (!endNode->visited)
		{
			for (auto edge : path.edges)
			{
				node = edge->toNode;
				//this becomes A
				if (!node->visited)
				{
					//A.visisted = true;
					node->visited = true;
					std::cout << "set " << node->name << " to visited" << std::endl;
					//for each edge in A
					for (auto e : node->edges)
					{
						Path p = path;
						//pushes C to A-> A, C
						//pushes B to A-> A, B
						p.edges.push_back(&e);
						//adds 17
						//adds 2
						std::cout << "added " << e.weight << "to " << p.totalCost;
						p.totalCost += e.weight;
						std::cout << "which is now " << p.totalCost << std::endl;
						//A C is pushed, A B is pushed
						apq.push(p);
						std::cout << "pushed path: ";
						for (auto edge : p.edges)
						{
							Node* n = edge->toNode;
							std::cout << n->name << ", ";
						}
						std::cout << " = " << p.totalCost << std::endl;
						Path q = apq.top();
						std::cout << "this is the top of the apq now: ";
						for (auto edge : q.edges)
						{
							Node* n = edge->toNode;
							std::cout << n->name << std::endl;
						}
						std::cout << " = " << q.totalCost << std::endl;
					}
				}
				else
				{
					std::cout << "skipeed " << node->name << " because it has already been visisted" << std::endl;
				}
			}
		}
	}

	while (!apq.empty())
	{
		std::cout << "path: ";
		Path p = apq.top();
		for (auto edge : p.edges)
		{
			Node* n = edge->toNode;
			std::cout << n->name << ", ";
		}
		std::cout << " = " << p.totalCost << std::endl;
		apq.pop();
	}
}

void Graph::AStar(char fromNode, char toNode)
{

}