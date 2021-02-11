//
// Created by Stephen on 2/9/2021.
//

#ifndef LAB7_VECTOR3F_HPP
#define LAB7_VECTOR3F_HPP

#include <iostream>

class Vector3f {

public:

	float x, y, z;

	Vector3f();

	Vector3f(float x, float y, float z);

	Vector3f(const Vector3f& vector3F);

	friend bool operator==(const Vector3f &a, const Vector3f &b);

	friend bool operator!=(const Vector3f &a, const Vector3f &b);

	friend std::ostream& operator<<(std::ostream &os, const Vector3f &v);

};

#endif //LAB7_VECTOR3F_HPP
