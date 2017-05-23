#include"SceneObject.h"
#include<iostream>

SceneObject::SceneObject() : m_parent(nullptr), m_position(5, 5, 0), m_angle(0){

}

SceneObject::~SceneObject(){
	for(auto child : m_children){
		delete child;
	}
}

void SceneObject::setPosition(Vector3 &pos){
	m_position = pos;
}

Vector3 SceneObject::getPosition(){
	return m_position;
}

//adds child objects as long as the one being added doesn't already have a parent
void SceneObject::addChild(SceneObject* child){
	if(child->m_parent == nullptr){
		child->m_parent = this;
		m_children.push_back(child);
	}
}

void SceneObject::update(float deltaTime){
	for(auto child : m_children){
		child->update(deltaTime);
	}
}

void SceneObject::draw(aie::Renderer2D* renderer){
	for(auto child : m_children){
		child->draw(renderer);
	}
}

//updates global transform for object and its children
void SceneObject::updateGlobalTransform(){
	if(m_parent != nullptr){
		m_globalTransform = m_parent->m_globalTransform * m_localTransform;
	}else{
		m_globalTransform = m_localTransform;
	}
	for(auto child : m_children){
		child->updateGlobalTransform();
	}
}

//rotates the local transform
void SceneObject::setRotate(float angle){
	m_angle += angle;
	Matrix3 r;
	r.setRotateZ(m_angle);

	m_rotate = r;
	m_localTransform = (m_translate * m_rotate);
	m_rotate = (m_translate * m_rotate);
}

float SceneObject::getRotate(){
	return m_angle;
}

//will move the object in the direction it's facing
void SceneObject::setTranslate(Vector3 pos){
	m_position += (m_rotate * pos);
	Matrix3 t;
	t.zAxis = Vector3(m_position.x, m_position.y, 0);
	m_translate = t;
	m_localTransform.zAxis = m_position;
}

Vector3 SceneObject::getTranslate(){
	return m_position;
}