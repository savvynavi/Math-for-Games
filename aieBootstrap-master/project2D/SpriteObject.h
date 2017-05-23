#pragma once
#include"SceneObject.h"

class SpriteObject: public SceneObject{
public:
	SpriteObject(aie::Texture *texture): m_texture(texture){

	}

	virtual ~SpriteObject(){}

	//first draws sprite using global transform, then calls base class draw to the children
	virtual void draw(aie::Renderer2D *renderer){
		renderer->drawSpriteTransformed3x3(m_texture, (float*)&m_globalTransform);
		SceneObject::draw(renderer);
	}
protected:
	aie::Texture *m_texture;
};