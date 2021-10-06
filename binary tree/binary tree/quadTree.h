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
struct GameObject
	{
		Vector2d m_position;
		std::string m_name;
		GameObject() {};
		GameObject(const Vector2d& position, std::string name)
			: m_position{ position }, m_name{ name } { };

	};

	class QuadTree
	{
	public:
		QuadTree();
		QuadTree(const Vector2d& v1, const Vector2d& v2, const Vector2d& v3, const Vector2d& v4);
		void subDivide(int n);
		void print() const;
		QuadTree* insert(const GameObject& gameObject);
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
		std::vector<GameObject> m_gameObjects;
		bool isLeaft() const;

	};