#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include"Vector2.h"
#include<math.h>
#include<stdlib.h>
#include<time.h>

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	srand(time(NULL));
	m_2dRenderer = new aie::Renderer2D();

	m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_shipTexture = new aie::Texture("./textures/ship.png");

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_audio = new aie::Audio("./audio/powerup.wav");

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;
	////ORIGINAL BOUNCING BALL
	//m_shape.x = 200.0f;
	//m_shape.y = 200.0f;

	//m_bouncingBall.x = 300.0f;
	//m_bouncingBall.y = 300.0f;
	//m_bounceDist.x = getWindowWidth() - m_bouncingBall.x;
	//m_bounceDist.y = getWindowHeight() - m_bouncingBall.y;

	//m_accelerationX = 5;
	//m_accelerationY = 5;

	////FRAME INDEPENDANT MOVEMENT MATRIX OF BOUNCING BALLS
	//Vector2 pos(getWindowWidth() / 2, getWindowHeight() / 2);
	//m_circle.setPos(pos);
	//Vector2 dir(5, 5);
	//m_circle.setDir(dir);
	//m_circle.setAcc(5);
	//for(int i = 0; i < 100; i++){
	//	arr[i] = m_circle;
	//	pos.x = rand() % (getWindowWidth() - 10) + 10;
	//	pos.y = rand() % (getWindowHeight() - 10) + 10;
	//	arr[i].setPos(pos);
	//}

	////BASE JUMPER 
	//m_radius = 50;
	//m_player.velocity.x = 0.0f;
	//m_player.velocity.y = 0.0f;
	//m_player.distance = getWindowHeight() - (m_radius + 10);
	//m_acc = 9.8f;
	//m_paraHeight = 0.0f;

	////LINEAR INTERPOLATION STUFF
	m_sprite1 = {200, 300};
	m_sprite2 = {900, 300};
	m_spriteMove = (m_sprite1 + m_sprite2) / 2;
	return true;
}

void Application2D::shutdown() {
	
	delete m_audio;
	delete m_font;
	delete m_texture;
	delete m_shipTexture;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime * 0.3f;
	if(m_timer > 1){
		m_timer = 0;
	}
	// input example
	aie::Input* input = aie::Input::getInstance();

	// use arrow keys to move camera
	//if (input->isKeyDown(aie::INPUT_KEY_UP))
	//	m_cameraY += 500.0f * deltaTime;

	//if (input->isKeyDown(aie::INPUT_KEY_DOWN))
	//	m_cameraY -= 500.0f * deltaTime;

	//if (input->isKeyDown(aie::INPUT_KEY_LEFT))
	//	m_cameraX -= 500.0f * deltaTime;

	//if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
	//	m_cameraX += 500.0f * deltaTime;

	//// example of audio
	//if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	//	m_audio->play();

	//// exit the application
	//if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
	//	quit();

	////FRAME INDEPENDANT MOVEMENT - BOUNCING BALL (multiplying by delta time makes movement per second, slows it down but makes movement more smooth with bad framerate)
	//if it would go outside the window, it reverses it's direction for either axis
	//for(int i = 0; i < 100; i++){
	//	if(arr[i].m_pos.x + 10 > getWindowWidth() || arr[i].m_pos.x - 10 < 0){
	//		arr[i].m_direction.x *= -1;
	//		arr[i].setAcc(arr[i].m_acc + 1);

	//	}
	//	if(arr[i].m_pos.y + 10 > getWindowHeight() || arr[i].m_pos.y - 10 < 0){
	//		arr[i].m_direction.y *= -1;
	//		arr[i].setAcc(arr[i].m_acc + 1);
	//	}
	//	arr[i].m_pos.x += arr[i].m_direction.x * arr[i].m_acc * deltaTime;
	//	arr[i].m_pos.y += arr[i].m_direction.y * arr[i].m_acc * deltaTime;
	//}

	////BASE JUMPER
	////space initiates jummp
	//if(input -> isKeyDown(aie::INPUT_KEY_SPACE)){
	//	m_player.jumpState = true;
	//}

	////initiates parachute
	//if(input -> isKeyDown(aie::INPUT_KEY_ENTER)){
	//	m_player.parachute = true;
	//	m_paraHeight = m_player.distance;
	//}

	////player movement
	//if(m_player.jumpState == true && m_player.distance > 0 + m_radius){
	//	m_player.velocity.x = m_acc * m_timer;
	//	m_player.distance += (0.5) * (-m_acc)* pow(m_timer, 2);
	//}

	//if(m_player.parachute == true){
	//	m_parachute.x = getWindowWidth() * 0.5;
	//	m_parachute.y = m_player.distance + 100 + m_radius;
	//}

	//INTERPOLATION

	m_spriteMove.interpolation(m_sprite1, m_sprite2, m_timer);

	//Vector2 *currentStart;
	//Vector2 *currentEnd;
	//if(m_spriteMove == m_sprite1){
	//	currentStart = &m_sprite1;
	//	currentEnd = &m_sprite2;
	//}else{
	//	currentStart = &m_sprite2;
	//	currentEnd = &m_sprite1;
	//}
	//m_spriteMove.interpolation(*currentStart, *currentEnd, m_timer);

}

