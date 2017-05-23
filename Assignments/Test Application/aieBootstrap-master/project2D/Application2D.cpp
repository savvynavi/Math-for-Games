#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"


Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	m_tankTexture = new aie::Texture("./textures/tankBlue.png");
	m_barrelTexture = new aie::Texture("./textures/barrelBlue.png");
	m_bulletTexture = new aie::Texture("./textures/bullet.png");
	
	m_tankPos = { STARTPOSX, STARTPOSY, STARTPOSZ };
	m_barrelPos = {STARTPOSX, STARTPOSY, STARTPOSZ};
	
	m_tank = new SpriteObject(m_tankTexture);
	m_barrel = new SpriteObject(m_barrelTexture);
	m_root = new SceneObject;

	m_root->addChild(m_tank);
	m_tank->addChild(m_barrel);

	return true;
}

void Application2D::shutdown() {
	delete m_tankTexture;
	delete m_barrelTexture;
	delete m_bulletTexture;
	delete m_2dRenderer;
	delete m_root;
}

void Application2D::update(float deltaTime) {
	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	 //tank movement
	if(input->isKeyDown(aie::INPUT_KEY_LEFT)){
		m_tank->setRotate(deltaTime);
	}
	if(input->isKeyDown(aie::INPUT_KEY_RIGHT)){
		m_tank->setRotate(-deltaTime);
	}

	//accelerates tank in forward (up key) and backwards(down key) direction, 
	if(input->isKeyDown(aie::INPUT_KEY_UP)){
		if((currentSpeed > m_speed) && (canForwards == false)){
			currentSpeed /= (m_deacc * 1.05);
			m_tank->setTranslate(Vector3(0, -currentSpeed, 0));
		} else{
			canForwards = true;
		}

		if(canForwards == true){
			if(currentSpeed >= m_maxSpeed){
				currentSpeed = m_maxSpeed;
			} else{
				currentSpeed += (currentSpeed * m_acc);
			}
			canBackwards = false;
			m_tank->setTranslate(Vector3(0, currentSpeed, 0));
		}
	}else if(input->isKeyDown(aie::INPUT_KEY_DOWN)){
		if((currentSpeed > m_speed) && (canBackwards == false)){
			currentSpeed /= (m_deacc * 1.05);
			m_tank->setTranslate(Vector3(0, currentSpeed, 0));
		} else{
			canBackwards = true;
		}

		if(canBackwards == true){
			if(currentSpeed >= m_maxSpeed){
				currentSpeed = m_maxSpeed;
			}else{
				currentSpeed += (currentSpeed * m_acc);
			}
			canForwards = false;
			m_tank->setTranslate(Vector3(0, -currentSpeed, 0));
		}
	}

	//deaccelerates normally while buttons not pressed
	if(input -> isKeyUp(aie::INPUT_KEY_UP) && (canForwards == true)){
		canBackwards = false;
		if(currentSpeed > m_speed + 0.01){
			currentSpeed /= m_deacc;
			m_tank->setTranslate(Vector3(0, currentSpeed, 0));
		}else{
			currentSpeed = m_speed;
		}
	}

	if(input->isKeyUp(aie::INPUT_KEY_DOWN) && (canBackwards == true)){
		canForwards = false;
		if(currentSpeed > m_speed + 0.01){
			currentSpeed /= m_deacc;
			m_tank->setTranslate(Vector3(0, -currentSpeed, 0));
		} else{
			currentSpeed = m_speed;
		}
	}

	//barrel movement
	if(input->isKeyDown(aie::INPUT_KEY_A)){
		m_barrel->setRotate(deltaTime);
	}
	if(input->isKeyDown(aie::INPUT_KEY_D)){
		m_barrel->setRotate(-deltaTime);
	}
	m_root->update(deltaTime);
	m_root->updateGlobalTransform();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	//draw scene
	m_root->draw(m_2dRenderer);

	// done drawing sprites
	m_2dRenderer->end();
}
