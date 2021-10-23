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

void Vector3D::distance_to(const Vector3D& vec)
{
    std::cout << "Distance to: ";
    this->printCoordinates();
    std::cout << "and: ";
    vec.printCoordinates();
    std::cout << "is: " << (*this - vec).magnitude() << std::endl;
}

float Vector3D::magnitude()
{
    return sqrt(square());
}

float Vector3D::square()
{
    return x * x + y * y + z * z;
}