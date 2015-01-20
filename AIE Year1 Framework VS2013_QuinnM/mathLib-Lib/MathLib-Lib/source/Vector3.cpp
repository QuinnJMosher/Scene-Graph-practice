#include "Vector3.h"

Vector3::Vector3() {
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector3::Vector3(float in_x, float in_y, float in_z) {
	this->x = in_x;
	this->y = in_y;
	this->z = in_z;
}

float Vector3::DotProduct(Vector3 other) {
	return ((this->x * other.x) + (this->y * other.y) + (this->z * other.z));
}

float Vector3::DotProduct(Vector3 in_a, Vector3 in_b) {
	return ((in_a.x * in_b.x) + (in_a.y * in_b.y) + (in_a.z * in_b.z));
}

Vector3 Vector3::CrossProduct(Vector3 other) {
	return Vector3((this->y * other.z) - (this->z * other.y), (this->z * other.x) - (this->x * other.z), (this->x * other.y) - (this->y * other.x));
}

Vector3 Vector3::CrossProduct(Vector3 in_a, Vector3 in_b) {
	return Vector3((in_a.y * in_b.z) - (in_a.z * in_b.y), (in_a.z * in_b.x) - (in_a.x * in_b.z), (in_a.x * in_b.y) - (in_a.y * in_b.x));
}

float Vector3::Magnitude() {
	return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

float Vector3::Magnitude(Vector3 input) {
	return sqrt(pow(input.x, 2) + pow(input.y, 2) + pow(input.z, 2));

}

Vector3 Vector3::Normalize() {
	if (this->Magnitude() != 0) {
		float normalX = this->x / this->Magnitude();
		float normalY = this->y / this->Magnitude();
		float normalZ = this->z / this->Magnitude();
	
		return Vector3(normalX, normalY, normalZ);
	}
	return Vector3();
}

Vector3 Vector3::Normalize(Vector3 input) {
	if (input.Magnitude() != 0) {
		float normalX = input.x / input.Magnitude();
		float normalY = input.y / input.Magnitude();
		float normalZ = input.z / input.Magnitude();

		return Vector3(normalX, normalY, normalZ);
	}
	return Vector3();
}

void Vector3::NormalizeThis() {//edits the vector3 called upon instead of outputing
	if (this->Magnitude() != 0) {
		float normalX = this->x / this->Magnitude();
		float normalY = this->y / this->Magnitude();
		float normalZ = this->z / this->Magnitude();

		this->x = normalX;
		this->y = normalY;
		this->z = normalZ;
		return;
	}
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector3 Vector3::Lerp(Vector3 other, float in_percent) {
	float outX = other.x - x;
	outX *= in_percent;
	outX += x;

	float outY = other.y - y;
	outY *= in_percent;
	outY += y;

	float outZ = other.z - z;
	outZ *= in_percent;
	outZ += z;

	return Vector3(outX, outY, outZ);
}

Vector3 Vector3::Lerp(Vector3 in_first, Vector3 in_second, float in_percent) {
	float outX = in_second.x - in_first.x;
	outX *= in_percent;
	outX += in_first.x;

	float outY = in_second.y - in_first.y;
	outY *= in_percent;
	outY += in_first.y;

	float outZ = in_second.z - in_first.z;
	outZ *= in_percent;
	outZ += in_first.z;

	return Vector3(outX, outY, outZ);
}

Vector3 Vector3::operator+(Vector3 other) {
	return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
}

Vector3 Vector3::operator-(Vector3 other) {
	return Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
}

Vector3 Vector3::operator*(Vector3 other){
	return Vector3(this->x * other.x, this->y * other.y, this->z * other.z);
}

Vector3 Vector3::operator*(float input) {
	return Vector3(this->x * input, this->y * input, this->z * input);
}

void Vector3::operator+= (Vector3 other) {
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
}

void Vector3::operator-=(Vector3 other) {
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
}

void Vector3::operator*=(Vector3 other) {
	this->x *= other.x;
	this->y *= other.y;
	this->z *= other.z;
}

void Vector3::operator*=(float input) {
	this->x *= input;
	this->y *= input;
	this->z *= input;
}

bool operator==(Vector3 left, Vector3 right) {
	float error = 0.00001f;
	if (std::abs(left.x - right.x) <= error) {
		if (std::abs(left.y - right.y) <= error) {
			if (std::abs(left.z - right.z) <= error) {
				return true;
			}
		}
	}
	return false;
}

bool operator!=(Vector3 left, Vector3 right) {
	return !(left == right);
}

std::ostream& operator<<(std::ostream& os, const Vector3& vec) {
	os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
	return os;
}