#include"AABB3.h"
#include"Matrix3.h"


AABB3::AABB3(){
	min.x = 100000;
	min.y = 100000;
	min.z = 100000;
	max.x = -min.x;
	max.y = -min.y;
	max.z = -min.z;
}

AABB3::AABB3(Matrix3 points){
	min.x = 100000;
	min.y = 100000;
	min.z = 100000;
	max.x = -min.x;
	max.y = -min.y;
	max.z = -min.z;
	points.transpose();
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(points.m[i][j] < min.x){
				min.x = points.m[i][j];
			}
			if(points.m[i][j + 1] < min.y){
				min.y = points.m[i][j + 1];
			}
			if(points.m[i][j + 2] < min.z){
				min.z = points.m[i][j + 2];
			}
			if(points.m[i][j] > max.x){
				max.x = points.m[i][j];
			}
			if(points.m[i][j + 1] > max.y){
				max.y = points.m[i][j + 1];
			}
			if(points.m[i][j + 2] > max.z){
				max.z = points.m[i][j + 2];
			}
			break;
		}
	}
}

AABB3::~AABB3(){

}

void AABB3::addPoint(Vector3 &point){
	if(point.x < min.x){
		min.x = point.x;
	}
	if(point.y < min.y){
		min.y = point.y;
	}
	if(point.z < min.z){
		min.z = point.z;
	}
	if(point.x > max.x){
		max.x = point.x;
	}
	if(point.y > max.y){
		max.y = point.y;
	}
	if(point.z > max.z){
		max.z = point.z;
	}
}

void AABB3::addAabb(AABB3 &other){
	if(other.min.x < min.x){
		min.x = other.min.x;
	}
	if(other.min.y < min.y){
		min.y = other.min.y;
	}
	if(other.min.z < min.z){
		min.z = other.min.z;
	}
	if(other.max.x > max.x){
		max.x = other.max.x;
	}
	if(other.max.y > max.y){
		max.y = other.max.y;
	}
	if(other.max.z > max.z){
		max.z = other.max.z;
	}
}

bool AABB3::overlap(Vector3 &point){
	if((min.x <= point.x) && (point.x <= max.x) && (min.y <= point.y) && (point.y <= max.y) && (min.z <= point.z) && (point.z <= max.z)){
		return true;
	}
	return false;
}

bool AABB3::overlap(AABB3 &other){
	if((this->max.x < other.min.x) || (other.max.x < this->min.x) || (this->max.y < other.min.y) || (other.max.y < this->min.y) || (this->max.z < other.min.z) || (other.max.z < this->min.z)){
		return false;
	}
	return true;
}