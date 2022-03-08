#include "binaryNode.h"
#include <iostream>
#include <queue>
#include <string>

int main()
{
    //Kandidat nr·118. Side 8
    std::string s{ "det er enklere å løse et algoritmisk problem enn et demokratisk" };
    //Danner roten som første element i stringen
    BinaryNode * node = new BinaryNode(s[0]);
    //Går gjennom hvert element i stringen og inserter elementet til binary treet
    for (int i = 1; i < s.size(); i++) {
    node->Insert(s[i]);
    }
    //Kaller print funksjonen
    node->print();
    return 0;
        
}

void BinaryNode::Insert(char data)
{
    //Bruker std::queue til å ha alle nodene, for å så sjekke de
    std::queue<BinaryNode*> list;
    //Finn hvis det er noen lingende i treet
    list.push(this);
    BinaryNode* node;
    //Wont run if there is no right
    while (!list.empty())
    {
        node = list.front();
        //Når pekeren til toppen er funnet, popper den fra queuen fordi vi er ferdig
        list.pop();
        //Hvis noden sin data er lik som data parameteren, legg til frekvensen
        if (node->m_data == data)
        {
            node->m_frekvens++;
        }
        //Hvis denne noden har barn, legg de til i queuen,
        if (node->m_left)
        {
            list.push(node->m_left);
        }
        if (node->m_right) {
            list.push(node->m_right);
        }
    }
    if (data < m_data)
    {
        if (m_left) {
            m_left->Insert(data);
        }
        else
        {
            m_left = new BinaryNode(data);
        }
    }
    else if (data > m_data) {
        if (m_right) {
            m_right->Insert(data);
        }
        else {
            m_right = new BinaryNode(data);
        }
    }
}


void BinaryNode::print() const
{ 
        if (m_left) 
        {
            m_left->print();
        }
    std::cout << m_data << "=" << m_frekvens << ", ";
    if (m_right) {
        m_right->print();
    }
}



/*
//Overrider operatoren > til binary node, så når de sammenlignes vil de gå på hvem n
//  bool operator > (const BinaryNode& b1, const BinaryNode& b2) {
   // return b1.m_frekvens >
void BinaryNode::printSorted()
{ 
            //Erklerer en kø for nodene, som sorteres ved den overkjørte operatoren, som gir
    std::priority_queue < BinaryNode*, std::vector<BinaryNode*>, std::greater < BinaryNode*;
            //En queue for å itterere gjennom alle nodene i treet og legge de til apq
            std::queue<BinaryNode*> list;
        //Pusher først seg selv inn inn i list
        list.push(this);
        //Erklerer en peker til en BinaryNode
        BinaryNode* node;
        while (!list.empty()) {
            node = list.front();
            list.pop();
            //Add it to the priorty queue
            apq.push(node);
            //Hvis denne noden har høyre eller vesntre barn, legg de til
            if (node->m_left) {
                list.push(node->m_left);
            }
            if (node->m_right) {
                list.push(node->m_right);
            }
            //Gjentas til det ikke er noen flere noder å finne
        }
        //Så lenge apq ikke er tom,
        while (!apq.empty()) {
            //Sett node til toppen, den laveste frekvensen
            node = apq.top();
            //Pop den ut av køen
            apq.pop();
            //Printer dataen og frekvensen
std::cout << node->m_data << "=" << node->m_frekvens << ", ";
}
std::cout << std::endl;
}*/