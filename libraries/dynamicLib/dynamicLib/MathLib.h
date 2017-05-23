#pragma once

#ifdef MATHLIB_EXPORTS
#define MATHLIB_API__declspec(dllexport)
#else
#define MATHLIB_API__declspec(dllimport)
#endif

namespace MathLib{
	//This class is exported from the mMthLib.dll
	class Functions{
	public:
		static MATHLIB_API double add(double a, double b);
		static MATHLIB_API double multiply(double a, double b);
		static MATHLIB_API double addMultiply(double a, double b);
	};
}