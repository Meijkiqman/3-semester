// Graph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>

struct Node;

struct Edge
{
    Node* m_fra;
    Node* m_til;
    double m_vekt;
    Edge();
    Edge(Node* fra, Node* til);
};

Edge::Edge() : m_fra{ nullptr }, m_til{ nullptr }, m_vekt{ 0.0 } {}
Edge::Edge(Node* fra, Node* til) : m_fra{fra}, m_til{til}, m_vekt{1.0} {}

struct Node
{
    char m_navn;
    std::vector<Edge*> m_kanter;
    void push_edge(Edge* kant) { m_kanter.push_back(kant); }
};

struct Graph
{
    std::vector<Node*> m_noder;
    Graph();
    Node* find_node(char navn);
    void make_edges(char z, char y);
    void make_all_edges();
    void print() const;
};
//Implementer en konstruktør Graph::Graph() som legger inn nodene til grafen på figur 1.
Graph::Graph()
{
    for (char ch = 'A'; ch < 'I'; ch++)
    {
        m_noder.push_back(new Node{ ch });
        m_noder.push_back(new Node{ 'S' });
        m_noder.push_back(new Node{ 'M' });
    }
    

}
//Implementer Node* Graph::find_node(char navn) slik at den returnerer
 //en peker til noden med gitt navn hvis den fins i grafen, og en nullpeker ellers.

Node* Graph::find_node(char navn)
{
    for (auto it:m_noder)
    {
        if (it->m_navn == navn)
            return it;
    }
    return nullptr;
}
//Implementer void Graph::make_edges(char x, char y) slik at den setter
//inn kanter mellom xy og yx med vekt 1, gitt at noder med navn x og y fins i grafen.
void Graph::make_edges(char x, char y)
{
    Node* fra = find_node(x);
    Node* til = find_node(y);
    if (fra && til)
    {
        fra->push_edge(new Edge{ fra, til });
        til->push_edge(new Edge{ til, fra });
    }
}
//Implementer void make_all_edges() slik at funksjonen setter inn alle kantene på grafen på figur 1.
void Graph::print() const
{
    for  (auto it : m_noder)
    {
        std::cout << it->m_navn << ": ";
        for (auto k : it ->m_kanter)
        {
            std::cout << k->m_fra->m_navn << k->m_til->m_navn << ", ";
            
        }
        std::cout << std::endl;
    }
}
//Implementer void Graph::print() const slik at den skriver ut en oversikt
//over alle noder og tilhørende kanter i grafen.Skriv deretter main() hvor
//grafen på gur 1 opprettes og skrives ut.
void Graph::make_all_edges() // e
{
    make_edges('A', 'B');
    make_edges('A', 'C');
    make_edges('E ', 'C');
    make_edges('E ', 'F ');
    make_edges('E ', 'M');
    make_edges('G', 'F ');
    make_edges('G', 'H');
    make_edges('G', 'D');
    make_edges('S ', 'D');
    make_edges('S ', 'B');
}
int main()
{
    Graph g;
    g.make_all_edges();
    g.print();
    return 0;
      
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
