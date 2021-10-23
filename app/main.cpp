#include <iostream>
#include "../include/Vector3D.h"

int main()
{
    std::cout << "Hello World!\n";

	Vector3D a, b, c, d;

	a = Vector3D();

	b = Vector3D(1, 0, 1);

	c = Vector3D(b);

	d = a + c;

	d.Normalize();

	d.distance_to(b);

	d.dot_product(b);

	d.cross_product(b);

	d.angle_between(b);
}
