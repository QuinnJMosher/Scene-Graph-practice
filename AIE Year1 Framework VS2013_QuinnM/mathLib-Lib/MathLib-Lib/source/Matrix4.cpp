#include "Matrix4.h"

Matrix4::Matrix4() {
	this->reset();
}

Matrix4::~Matrix4() {}

void Matrix4::reset() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrix[i][j] = 0;
		}
	}

	matrix[0][0] = 1;
	matrix[1][1] = 1;
	matrix[2][2] = 1;
	matrix[3][3] = 1;
}

Matrix4 Matrix4::XRotation(float in_degrees) {
	this->reset();


	if (in_degrees != 0) {
		matrix[1][1] = std::cos(-in_degrees);
		matrix[1][2] = -std::sin(-in_degrees);
		matrix[2][1] = std::sin(-in_degrees);
		matrix[2][2] = std::cos(-in_degrees);
	}

	return *this;
}

Matrix4 Matrix4::YRotation(float in_degrees) {
	this->reset();

	if (in_degrees != 0) {
		matrix[0][0] = std::cos(-in_degrees);
		matrix[0][2] = std::sin(-in_degrees);
		matrix[2][0] = -std::sin(-in_degrees);
		matrix[2][2] = std::cos(-in_degrees);
	}

	return *this;
}

Matrix4 Matrix4::ZRotation(float in_degrees) {
	this->reset();

	if (in_degrees != 0) {
		matrix[0][0] = std::cos(-in_degrees);
		matrix[0][1] = -std::sin(-in_degrees);
		matrix[1][0] = std::sin(-in_degrees);
		matrix[1][1] = std::cos(-in_degrees);
	}

	return *this;
}

Matrix4 Matrix4::Scale(float in_xScale, float in_yScale, float in_zScale) {
	this->reset();

	if (in_xScale > 0) {
		matrix[0][0] = in_xScale;
	}
	if (in_yScale > 0) {
		matrix[1][1] = in_yScale;
	}
	if (in_zScale > 0) {
		matrix[2][2] = in_zScale;
	}

	return *this;
}

Matrix4 Matrix4::TransformVector(float in_xTransform, float in_yTransform, float in_zTransform) {
	this->reset();

	matrix[0][3] = in_xTransform;
	matrix[1][3] = in_yTransform;
	matrix[2][3] = in_zTransform;

	return *this;
}

Matrix4 Matrix4::Transpose() {
	float temp[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp[i][j] = matrix[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrix[i][j] = temp[j][i];
		}
	}

	return *this;
}

Matrix4 Matrix4::OrthoProj(float in_top, float in_bottom, float in_right, float in_left, float in_far, float in_near) {

	matrix[0][0] = 2 / (in_right - in_left);
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[0][3] = -1 * ((in_right + in_left) / (in_right - in_left));

	matrix[1][0] = 0;
	matrix[1][1] = 2 / (in_top - in_bottom);
	matrix[1][2] = 0;
	matrix[1][3] = -1 * ((in_top + in_bottom) / (in_top - in_bottom));

	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = -2 / (in_far - in_near);
	matrix[2][3] = ((in_far + in_near) / (in_far - in_near));

	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 1;

	return (*this);
}

Matrix4 Matrix4::operator+(Matrix4 other) {
	Matrix4 temp = Matrix4();

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
		}
	}

	return temp;
}

Matrix4 Matrix4::operator-(Matrix4 other) {
	Matrix4 temp = Matrix4();

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
		}
	}

	return temp;
}

Matrix4 Matrix4::operator+=(Matrix4 other) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrix[i][j] = matrix[i][j] += other.matrix[i][j];
		}
	}

	return *this;
}

Matrix4 Matrix4::operator-=(Matrix4 other) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrix[i][j] = matrix[i][j] -= other.matrix[i][j];
		}
	}

	return *this;
}

Matrix4 Matrix4::operator*(Matrix4 other) {
	Matrix4 temp = Matrix4();

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp.matrix[i][j] = 0;
			for (int k = 0; k < 4; k++) {
				temp.matrix[i][j] += (matrix[i][k] * other.matrix[k][j]);
			}
		}
	}

	return temp;
}

Matrix4 Matrix4::operator*=(Matrix4 other) {
	Matrix4 temp = Matrix4();

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp.matrix[i][j] = matrix[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrix[i][j] = 0;
			for (int k = 0; k < 4; k++) {
				matrix[i][j] += (temp.matrix[i][k] * other.matrix[k][j]);
			}
		}
	}

	return temp;
}

Vector3 Matrix4::operator*(Vector3 other) {
	Vector3 out = Vector3();

	out.x = (matrix[0][0] * other.x) + (matrix[0][1] * other.y) + (matrix[0][2] * other.z) + matrix[0][3];
	out.y = (matrix[1][0] * other.x) + (matrix[1][1] * other.y) + (matrix[1][2] * other.z) + matrix[1][3];
	out.z = (matrix[2][0] * other.x) + (matrix[2][1] * other.y) + (matrix[2][2] * other.z) + matrix[2][3];

	return out;
}

void Matrix4::Set(int in_col, int in_row, float in_value) {
	if (in_col < 4 && in_row < 4) {
		matrix[in_col][in_row] = in_value;
	}
}

void Matrix4::Set(float in_00, float in_01, float in_02, float in_03, float in_10, float in_11, float in_12, float in_13, float in_20, float in_21, float in_22, float in_23, float in_30, float in_31, float in_32, float in_33) {
	matrix[0][0] = in_00;
	matrix[0][1] = in_01;
	matrix[0][2] = in_02;
	matrix[0][3] = in_03;

	matrix[1][0] = in_10;
	matrix[1][1] = in_11;
	matrix[1][2] = in_12;
	matrix[1][3] = in_13;

	matrix[2][0] = in_20;
	matrix[2][1] = in_21;
	matrix[2][2] = in_22;
	matrix[2][3] = in_23;

	matrix[3][0] = in_30;
	matrix[3][1] = in_31;
	matrix[3][2] = in_32;
	matrix[3][3] = in_33;
}

bool operator==(Matrix4 left, Matrix4 right) {
	bool equality = true;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (std::abs(right.matrix[i][j] - left.matrix[i][j]) > 0.00001) {
				equality = false;
			}
		}
	}
	return equality;
}

bool operator!=(Matrix4 left, Matrix4 right) {
	return !(left == right);
}

std::ostream& operator<<(std::ostream& os, const Matrix4& mx4) {
	os << "[[" << mx4.matrix[0][0] << ", " << mx4.matrix[0][1] << ", " << mx4.matrix[0][2] << ", " << mx4.matrix[0][3] << "]\n";
	os << " [" << mx4.matrix[1][0] << ", " << mx4.matrix[1][1] << ", " << mx4.matrix[1][2] << ", " << mx4.matrix[1][3] << "]\n";
	os << " [" << mx4.matrix[2][0] << ", " << mx4.matrix[2][1] << ", " << mx4.matrix[2][2] << ", " << mx4.matrix[2][3] << "]\n";
	os << " [" << mx4.matrix[3][0] << ", " << mx4.matrix[3][1] << ", " << mx4.matrix[3][2] << ", " << mx4.matrix[3][3] << "]]\n";
	return os;
}