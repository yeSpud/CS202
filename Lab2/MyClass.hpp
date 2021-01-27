//
// Created by Stephen on 1/19/2021.
//

#ifndef LAB1_MYCLASS_HPP
#define LAB1_MYCLASS_HPP

#include <vector>
#include <iostream>

class MyClass {

private:

	const char* name;

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

	std::vector<int> createVector();

	void setName(const char*& newName); // Pass by reference const

	void vectorReference(std::vector<int>& vectorReference); // Pass by reference

	void setMyPrivateVector(std::vector<int> vector); // Pass by value

	std::vector<int> getMyPrivateVector();

	void selfReferenceConst(const MyClass& myClass);

	void selfReference(MyClass& myClass);

	void selfValue(MyClass myClass);

	static MyClass getMyClass();

};

#endif //LAB1_MYCLASS_HPP
