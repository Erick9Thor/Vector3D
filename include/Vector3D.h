#pragma once
#include<iostream>
#include<math.h>
#include<assert.h>
using namespace std;

template <class T>
class Vector3D
{
public:
	Vector3D(): x(T(0)), y(T(0)), z(T(0)) {}

	Vector3D(T x_pass, T y_pass, T z_pass) {
		x = T(x_pass);
		y = T(y_pass);
		z = T(z_pass);
	};

	Vector3D(const Vector3D& vec);
	
	Vector3D<T> operator+(const Vector3D<T>& vec);
	Vector3D<T> operator-(const Vector3D<T>& vec);
	Vector3D<T> operator/(T value);
	Vector3D<T>& operator/=(T value);
	Vector3D<T>& operator=(const Vector3D<T>& vec);
	
	void printCoordinates() const;

	void Normalize();

	T distanceTo(const Vector3D<T>& vec);
	T dotProduct(const Vector3D<T>& vec);
	Vector3D crossProduct(const Vector3D<T>& vec);
	double angleBetween(const Vector3D& vec);
	
private:
	T x, y, z;

	T magnitude() const;
	T square() const;
};

template<class T>
Vector3D<T>::Vector3D(const Vector3D<T>& vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
}

template<class T>
inline Vector3D<T> Vector3D<T>::operator+(const Vector3D<T>& vec)
{
	return Vector3D<T>(x + vec.x, y + vec.y, z + vec.z);
}

template<class T>
inline Vector3D<T> Vector3D<T>::operator-(const Vector3D<T>& vec)
{
	return Vector3D(x - vec.x, y - vec.y, z - vec.z);
}

template<class T>
inline Vector3D<T> Vector3D<T>::operator/(T value)
{
	assert(value != 0);
	return Vector3D(x / value, y / value, z / value);
}

template <class T>
Vector3D<T>& Vector3D<T>::operator=(const Vector3D<T>& vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
	return *this;
}

template <class T>
Vector3D<T>& Vector3D<T>::operator/=(T value)
{
	assert(value != 0);
	x /= value;
	y /= value;
	z /= value;
	return *this;
}


template<class T>
inline void Vector3D<T>::printCoordinates() const
{
	std::cout << "3D Vector Coordinates: x: " << x
		<< "; y: " << y << "; z: " << z << std::endl;
}

template<class T>
void Vector3D<T>::Normalize()
{
	assert(magnitude() != 0);
	*this /= magnitude();
}

template<class T>
inline T Vector3D<T>::distanceTo(const Vector3D& vec)
{
	return (*this - vec).magnitude();
}

template<class T>
inline T Vector3D<T>::dotProduct(const Vector3D& vec)
{
	return (x * vec.x + vec.y * y + vec.z * z);
}

template<class T>
inline Vector3D<T> Vector3D<T>::crossProduct(const Vector3D& vec)
{
	T cpx = x * vec.y - y * vec.x;
	T cpy = y * vec.z - z * vec.y;
	T cpz = z * vec.x - x * vec.z;
	return Vector3D(cpy, cpz, cpx);
}

template <class T>
inline double Vector3D<T>::angleBetween(const Vector3D<T>& vec)
{
	T dotProduct = this->dotProduct(vec);
	T dotMagnitudes = this->magnitude() * vec.magnitude();
	T res = dotProduct / dotMagnitudes;
	res = (float)(res < -1.0 ? -1.0 : (res > 1.0 ? 1.0 : res));
	double angle = acos(res);
	return angle;
}

template <class T>
T Vector3D<T>::magnitude() const
{
	return sqrt(square());
}

template <class T>
T Vector3D<T>::square() const
{
	return x * x + y * y + z * z;
}
