#pragma once
#include"Vector2.h"

class BaseJumper{
public:
	BaseJumper();
	BaseJumper(float dist, Vector2 v);
	~BaseJumper();

	Vector2 velocity;
	float distance;
	bool jumpState;
	bool parachute;
};