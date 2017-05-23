#pragma once
#include"Vector3.h"
#include"Matrix3.h"

class AABB3{
public:
	AABB3();
	AABB3(Matrix3 points);
	~AABB3();
	void addPoint(Vector3 &point);
	void addAabb(AABB3 &other);
	bool overlap(Vector3 &point);
	bool overlap(AABB3 &other);
	Vector3 min;
	Vector3 max;
};