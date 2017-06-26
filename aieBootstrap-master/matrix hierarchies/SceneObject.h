#pragma once
#include"Matrix3.h"
#include"Renderer2D.h"
#include<vector>

class SceneObject{
public:
	SceneObject() : m_parent(nullptr) {}
	virtual ~SceneObject() {
		for(auto child : m_children){
			delete child;
		}
	}

	//adds child objects as long as the one being added doesn't already have a parent
	virtual void addChild(SceneObject *child){
		if(child -> m_parent == nullptr){
			child->m_parent = this;
			m_children.push_back(child);
		}
	}

	//updates global transform
	virtual void updateGlobalTransform(){
		if(m_parent != nullptr){
			m_globalTransform = m_parent->m_globalTransform * m_localTransform;
		}else{
			m_globalTransform = m_localTransform;
		}
		for(auto child : m_children){
			child->updateGlobalTransform;
		}
	}

	virtual void update(float deltaTime){
		for(auto child : m_children){
			child->update(deltaTime);
		}
	}

	virtual void draw(aie::Renderer2D* renderer){
		for(auto child : m_children){
			child->draw(renderer);
		}
	}
protected:
	Matrix3 m_globalTransform;
	Matrix3 m_localTransform;
	SceneObject *m_parent;
	std::vector<SceneObject*> m_children;
};