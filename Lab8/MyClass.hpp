//
// Created by Stephen on 1/19/2021.
//

#ifndef LAB1_MYCLASS_HPP
#define LAB1_MYCLASS_HPP

#include <vector>
#include <iostream>
#include <cstring>

class MyClass {

private:

	const char* name;

	static int classCount;

	std::vector<int> myPrivateVector;

public:

	/**
	 * Constructors and destructors
	 */

	MyClass();

	MyClass(const MyClass& myClassCopy);

	explicit MyClass(const char* name);

	~MyClass();


	/**
	 * Functions
	 */

	const char* getName();

	std::vector<int> getMyPrivateVector();

	void setName(const char*& newName); // Pass by reference const

	void setMyPrivateVector(std::vector<int> vector); // Pass by value

	static int getClassCount(); // Static test.

};

#endif //LAB1_MYCLASS_HPP
