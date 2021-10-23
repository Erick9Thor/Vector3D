#include "../include/Vector3D.h"
#include<assert.h>


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
    // *this /= magnitude();
}

float Vector3D::magnitude()
{
    return sqrt(square());
}

float Vector3D::square()
{
    return x * x + y * y + z * z;
}
