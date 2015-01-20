#include <cmath>
#include <iostream>

#ifndef _Vector4_h_
#define _Vector4_h_

class Vector4 {
public:
	float w;
	float x;
	float y;
	float z;

	//constructs a Vector4 with the fields w,  x, y and z equal to 0
	Vector4();
	//constructs a Vector4 with field x = in_x, field y = in_y, field z = in_z and field w = in_w
	Vector4(float in_x, float in_y, float in_z, float in_w);
	//destroys the vector4 called upon
	~Vector4();

	//returns a Vector4 with field w = in_alpha / 250 field x = in_red / 250, field y = in_Green / 250 and field z = in_Blue / 250
	static Vector4 ConstructFromColor(float in_Alpha, float in_Red, float in_Green, float in_Blue);
	//converts a hexadecimal number into a Vector4
	static Vector4 ConstructFromColor(unsigned int in_hexColor);

	//returns the magnitude of the instance called upon
	float Magnitude();
	//returns the magnitude of the given Vector4
	static float Magnitude(Vector4 input);

	//returns a normalized version of the instance called upon
	Vector4 Normalize();
	//returns a normalized version of the vector4 given
	static Vector4 Normalize(Vector4 input);

	friend std::ostream& operator<<(std::ostream& os, const Vector4& vec);
};


bool operator==(Vector4 left, Vector4 right);
bool operator!=(Vector4 left, Vector4 right);

#endif