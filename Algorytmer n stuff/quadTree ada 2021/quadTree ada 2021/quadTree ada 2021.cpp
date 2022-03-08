#include <vector>
#include <iostream>

struct Vector2D
{
    double x;
    double y;

    Vector2D operator + (const Vector2D& v) const
    {
        Vector2D u;
        u.x = x + v.x;
        u.y = y + v.y;
        return u;
    }
    Vector2D operator - (const Vector2D& v) const
    {
        Vector2D u;
        u.x = x - v.x;
        u.y = y - v.y;
        return u;
    }
    Vector2D operator / (int d)
    {
        Vector2D u;
        u.x = x / d;
        u.y = y / d;
        return u;
    }
};

class QuadTree
{
public:

    QuadTree();
    void DivideOutData();
    QuadTree(Vector2D& vne, Vector2D& vnw, Vector2D& vse, Vector2D& vsw,
        QuadTree* qne = nullptr, QuadTree* qnw = nullptr, QuadTree* qse = nullptr, QuadTree* qsw = nullptr);
    QuadTree* Insert(Vector2D input);

    std::vector<Vector2D> data;

private:
    Vector2D v_ne;
    Vector2D v_nw;
    Vector2D v_se;
    Vector2D v_sw;
public:
    QuadTree* q_ne;
    QuadTree* q_nw;
    QuadTree* q_se;
    QuadTree* q_sw;
};


QuadTree::QuadTree()
{

}

QuadTree::QuadTree(Vector2D& vne, Vector2D& vnw, Vector2D& vse, Vector2D& vsw, 
	QuadTree* qne, QuadTree* qnw, QuadTree* qse, QuadTree* qsw) : 
	v_ne(vne), v_nw(vnw), v_se(vse), v_sw(vsw), 
	q_ne(qne), q_nw(qnw), q_se(qse), q_sw(qsw)
{
}

QuadTree* QuadTree::Insert(Vector2D input)
{
    //legger til input i data vekoren.
    data.push_back(input);
    return nullptr;
}
int main()
{
    //danner punktene som den første quadden dekker
    Vector2D ne{ 2, 2 };
    Vector2D nw{ -2, 2 };
    Vector2D se{ 2, -2 };
    Vector2D sw{ -2, -2 };
    //lager et nytt quadtree , og gir kordinatene fra construktoren
    QuadTree* tree = new QuadTree(ne, nw, se, sw);
    
    //bruker rand funskjoen for å få tifleldig punkter innen for 2, 2
    Vector2D va;
    //20 punkter
    for (int i = 0; i < 20; i++)
    {
        va.x = rand() % 2, -2;
        va.y = rand() % -2, 2;
        tree->Insert(va);
    }
    //for punktene 0,2 til -0,2
    for (int  i = 0; i < 20; i++)
    {
        va.x = rand() % (0, 2), -2;
        va.y = rand() % (-0, 2), 2;
        tree->Insert(va);
    }


}

void QuadTree::DivideOutData()
{
    //max grnsen for hvor mange elemtner man kan ha i hvert quad
    int max = 5;
    //finn punkter for hvor mulige nye quads må starte og ende
    //punkt mellom sør-øst og sør-west
    Vector2D a = (v_sw + v_se) / 2;
    //sør øst og nord øst
    Vector2D b = (v_se + v_ne) / 2;
    //nord øst og nord west
    Vector2D c = (v_ne + v_nw) / 2;
    //Nord vest og sør vest
    Vector2D d = (v_nw + v_sw) / 2;
    //midten av quaden
    Vector2D m = (v_ne + v_sw) / 2;

    //ta ut verdier fra data til der er m
    for (int i = data.size()-1; data.size() > max; i--)
    {
        //if the y is smaller than the middle it should land in one of the south tree
        if (data[i].y < m.y)
        {
            //if x is smaller than the middle x, it should land in the left tree
            if (data[i].x < m.x)
            {
                //hvis det ikke er noe subtree her, ndan en ny kordinatene funnet
                if (q_sw)
                {
                    q_sw->Insert(data[i]);
                }
            }
            else
            {
                //danner ny quad
                q_sw = new QuadTree(m, d, a, v_sw);
                //setter inn dataen
                q_sw->Insert(data[i]);
            }
        }
        else
        {
            if (q_se)
            {
                q_se->Insert(data[i]);
            }
            else
            {
                q_se = new QuadTree(b, m, v_se, d);
                q_se->Insert(data[i]);
            }
        }  
    }
}
