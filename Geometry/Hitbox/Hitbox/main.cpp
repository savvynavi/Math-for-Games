#include<iostream>
#include"Circle.h"
#include"Matrix2.h"
#include"Vector2.h"
#include"AABB2.h"
#include"AABB3.h"
#include"Ray2.h"

using namespace std;

int main(){
	Matrix2 mat1(90, 0, 70, 0);
	Circle circle1(mat1);
	circle1.print();
	Matrix2 mat2(2, 5, 6, 10);
	AABB2 box1(mat2);
	box1.print();

	if(circle1.overlap(box1) == true){
		cout << "Overlap!\n";
	}else{
		cout << "No Overlap!\n";
	}

	system("pause");
	return 0;
}