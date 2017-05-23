#pragma once
#include"Matrix2.h"
#include"Vector2.h"
#include"AABB2.h"

class Circle{
public:
	Circle();
	Circle(Matrix2 points);
	~Circle();
	void print();
	Vector2 getCentre();
	float getRadius();
	void addPoint(Vector2 &point);
	void addCircle(Circle &other);
	bool overlap(Vector2 &other);
	bool overlap(Circle &other);
	bool overlap(AABB2 &other);
	float clamp(float c, float min, float max);
private:
	Vector2 m_centre;
	float m_radius;
};