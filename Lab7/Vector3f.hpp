//
// Created by Stephen on 2/9/2021.
//

#ifndef LAB7_VECTOR3F_HPP
#define LAB7_VECTOR3F_HPP


class Vector3f {

public:

	float x, y, z;

	Vector3f();

	Vector3f(float x, float y, float z);

	Vector3f(const Vector3f& vector3F);

};

inline bool operator==(const Vector3f &a, const Vector3f &b) {
	return (a.x == b.x) && (a.y == b.y) && (a.z == b.z);
}

inline bool operator!=(const Vector3f &a, const Vector3f &b) {
	return (a.x != b.x) || (a.y != b.y) || (a.z != b.z);
}

#endif //LAB7_VECTOR3F_HPP
