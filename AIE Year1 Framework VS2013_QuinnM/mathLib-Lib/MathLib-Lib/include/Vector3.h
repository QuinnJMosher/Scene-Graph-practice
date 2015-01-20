#ifndef _Vector3_h_
#define _Vector3_h_

#include <cmath>
#include <iostream>

class Vector3 {

public:
	float x;
	float y;
	float z;

	//constructs a Vector3 with the fields x, y and z equal to 0
	Vector3();
	//constructs a Vector3 with field x = in_x, field y = in_y and field z = in_z 
	Vector3(float in_x, float in_y, float in_z);
	//destroys the vector3 called upon
	~Vector3() { };

	//returns the dot product of the instance called upon and the given Vector3
	float DotProduct(Vector3 other);
	//returns the dot product of the two given Vector3s
	static float DotProduct(Vector3 in_a, Vector3 in_b);

	//returns a Vector3 containing the cross product of the instance called upon and the given Vector3
	Vector3 CrossProduct(Vector3 other);
	//returns a Vector3 containing the cross product containing the two given Vector3s
	static Vector3 CrossProduct(Vector3 in_a, Vector3 in_b);

	//returns the magnitude of the instance called upon
	float Magnitude();
	//returns the magnitude of the given Vector3
	static float Magnitude(Vector3 input);

	//returns a normalized version of the instance called upon
	Vector3 Normalize();
	//returns a normalized version of the Vector3 given
	static Vector3 Normalize(Vector3 input);

	//sets the instance called upon to a normalized version of itself
	void NormalizeThis();

	//returns a Vector3 that is in_percent(0 - 1) between the instance called upon and the Vector3 given
	Vector3 Lerp(Vector3 other, float in_percent);
	//returns a Vector3 that is in_percent(0 - 1) between the Vector3s that are given
	static Vector3 Lerp(Vector3 in_first, Vector3 in_second, float in_percent);

	Vector3 operator+(Vector3 other);
	Vector3 operator-(Vector3 other);
	Vector3 operator*(Vector3 other);
	Vector3 operator*(float input);

	void operator+=(Vector3 other);
	void operator-=(Vector3 other);
	void operator*=(Vector3 other);
	void operator*=(float input);

	friend std::ostream& operator<<(std::ostream& os, const Vector3& vec);

};

bool operator==(Vector3 left, Vector3 right);
bool operator!=(Vector3 left, Vector3 right);



#endif