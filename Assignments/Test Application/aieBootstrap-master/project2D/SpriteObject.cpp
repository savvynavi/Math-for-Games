#include"SpriteObject.h"

SpriteObject::SpriteObject(aie::Texture *texture) : m_texture(texture){

}

SpriteObject::~SpriteObject(){

}

void SpriteObject::draw(aie::Renderer2D *renderer){
	renderer->drawSpriteTransformed3x3(m_texture, (float*)&m_globalTransform);
	SceneObject::draw(renderer);
}