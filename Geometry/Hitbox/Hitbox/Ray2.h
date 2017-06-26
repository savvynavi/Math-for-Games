#pragma once
#include"Vector2.h"

class Ray2{
public:
	Ray2();
	~Ray2();
private:
	Vector2 m_origin;
	Vector2 m_direction;
	float m_length;
};