#pragma once
#include"Matrix3.h"
#include"Renderer2D.h"
#include<vector>

#define STARTPOSX 0
#define STARTPOSY 0
#define STARTPOSZ 0
#define STARTANGLE 0

class SceneObject{
public:
	SceneObject();
	virtual ~SceneObject();

	void setPosition(Vector3 &pos);
	Vector3 getPosition();
	void addChild(SceneObject* child);
	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D* renderer);
	virtual  void updateGlobalTransform();
	void setRotate(float angle);
	float getRotate();
	void setTranslate(Vector3 pos);
	Vector3 getTranslate();

protected:
	Matrix3 m_globalTransform;
	Matrix3 m_localTransform;
	Vector3 m_position;
	float m_angle;
	Matrix3 m_rotate;
	Matrix3 m_translate;

	SceneObject *m_parent;
	std::vector<SceneObject*> m_children;
};