#include "Application2D.h"


int main() {
	
	auto app = new Application2D();
	app->run("AIE", 1280, 720, false);
	//app->run("AIE", 720, 850, false); //for base jump exercise
	delete app;

	return 0;
}