#include "MathUtil.h"
#include <cmath>
namespace Maths 
{
	bool closeEnough(const float left, const float right)
	{
		const float THRESHOLD = 0.000001f;
		if (abs(left - right) <= THRESHOLD)
			return true;
		return false;
	}
	float LinearInterpolate(const float a, const float b, const float m)
	{
		return a*(1 - m) + b*m;
	}

	double LinearInterpolate(const double a, const double b, const double m)
	{
		return a*(1 - m) + b*m;
	}
}