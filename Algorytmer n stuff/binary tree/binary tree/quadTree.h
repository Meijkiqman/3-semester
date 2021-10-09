#pragma once
#include <vector>


struct Vector2d
{
	double x;
	double y;
	Vector2d operator + (const Vector2d& v) const
	{
		Vector2d u;
		u.x = v.x;
		u.y = v.y;
		return u;
	}
	Vector2d operator / (int d)
	{
		Vector2d u;
		u.x = x / d;
		u.y = y / d;
		return u;
	}
	

};

	class QuadTree
	{
	public:
		QuadTree();
		QuadTree* findAllLeafs();
		QuadTree(const Vector2d& v1, const Vector2d& v2, const Vector2d& v3, const Vector2d& v4);
		void subDivide(int n);
		
		bool isLeaf() const;
		QuadTree* find(const Vector2d& p);
		Vector2d v_sw;
		Vector2d v_se;
		Vector2d v_nw;
		Vector2d v_ne;
		QuadTree* m_sw;
		QuadTree* m_se;
		QuadTree* m_nw;
		QuadTree* m_ne;
	

	};