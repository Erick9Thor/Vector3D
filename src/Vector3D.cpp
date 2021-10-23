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

float Vector3D::dot_product(const Vector3D& vec)
{
    std::cout << "Dot product between: ";
    this->printCoordinates();
    std::cout << "and: ";
    vec.printCoordinates();
    std::cout << "is: ";

    std::cout << (x * vec.x + vec.y * y + vec.z * z) << std::endl;

    return (x * vec.x + vec.y * y + vec.z * z);
}

void Vector3D::cross_product(const Vector3D& vec)
{
    
    std::cout << "Cross product between: ";
    this->printCoordinates();
    std::cout << "and: ";
    vec.printCoordinates();
    std::cout << "is: ";

    float cpx = x * vec.y - y * vec.x;
    float cpy = y * vec.z - z * vec.y;
    float cpz = z * vec.x - x * vec.z;
    Vector3D(cpy, cpz, cpx).printCoordinates();
}

float Vector3D::angle_between(const Vector3D& vec)
{
    float angle;

    std::cout << "Angle between: ";
    this->printCoordinates();
    std::cout << "and: ";
    vec.printCoordinates();

    angle = acos(dot_product(vec) / (this->magnitude() * vec.magnitude()));

    std::cout << angle << std::endl;

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