#pragma once
#include"Texture.h"
#include"Renderer2D.h"
#include"SceneObject.h"

class SpriteObject : public SceneObject{
public:
	SpriteObject(aie::Texture *texture);
	virtual ~SpriteObject();
	virtual void draw(aie::Renderer2D *renderer);
protected:
	aie::Texture *m_texture;
};