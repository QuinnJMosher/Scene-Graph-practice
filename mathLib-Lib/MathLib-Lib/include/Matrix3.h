#include "Vector2.h"
#include <cmath>

#ifndef _Matrix3_h_
#define _Matrix3_h_

class Matrix3 {
public:
	//creates a Matrix3 in identity form
	Matrix3();
	//destroys instantiated Matrix3
	~Matrix3();

	//creates and sets a matrix for the given degrees
	Matrix3 Rotation(float in_degrees);
	//creates and sets a matrix to scale the given amount
	Matrix3 Scale(float in_xScale, float in_yScale);
	//creates and sets a matrix to transform a vector the given amount
	Matrix3 TransformVector(float in_xTransform, float in_yTransform);
	//transposes the instance called upon
	Matrix3 Transpose();

	//sets the matrix at [in_col][in_row] to in_value
	void Set(int in_col, int in_row, float in_value);
	//sets the matrix to the given values
	void Set(float in_00, float in_01, float in_02, float in_10, float in_11, float in_12, float in_20, float in_21, float in_22);

	Matrix3 operator+(Matrix3 other);
	Matrix3 operator-(Matrix3 other);
	Matrix3 operator+=(Matrix3 other);
	Matrix3 operator-=(Matrix3 other);

	Matrix3 operator*(Matrix3 other);
	Matrix3 operator*=(Matrix3 other);

	Vector2 operator*(Vector2 other);

	friend std::ostream& operator<<(std::ostream& os, const Matrix3& mx3);

	float matrix[3][3];

private:
	void reset();
};

bool operator==(Matrix3 right, Matrix3 left);
bool operator!=(Matrix3 right, Matrix3 left);

#endif