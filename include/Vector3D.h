#pragma once
#include<iostream>
#include<math.h>
#include<assert.h>
using namespace std;

class Vector3D
{
public:
	Vector3D() {
		x = 0;
		y = 0;
		z = 0;
	};

	Vector3D(float x_pass, float y_pass, float z_pass) {
		x = x_pass;
		y = y_pass;
		z = z_pass;
	};

	Vector3D(const Vector3D& vec);


	Vector3D operator+(const Vector3D& vec);
	Vector3D operator-(const Vector3D& vec);
	Vector3D operator/(float value);
	Vector3D& operator/=(float value);
	Vector3D& operator=(const Vector3D& vec);

	void printCoordinates() const;
	void Normalize();
	void distance_to(const Vector3D& vec);

	/*
	void dot_product(const Vector3D& vec);
	void cross_product(const Vector3D& vec);
	void angle_between(const Vector3D& vec);
	*/
private:
	float x, y, z;

	float magnitude();
	float square();
};