//quadtree
#include "QuadTree.h"
#include <iostream>

QuadTree::QuadTree()
{

}

QuadTree::QuadTree(Vector2D& vne, Vector2D& vnw, Vector2D& vse, Vector2D& vsw,
	QuadTree* qne, QuadTree* qnw, QuadTree* qse, QuadTree* qsw) :
	v_ne(vne), v_nw(vnw), v_se(vse), v_sw(vsw),
	q_ne(qne), q_nw(qnw), q_se(qse), q_sw(qsw)
{

}

void QuadTree::subdivide(int amount)
{
	if (amount > 0)
	{
		std::cout << "Subdivided: " << amount << std::endl;
		//Gets point between south west and south east
		Vector2D a = (v_sw + v_se) / 2;
		//Gets point between south east and nort heast
		Vector2D b = (v_se + v_ne) / 2;
		//Gets point between noerth east and north weast
		Vector2D c = (v_ne + v_nw) / 2;
		//Gets between north west and sout hwest
		Vector2D d = (v_nw + v_sw) / 2;
		//Gets middle
		Vector2D m = (v_ne + v_sw) / 2;

		//new North East Corner (10,10), (0,10), (10,0), (0,0)	
		q_ne = new QuadTree(v_ne, c, b, m);
		q_ne->subdivide(amount - 1);
		//new North West Corner (0,10), (-10,10), (0,0), (-10,0)
		q_nw = new QuadTree(c, v_nw, m, d);
		q_nw->subdivide(amount - 1);
		//new South East Corner (10,0), (0,0), (10,-10), (0,-10)
		q_se = new QuadTree(b, m, v_se, d);
		q_se->subdivide(amount - 1);
		//new South West Corner (0,0), (-10, 0), (0,-10), (-10,-10)
		q_sw = new QuadTree(m, d, a, v_sw);
		q_sw->subdivide(amount - 1);
	}
}

void QuadTree::Print()
{
	for (auto i = 0; i < data.size(); i++)
	{
		std::cout << "(" << data[i].x << ". " << data[i].y << ")" << std::endl;
	}
}

bool QuadTree::isLeaf()
{
	//if its a leaf, all quadtree pointers should be null
	if (q_ne == nullptr && q_nw == nullptr && q_se == nullptr && q_sw == nullptr) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

QuadTree* QuadTree::insert(Vector2D input)
{
	//if i am leaf, i can take the input
	if (isLeaf())
	{
		//but if i am at cap, subdivide
		if (atCap())
		{
			subdivide(1);
		}
		else
		{
			data.push_back(input);
			return nullptr;
		}
	}

	//if i get this far, i am not leaf

	// get middle to determine where it should go
	Vector2D middle = (v_ne + v_sw) / 2;
	//if the y is smaller than in the middle, it should land in one of the south trees
	if (input.y < middle.y)
	{
		//if the x is smaller than the middle, x should land in the left tree.
		//x goes from left to right

	}
	else
	{
		//opposite of the south
		if (input.x < middle.x)
		{
			q_nw->insert(input);
		}
		else
		{
			q_ne->insert(input);
		}
	}

	return nullptr;
}

QuadTree* QuadTree::find(Vector2D point)
{
	if (isLeaf())
	{
		return this;
	}
	else
	{
		Vector2D middle = (v_ne + v_sw) / 2;
		//find what quad it should be in
		//same as insert function
		if (point.y < middle.y)
		{
			if (point.x < middle.x)
			{
				q_sw->find(point);
			}
			else
			{
				q_se->find(point);
			}
		}
		else
		{
			if (point.x < middle.x)
			{
				q_nw->find(point);
			}
			else
			{
				q_ne->find(point);
			}
		}
	}
	return nullptr;
}

QuadTree* QuadTree::findAllLeafs()
{
	if (isLeaf())
	{
		std::cout << "NE:(" << v_ne.x << ", " << v_ne.y << "), " << "NW:(" << v_nw.x << ", " << v_nw.y << "), "
			<< "SE:(" << v_se.x << ", " << v_se.y << "), " << "SW:(" << v_sw.x << ", " << v_sw.y << ")" << std::endl;
		std::cout << "I have " << data.size() << " elements" << std::endl;
		return this;
	}
	if (q_ne) {
		q_ne->findAllLeafs();
	}
	if (q_nw) {
		q_nw->findAllLeafs();
	}
	if (q_se) {
		q_se->findAllLeafs();
	}
	if (q_sw) {
		q_sw->findAllLeafs();
	}
	return nullptr;

}

bool QuadTree::atCap()
{
	if (data.size() < cap)
	{
		std::cout << std::endl << "cap calculated: " << data.size() << std::endl;
		return false;
	}
	else
	{
		return true;
	}
}

void QuadTree::rebuild()
{
	//devide my data to my subquads
	Vector2D middle = (v_ne + v_sw) / 2;
	//devides the points to the subsquads
	for (int i = 0; i < data.size(); i++)
	{
		//if the y is smaller than the middle it should land in one of the south trees
		if (data[i].y < middle.y)
		{
			//if the x is smaller than the middle x, it should land in the left tree. x goes from the left to the right with size
			if (data[i].x < middle.x)
			{
				q_sw->insert(data[i]);
			}
			else
			{
				q_se->insert(data[i]);
			}
		}
		else
		{
			//opposite of the south
			if (data[i].x < middle.x)
			{
				q_nw->insert(data[i]);
			}
			else
			{
				q_ne->insert(data[i]);
			}
		}
	}
	data.clear();
}