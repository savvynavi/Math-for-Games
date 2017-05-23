#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include"Vector3.h"
#include"Matrix3.h"
#include"SceneObject.h"
#include"SpriteObject.h"


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
	aie::Texture*		m_tankTexture;
	aie::Texture*		m_barrelTexture;
	aie::Texture*		m_bulletTexture;
	SpriteObject*		m_tank;
	SpriteObject*		m_barrel;
	SceneObject*		m_root;
	Vector3				m_tankPos;
	Vector3				m_barrelPos;
	const float			m_speed = 0.05;
	float				currentSpeed = m_speed;
	const float			m_maxSpeed = 3;
	const float			m_acc = 0.03;
	const float			m_deacc = 1.01;
	bool				canBackwards = true;
	bool				canForwards = true;

	float m_timer;
};