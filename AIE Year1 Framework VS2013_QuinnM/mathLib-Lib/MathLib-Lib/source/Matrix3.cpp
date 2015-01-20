#include "Matrix3.h"

Matrix3::Matrix3() {
	this->reset();
}

Matrix3::~Matrix3() {}

void Matrix3::reset() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix[i][j] = 0;
		}
	}
	matrix[0][0] = 1;
	matrix[1][1] = 1;
	matrix[2][2] = 1;
}

Matrix3 Matrix3::Rotation(float in_degrees) {
	this->reset();

	if (in_degrees != 0) {
		matrix[0][0] = std::cos(in_degrees);
		matrix[1][0] = std::sin(in_degrees);
		matrix[0][1] = -(std::sin(in_degrees));
		matrix[1][1] = std::cos(in_degrees);
	}

	return *this;
}

Matrix3 Matrix3::Scale(float in_xScale, float in_yScale) {
	this->reset();

	if (in_xScale > 0) {
		matrix[0][0] = in_xScale;
	}
	if (in_yScale > 0) {
		matrix[1][1] = in_yScale;
	}

	return *this;
}

Matrix3 Matrix3::TransformVector(float in_xTransform, float in_yTransform) {
	this->reset();

	matrix[0][2] = in_xTransform;
	matrix[1][2] = in_yTransform;

	return *this;
}

Matrix3 Matrix3::Transpose() {
	float temp[3][3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			temp[i][j] = matrix[i][j];
		}
	}
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix[i][j] = temp[j][i];
		}
	}

	return *this;
}

Matrix3 Matrix3::operator+(Matrix3 other) {
	Matrix3 temp = Matrix3();

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			temp.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
		}
	}

	return temp;
}
Matrix3 Matrix3::operator-(Matrix3 other) {
	Matrix3 temp = Matrix3();

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			temp.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
		}
	}

	return temp;
}

Matrix3 Matrix3::operator+=(Matrix3 other) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix[i][j] += other.matrix[i][j];
		}
	}

	return *this;
}
Matrix3 Matrix3::operator-=(Matrix3 other) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix[i][j] -= other.matrix[i][j];
		}
	}

	return *this;
}

Matrix3 Matrix3::operator*(Matrix3 other) {
	Matrix3 temp = Matrix3();

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			temp.matrix[i][j] = 0;
			for (int k = 0; k < 3; k++) {
				temp.matrix[i][j] += (matrix[i][k] * other.matrix[k][j]);
			}
		}
	}

	return temp;
}
Matrix3 Matrix3::operator*=(Matrix3 other) {
	Matrix3 temp = Matrix3();

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			temp.matrix[i][j] = matrix[i][j];
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix[i][j] = 0;
			for (int k = 0; k < 3; k++) {
				matrix[i][j] += (temp.matrix[i][k] * other.matrix[k][j]);
			}
		}
	}

	return temp;
}

Vector2 Matrix3::operator*(Vector2 other) {
	Vector2 out = Vector2();

	out.x = (matrix[0][0] * other.x) + (matrix[0][1] * other.y) + matrix[0][2];
	out.y = (matrix[1][0] * other.x) + (matrix[1][1] * other.y) + matrix[1][2];

	return out;
}

void Matrix3::Set(int in_col, int in_row, float in_value) {
	if (in_col < 3 && in_row < 3) {
		matrix[in_col][in_row] = in_value;
	}
}

void Matrix3::Set(float in_00, float in_01, float in_02, float in_10, float in_11, float in_12, float in_20, float in_21, float in_22) {
	matrix[0][0] = in_00;
	matrix[0][1] = in_01;
	matrix[0][2] = in_02;

	matrix[1][0] = in_10;
	matrix[1][1] = in_11;
	matrix[1][2] = in_12;

	matrix[2][0] = in_20;
	matrix[2][1] = in_21;
	matrix[2][2] = in_22;
}

bool operator==(Matrix3 right, Matrix3 left) {
	bool equality = true;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (std::abs(right.matrix[i][j] - left.matrix[i][j]) > 0.00001) {
				equality = false;
			}
		}
	}
	return equality;
}

bool operator!=(Matrix3 right, Matrix3 left) {
	return !(right == left);
}

std::ostream& operator<<(std::ostream& os, const Matrix3& mx3) {
	os << "[[" << mx3.matrix[0][0] << ", " << mx3.matrix[0][1] << ", " << mx3.matrix[0][2] << "]\n";
	os << " [" << mx3.matrix[1][0] << ", " << mx3.matrix[1][1] << ", " << mx3.matrix[1][2] << "]\n";
	os << " [" << mx3.matrix[2][0] << ", " << mx3.matrix[2][1] << ", " << mx3.matrix[2][2] << "]]\n";
	return os;
}