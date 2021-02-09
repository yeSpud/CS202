//
// Created by Stephen on 2/9/2021.
//

#include "Vector3f.hpp"

Vector3f::Vector3f() {

	// Set all floats to 0.
	x = 0.0;
	y = 0.0;
	z = 0.0;

}

Vector3f::Vector3f(const Vector3f &vector3F) {

	// Set all floats to that of the copy values.
	x = vector3F.x;
	y = vector3F.y;
	z = vector3F.z;

}

Vector3f::Vector3f(float xValue, float yValue, float zValue) {

	// Set all the floats manually.
	x = xValue;
	y = yValue;
	z = zValue;
}