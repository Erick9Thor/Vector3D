#include "../include/Vector3D.h"
#include<assert.h>
#include<iostream>
using namespace std;


Vector3D::Vector3D(const Vector3D& vec)
{
    x = vec.x;
    y = vec.y;
    z = vec.z;
}

Vector3D Vector3D::operator+(const Vector3D& vec)
{
    return Vector3D(x + vec.x, y + vec.y, z + vec.z);
}

Vector3D Vector3D::operator-(const Vector3D& vec)
{
    return Vector3D(x - vec.x, y - vec.y, z - vec.z);
}

Vector3D Vector3D ::operator/(float value)
{
    assert(value != 0);
    return Vector3D(x / value, y / value, z / value);
}

Vector3D& Vector3D::operator/=(float value)
{
    assert(value != 0);
    x /= value;
    y /= value;
    z /= value;
    return *this;
}

Vector3D& Vector3D::operator=(const Vector3D& vec)
{
    x = vec.x;
    y = vec.y;
    z = vec.z;
    return *this;
}

void Vector3D::Normalize()
{
    assert(magnitude() != 0);
    *this /= magnitude();
}

void Vector3D::printCoordinates() const
{
    std::cout << "3D Vector Coordinates: x: " << x
        << "; y: " << y << "; z: " << z << std::endl;
}

float Vector3D::distanceTo(const Vector3D& vec)
{
    return (*this - vec).magnitude();
}

float Vector3D::dotProduct(const Vector3D& vec)
{
    return (x * vec.x + vec.y * y + vec.z * z);
}

Vector3D Vector3D::crossProduct(const Vector3D& vec)
{
    float cpx = x * vec.y - y * vec.x;
    float cpy = y * vec.z - z * vec.y;
    float cpz = z * vec.x - x * vec.z;
    return Vector3D(cpy, cpz, cpx);
}

double Vector3D::angleBetween(const Vector3D& vec)
{
    float dotProduct = this->dotProduct(vec);
    float dotMagnitudes = this->magnitude() * vec.magnitude();
    double res = dotProduct / dotMagnitudes;
    res = (res < -1.0 ? -1.0 : (res > 1.0 ? 1.0 : res));
    double angle = acos(res);
    return angle;
}

float Vector3D::magnitude() const
{
    return sqrt(square());
}

float Vector3D::square() const
{
    return x * x + y * y + z * z;
}