void Application2D::draw() {


	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	//setting the colour
	m_2dRenderer->setRenderColour(0.6f, 0, 0.25f);

	//////MAGNITUDE AND NORM STUFF

	//Vector2 mousePos(aie::Input::getInstance() -> getMouseX(), aie::Input::getInstance() -> getMouseY());
	//float pointRadius = 20;
	//m_2dRenderer->drawCircle(mousePos.x, mousePos.y, pointRadius);

	////shape that follows 100 units away
	//Vector2 distVec(mousePos.x - m_shape.x, mousePos.y - m_shape.y);
	//float distance = distVec.getMagnitude();
	//if(distance > 100){
	//	distVec.getNorm();
	//	m_shape.x += distVec.x * 2;
	//	m_shape.y += distVec.y * 2;
	//}else if(distance <= 20){
	//	distVec.getNorm();
	//	m_shape.x -= distVec.x * 5;
	//	m_shape.y -= distVec.y * 5;
	//}

	//m_2dRenderer->setRenderColour(0.25f, 0, 0.6f);
	//m_2dRenderer->drawCircle(m_shape.x, m_shape.y, pointRadius);

	////drawing line between 2 circles 
	//m_2dRenderer->setRenderColour(0.7f, 0.5, 0.0f);
	//m_2dRenderer->drawLine(mousePos.x, mousePos.y, m_shape.x, m_shape.y, 2);
	//
	////////BOUNCING BALL
	//float radius = 50.0f;
	//m_2dRenderer->setRenderColour(0.6f, 0, 0.25f);


	////if it would go outside the window, it reverses it's direction for either axis
	//if(m_bouncingBall.x + radius > getWindowWidth()  || m_bouncingBall.x - radius < 0 ){
	//	m_bounceDist.x *= -1;
	//	m_accelerationX *= 1.08;

	//}
	//if(m_bouncingBall.y + radius > getWindowHeight()  || m_bouncingBall.y - radius < 0 ){
	//	m_bounceDist.y *= -1;
	//	m_accelerationY *= 1.02;
	//}
	//m_bounceDist.getNorm();
	//m_bouncingBall.y += m_bounceDist.y * m_accelerationY;
	//m_bouncingBall.x += m_bounceDist.x * m_accelerationX;

	//m_2dRenderer->drawCircle(m_bouncingBall.x, m_bouncingBall.y, radius);

	////drawing triangle
	//Vector2 v1(100.0f, 500.0f);
	//Vector2 v2(500.0f, 100.0f);
	//Vector2 v3(50.0f, 50.0f);
	//m_2dRenderer->drawLine(v1.x, v1.y, v2.x, v2.y, 2);
	//m_2dRenderer->drawLine(v2.x, v2.y, v3.x, v3.y, 2);
	//m_2dRenderer->drawLine(v3.x, v3.y, v1.x, v1.y, 2);


	//////MATRIX TRANSFORM STUFF
	Matrix3 m1 = {
		1, 0, 0,
		0, 1, 0,
		0, 0, 1
	};

	Matrix3 m3 = m1.setRotateZ(getTime());
	m_2dRenderer->setUVRect(0, 0, 1, 1);
	m_2dRenderer->drawSpriteTransformed3x3(m_shipTexture, (float*)&m3);

	//FRAME INDEPENDANT MOVEMENT BOUNCING BALL MATRIX
	//m_2dRenderer->setRenderColour(0.6f, 0, 0.25f);
	//for(int i = 0; i < 100; i++){
	//	m_2dRenderer->drawCircle(arr[i].m_pos.x, arr[i].m_pos.y, 10);
	//}

	////BASE JUMPER 
	
	//m_2dRenderer->drawCircle(getWindowWidth() * 0.5f, m_player.distance, m_radius);
	//
	//if(m_player.parachute == true){
	//	m_2dRenderer->setRenderColour(0.25f, 0, 0.6f);
	//	m_2dRenderer->drawBox(m_parachute.x, m_parachute.y, 200, 10);
	//	m_2dRenderer->setRenderColour(0.7f, 0.5, 0.0f);
	//	m_2dRenderer->drawLine(getWindowWidth() * 0.5 + m_radius, m_player.distance, m_parachute.x + 70, m_parachute.y - 5);
	//	m_2dRenderer->drawLine(getWindowWidth() * 0.5 - m_radius, m_player.distance, m_parachute.x - 70, m_parachute.y - 5);
	//}

	////rendering text depending on when/if parachute deployed
	//m_2dRenderer->setRenderColour(1, 1, 1);
	//if(m_player.parachute == true && m_paraHeight <= 100 && m_player.distance < 0 + m_radius){
	//	m_2dRenderer->drawText(m_font, "You got injured on landing!", 100, getWindowHeight() * 0.5);
	//}else if(m_player.parachute == true && m_paraHeight > 200 && m_player.distance < 0 + m_radius){
	//	m_2dRenderer->drawText(m_font, "You landed safely!", 100, getWindowHeight() * 0.5);
	//}else if(m_player.parachute == false && m_player.distance < 0 + m_radius){
	//	m_2dRenderer->drawText(m_font, "You died!", 100, getWindowHeight() * 0.5);
	//}


	////LINEAR INTERPOLATION STUFF

	m_2dRenderer->setUVRect(0, 0, 1, 1);
	m_2dRenderer->drawSprite(m_shipTexture, m_sprite1.x, m_sprite1.y);
	m_2dRenderer->drawSprite(m_shipTexture, m_sprite2.x, m_sprite2.y);
	m_2dRenderer->drawSprite(m_shipTexture, m_spriteMove.x, m_spriteMove.y);


	//QUESTION 3 STUFF
	float scale = fmod(getTime(), 3.0f);
	if(scale > 1 && scale < 2){
		scale = 1;
	}
	if(scale > 2){
		scale = 1 - (scale - 2);
	}
	//EASING PART OF THIS...

	//box that scales in size
	m_2dRenderer->setRenderColour(1, 0, 1);
	m_2dRenderer->drawBox(getWindowWidth() * 0.5f, getWindowHeight() * 0.5f, 200 * scale, 200 * scale);

	////DEFAULT EXAMPLE STUFF
	//// demonstrate animation
	//m_2dRenderer->setUVRect(int(m_timer) % 8 / 8.0f, 0, 1.f / 8, 1.f / 8);
	//m_2dRenderer->drawSprite(m_texture, 200, 200, 100, 100);

	//// demonstrate spinning sprite
	//m_2dRenderer->setUVRect(0,0,1,1);
	//m_2dRenderer->drawSprite(m_shipTexture, 600, 400, 0, 0, m_timer, 1);

	//// draw a thin line
	//m_2dRenderer->drawLine(300, 300, 600, 400, 2, 1);

	//// draw a moving purple circle
	//m_2dRenderer->setRenderColour(1, 0, 1, 1);
	//m_2dRenderer->drawCircle(sin(m_timer) * 100 + 600, 150, 50);

	//// draw a rotating red box
	//m_2dRenderer->setRenderColour(1, 0, 0, 1);
	//m_2dRenderer->drawBox(600, 500, 60, 20, m_timer);

	//// draw a slightly rotated sprite with no texture, coloured yellow
	//m_2dRenderer->setRenderColour(1, 1, 0, 1);
	//m_2dRenderer->drawSprite(nullptr, 400, 400, 50, 50, 3.14159f * 0.25f, 1);
	//
	//// output some text, uses the last used colour
	//char fps[32];
	//sprintf_s(fps, 32, "FPS: %i", getFPS());
	//m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	//m_2dRenderer->drawText(m_font, "Press Space for sound!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}