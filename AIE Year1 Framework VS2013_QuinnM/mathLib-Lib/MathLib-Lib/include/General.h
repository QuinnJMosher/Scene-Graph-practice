#include <cmath>

#ifndef _General_h_
#define _General_h_

class General {
public:
	//Returns a scalar that is in_percent(0 - 1)% between in_begin and in_end
	static float Lerp(float in_begin, float in_end, float in_percent);

	//returns the Degree equivalent of in_radians
	static float ToDegrees(float in_radians);
	//returns the Radian equivalent of in_Degrees
	static float ToRadians(float in_Degrees);

	//returns the closest power of two to in_scalar
	static float ShiftPowOfTwo(float in_scalar);
};

#endif