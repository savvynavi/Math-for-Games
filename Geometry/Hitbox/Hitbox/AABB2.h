#pragma once
#include"Vector2.h"
#include"Matrix2.h"

class AABB2{
public:
	AABB2();
	AABB2(Matrix2 points);
	~AABB2();
	void print();
	void addPoint(Vector2 &point);
	void addAabb(AABB2 &other);
	bool overlap(Vector2 &point);
	bool overlap(AABB2 &other);
	Vector2 min;
	Vector2 max;
};