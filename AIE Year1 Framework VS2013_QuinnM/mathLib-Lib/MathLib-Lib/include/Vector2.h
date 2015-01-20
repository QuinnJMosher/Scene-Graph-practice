#ifndef _Vector2_h_
#define _Vector2_h_

#include <cmath>
#include <iostream>

class Vector2 {

public:
	float x;
	float y;

	//constructs a Vector2 with the fields x and y equal to 0
	Vector2();
	//constructs a Vector2 with field x = in_x and field y = in_y
	Vector2(float in_x, float in_y);
	//destroys the vector2 called upon
	~Vector2() { };

	//returns the dot product of the instance called upon and the given Vector2
	float DotProduct(Vector2 other);
	//returns the dot product of the two given Vector2s
	static float DotProduct(Vector2 in_a, Vector2 in_b);

	//returns a Vector2 containing the cross product of the instance called upon and the given Vector2
	Vector2 CrossProduct(Vector2 other);
	//returns a Vector2 containing the cross product containing the two given Vector2s
	static Vector2 CrossProduct(Vector2 in_a, Vector2 in_b);

	//returns the magnitude of the instance called upon
	float Magnitude();
	//returns the magnitude of the given Vector2
	static float Magnitude(Vector2 input);

	//returns a normalized version of the instance called upon 
	Vector2 Normalize();
	//returns a normalized version of the Vector2 given
	static Vector2 Normalize(Vector2 input);

	//sets the instance called upon to a normalized version of itself
	void NormalizeThis();

	//returns a Vector2 that is in_percent(0 - 1) between the instance called upon and the Vector2 given
	Vector2 Lerp(Vector2 other, float in_percent);
	//returns a Vector2 that is in_percent(0 - 1) between the Vector2s that are given
	static Vector2 Lerp(Vector2 in_first, Vector2 in_second, float in_percent);

	Vector2 operator+(Vector2 other);
	Vector2 operator-(Vector2 other);
	Vector2 operator*(Vector2 other);
	Vector2 operator*(float input);

	void operator+=(Vector2 other);
	void operator-=(Vector2 other);
	void operator*=(Vector2 other);
	void operator*=(float input);

	friend std::ostream& operator<<(std::ostream& os, const Vector2& vec);

};

bool operator==(Vector2 left, Vector2 right);
bool operator!=(Vector2 left, Vector2 right);


#endif