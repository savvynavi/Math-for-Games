#include"Circle.h"
#include<iostream>
#include<math.h>

Circle::Circle(){
	m_centre = { 0, 0 };
	m_radius = 0.0f;
}

Circle::Circle(Matrix2 points){
	m_centre.x = (points.xAxis.x + points.xAxis.y) / 2;
	m_centre.y = (points.yAxis.x + points.yAxis.y) / 2;
	Vector2 a(points.xAxis.x, points.yAxis.x);
	Vector2 b(points.xAxis.y, points.yAxis.y);
	float magA = a.magnitude(m_centre);
	float magB = b.magnitude(m_centre);
	if(magB >= magA){
		m_radius = magB;
	} else{
		m_radius = magA;
	}
}

Circle::~Circle(){

}

//prints out centre and radius
void Circle::print(){
	std::cout << "centre: " << m_centre.x << ", " << m_centre.y << ", radius: " << m_radius << std::endl;
}

Vector2 Circle::getCentre(){
	return m_centre;
}

float Circle::getRadius(){
	return m_radius;
}

//adds a point to the circle, expands if needed
void Circle::addPoint(Vector2 &point){
	if(point.magnitude(m_centre) > m_radius){
		m_radius = point.magnitude(m_centre);
	}
}

//sets radius to the larger raduis + half magnitude, then finds new centre point
void Circle::addCircle(Circle &other){
	if(other.getCentre().magnitude(m_centre) + other.getRadius() > this->m_radius){
		if(other.getRadius() > this->getRadius()){
			this->m_radius = (this->getCentre().magnitude(other.getCentre()) / 2) + other.getRadius();
		} else{
			this->m_radius = (this->getCentre().magnitude(other.getCentre()) / 2) + this->getRadius();
		}
		this->m_centre.x = (other.getCentre().x + this->getCentre().x) / 2;
		this->m_centre.y = (other.getCentre().y + this->getCentre().y) / 2;
	}
}

//returns true if the point overlaps with the circle
bool Circle::overlap(Vector2 &other){
	if(this->getCentre().magnitude(other) <= this->getRadius()){
		return true;
	}
	return false;
}

//returns true if the circle overlaps with another circle
bool Circle::overlap(Circle &other){
	if(other.getRadius() + this->getRadius() >= this->getCentre().magnitude(other.getCentre())){
		return true;
	}
	return false;
}

//return true if a circle overlaps with an AABB2
bool Circle::overlap(AABB2 &other){
	Vector2 midpoint = m_centre;
	midpoint.x = clamp(this->m_centre.x, other.min.x, other.max.x);
	midpoint.y = clamp(this->m_centre.y, other.min.y, other.max.y);
	if(this->overlap(midpoint) == true){
		return true;
	}
	return false;
}

//clamps value for overlap AABB
float Circle::clamp(float c, float min, float max){
	if(c < min){
		c = min;
	}else if(c > max){
		c = max;
	}
	return c;
}