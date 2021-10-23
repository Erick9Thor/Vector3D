#include <iostream>
#include "../include/Vector3D.h"

int main()
{
	Vector3D<float> a, b, c, d;
	
	a = Vector3D<float>();
	b = Vector3D<float>(1, 0, 1);
	c = Vector3D<float>(b);
	
	d = a + c;

	b.Normalize();
	
	cout << "----------------\n";

	std::cout << "Distance to: ";
	d.printCoordinates();
	std::cout << "and: ";
	b.printCoordinates();
	std::cout << "is: ";
	
	cout << d.distanceTo(b) << '\n';

	cout << "----------------\n";

	std::cout << "Dot product between: ";
	d.printCoordinates();
	std::cout << "and: ";
	b.printCoordinates();
	std::cout << "is: ";
	
	cout << d.dotProduct(b) << '\n';

	cout << "----------------\n";

	std::cout << "Cross product between: ";
	d.printCoordinates();
	std::cout << "and: ";
	b.printCoordinates();
	std::cout << "is: ";
	
	d.crossProduct(b).printCoordinates();

	cout << "----------------\n";

	std::cout << "Angle between: ";
	d.printCoordinates();
	std::cout << "and: ";
	b.printCoordinates();
	
	cout << d.angleBetween(b) << '\n';
}
