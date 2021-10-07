#include <iostream>
#include "QuadTree.h"

QuadTree* QuadTree::find(const Vector2d& p)
{
	if (isLeaft())
	{
		return this;
	}
	else
	{
		Vector2d m = (m_a + m_c) / 2;
		if (p.y < m.y)
		{
			if (p.x < m.x)
				m_sw->find(p);
			else
				m_se->find(p);
		}
		else
		{
			if (p.x < m.x)
			{
				m_nw->find(p);
			}
			else
			{
				m_ne->find(p);
			}
		}
	}
}