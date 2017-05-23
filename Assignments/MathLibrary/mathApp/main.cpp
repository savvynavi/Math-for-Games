#include<iostream>
#include"Vector3.h"
#include"Matrix3.h"
#include"Vector2.h"
#include"Matrix2.h"
#include"Vector4.h"
using namespace std;

int main(){
	Matrix2 m1(5, 10, 15, 20);
	Vector2 v1(2, 4);
	Vector2 v2 = m1 * v1;
	cout << v2.x << " " << v2.y << " " << endl;
	system("pause");
	return 0;
}