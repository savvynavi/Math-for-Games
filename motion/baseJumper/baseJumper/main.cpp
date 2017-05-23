#include<iostream>
#include"BaseJumper.h"
#include"Vector2.h"
#include<math.h>
using namespace std;

//most likely calculating wrong, fix
int main(){
	BaseJumper p;
	float acc = 9.8f;
	float u = 0.0f;
	float t = 0.0f;


	for(int i = 0; i <= 12; i++){
		p.velocity.x = (acc)*(t);
		p.distance = (0.5) * (acc)* pow(t, 2);
		t += 0.5f;
		cout << "Distance travelled: " << p.distance << "\t Velocity: " << p.velocity.x << endl;
	}

	system("pause");
	return 0;
}