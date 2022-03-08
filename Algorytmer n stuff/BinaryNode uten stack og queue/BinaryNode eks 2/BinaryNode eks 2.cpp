
#include <iostream>

class BinaryNode {
public:
    BinaryNode(double data = 0.0);
    void insert(double data);
    void stigende() const;
    void avtakende() const;
private:
    double m_data;
    BinaryNode* m_left;
    BinaryNode* m_right;
};

BinaryNode::BinaryNode(double data)
    : m_data{ data }, m_left{ nullptr }, m_right{ nullptr } { }


void BinaryNode::insert(double data) 
{
  if (data < m_data) 
  {
      if (m_left)
      { 
          m_left->insert(data);
      }
      else
      { 
          m_left = new BinaryNode(data);
      }
  }
  else if (data > m_data) 
  {
      if (m_right)
      { 
          m_right->insert(data);
      }
      else
      { 
          m_right = new BinaryNode(data);
      }
  }
}

//Skriv koden til funksjonen stigende() slik at den skriver ut nodenes verdier
//i stigende rekkefølge når den kalles av roten i et tre.

void BinaryNode::stigende() const
{
    if (m_left)
    {
        m_left->stigende();
    }
    std::cout << m_data << std::endl;
    if (m_right)
    {
        m_right->stigende();
    }
}
//Skriv koden til funksjonen avtakende() slik at den skriver ut nodenes verdier
//i avtakende rekkefølge når den kalles av roten i et tre.
//
void BinaryNode::avtakende() const
{
   //starter fra right for avtakende
    if (m_right)
    {
        m_right->avtakende();
    }
    std::cout << m_data << std::endl;
    if (m_left)
    {
        m_left->avtakende();
    }
}
//Skriv et testprogram hvor du setter inn verdiene 14, 33, 12, 4, 7, 19, 29, 11,21, 17
//i opplistet rekkefølge og deretter skriver ut stigende og avtakende.
int main()
{
    double a[]{ 14, 33, 12, 4, 7, 19, 19, 11, 21, 17 };
    BinaryNode tree{ a[0] };
    for (int i = 1; i < 10; i++)
    {
        tree.insert(a[i]);
    }
    tree.stigende();
    std::cout << std::endl;
    tree.avtakende();

}

