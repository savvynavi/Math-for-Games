#include"MathLib.h"

namespace MathLib{
	double Functions::add(double a, double b){
		return (a + b);
	}

	double Functions::multiply(double a, double b){
		return (a * b);
	}

	double Functions::addMultiply(double a, double b){
		return (a + (a * b));
	}
}