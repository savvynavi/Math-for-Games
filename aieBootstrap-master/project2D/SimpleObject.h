#pragma once
#include"Vector2.h"

class SimpleObject{
public:
	SimpleObject() : m_pos(0, 0), m_direction(1, 0){}
	SimpleObject(Vector2 pos, Vector2 direction) : m_pos(pos), m_direction(direction.getNorm()){}
	
	//sets direction after normalising it
	void setDir(Vector2 dir){
		dir.getNorm();
		m_direction = dir;
	}
	
	//sets position
	void setPos(Vector2 pos){
		m_pos = pos;
	}

	void setAcc(float acc){
		if(acc >= 20){
			m_acc = 20;
		}else{
			m_acc = acc;
		}

	}
//protected:
	Vector2 m_pos;
	Vector2 m_direction;
	float m_acc;
};