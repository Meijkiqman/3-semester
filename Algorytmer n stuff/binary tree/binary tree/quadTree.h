#pragma once
#include <string>
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
		QuadTree(const Vector2d& v1, const Vector2d& v2, const Vector2d& v3, const Vector2d& v4);
		void subDivide(int n);
		//void print() const;
		QuadTree* find(const Vector2d& p);
	private:
		Vector2d m_a;
		Vector2d m_b;
		Vector2d m_c;
		Vector2d m_d;
		QuadTree* m_sw;
		QuadTree* m_se;
		QuadTree* m_nw;
		QuadTree* m_ne;
		bool isLeaft() const;

	};