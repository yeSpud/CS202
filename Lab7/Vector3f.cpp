//
// Created by Stephen on 2/9/2021.
//

#include "Vector3f.hpp"

// Set all floats to 0.
Vector3f::Vector3f():x(0.0),y(0.0),z(0.0) {

}

// Set all floats to that of the copy values.
Vector3f::Vector3f(const Vector3f &vector3F):x(vector3F.x),y(vector3F.y),z(vector3F.z) {

}

// Set all the floats manually.
Vector3f::Vector3f(float xValue, float yValue, float zValue):x(xValue),y(yValue),z(zValue) {

}