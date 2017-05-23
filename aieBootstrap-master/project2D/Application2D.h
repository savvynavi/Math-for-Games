#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include"Vector2.h"
#include"Matrix2.h"
#include"Vector3.h"
#include"Matrix3.h"

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;
	aie::Audio*			m_audio;
	//Vector2			m_shape;
	//Vector2			m_bouncingBall;
	//Vector2			m_bounceDist;
	//SimpleObject		m_circle;
	//SimpleObject		arr[100];
	//Vector2			m_parachute;
	Vector2				m_sprite1;
	Vector2				m_sprite2;
	Vector2				m_spriteMove;


	float m_cameraX, m_cameraY;
	float m_timer;
	//float m_accelerationY;
	//float m_accelerationX;
	//float m_radius;
	//float m_acc;
};