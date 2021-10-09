#include <iostream>
#include "QuadTree.h"





QuadTree::QuadTree(const Vector2d &v1, const Vector2d &v2, const Vector2d &v3, const Vector2d &v4)
	:v_sw{v1}, v_se{v2}, v_ne{v3}, v_nw{v4},
	m_sw{ nullptr }, m_se{ nullptr }, m_ne{ nullptr }, m_nw{ nullptr }
{

}

void QuadTree::subDivide(int n)
{
	if (n > 0)
	{
		Vector2d v1 = (v_sw + v_se) / 2;
		Vector2d v2 = (v_se + v_ne) / 2;
		Vector2d v3 = (v_ne + v_nw) / 2;
		Vector2d v4 = (v_nw + v_sw) / 2;
		Vector2d m = (v_sw + v_ne) / 2;

		m_sw = new QuadTree(v_sw, v1, m, v4);
		m_sw->subDivide(n - 1);

		m_se = new QuadTree(v1, v_se, v2, m);
		m_se->subDivide(n - 1);

		m_ne = new QuadTree(m, v2, v_ne, v3);
		m_ne->subDivide(n - 1);

		m_nw = new QuadTree(v4, m, v3, v_nw);
		m_nw->subDivide(n - 1);

	}
}


bool QuadTree::isLeaf() const
{
	//if this is a leaf, then all the pointer/nodes in quadtree should point to nullptr
	if (m_ne == nullptr && m_se == nullptr && m_nw && m_sw == nullptr)
	{
		return true;
	}
	else
	{

		std::cout << "THIS IS FALSE" << std::endl;
		return false;
	}
}

//finds all leafs(corners) the the quadtree
QuadTree* QuadTree::findAllLeafs()
{
	if (isLeaf())
	{
		std::cout << "ne(" << v_ne.x << ", " << v_ne.y << "), " << "nw(" << v_nw.x << ", " << v_nw.y << ")" << std::endl;;
		std::cout << "se(" << v_se.x << ", " << v_se.y << "), " << "sw(" << v_sw.x << ", " << v_sw.y << ")" << std::endl;
		return this;
	}

	if (m_se)
	{
		m_se->findAllLeafs();
	}
	if (m_ne)
	{
		m_ne->findAllLeafs();
	}
	if (m_sw)
	{
		m_sw->findAllLeafs();
	}
	if (m_nw)
	{
		m_nw->findAllLeafs();
	}
	return nullptr;
}




