#include"AABB2.h"
#include"Matrix2.h"
#include<iostream>

AABB2::AABB2(){
	min.x = 100000;
	min.y = 100000;
	max.x = -min.x;
	max.y = -min.y;
}

AABB2::AABB2(Matrix2 points){
	min.x = 100000;
	min.y = 100000;
	max.x = -min.x;
	max.y = -min.y;
	points.transpose();
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			if(points.m[i][j] < min.x){
				min.x = points.m[i][j];
			}
			if(points.m[i][j + 1] < min.y){
				min.y = points.m[i][j + 1];
			}
			if(points.m[i][j] > max.x){
				max.x = points.m[i][j];
			}
			if(points.m[i][j + 1] > max.y){
				max.y = points.m[i][j + 1];
			}
			break;
		}
	}
}

AABB2::~AABB2(){

}

void AABB2::print(){
	std::cout << "min point: (" << min.x << ", " << min.y << ")\n";
	std::cout << "max point: (" << max.x << ", " << max.y << ")\n";
}

//extends bounding box to fit a new point
void AABB2::addPoint(Vector2 &point){
	if(point.x < min.x){
		min.x = point.x;
	}
	if(point.y < min.y){
		min.y = point.y;
	}
	if(point.x > max.x){
		max.x = point.x;
	}
	if(point.y > max.y){
		max.y = point.y;
	}
}

//extends bounding box to fit another bounding box
void AABB2::addAabb(AABB2 &other){
	if(other.min.x < min.x){
		min.x = other.min.x;
	}
	if(other.min.y < min.y){
		min.y = other.min.y;
	}
	if(other.max.x > max.x){
		max.x = other.max.x;
	}
	if(other.max.y > max.y){
		max.y = other.max.y;
	}
}

//returns true if the point is in the AABB
bool AABB2::overlap(Vector2 &point){
	if(min.x <= point.x && point.x <= max.x && min.y <= point.y && point.y <= max.y){
		return true;
	}
	return false;
}

//returns true if they overlap
bool AABB2::overlap(AABB2 &other){
	if((this->max.x < other.min.x) || (other.max.x < this->min.x) || (this->max.y < other.min.y) || (other.max.y < this->min.y)){
		return false;
	}
	return true;
}