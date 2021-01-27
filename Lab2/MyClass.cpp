//
// Created by Stephen on 1/19/2021.
//

#include "MyClass.hpp"
#include <iostream>
#include <vector>

MyClass::MyClass():name("") {
	std::cout << "Default constructor called." << std::endl;
}

MyClass::MyClass(const MyClass &myClassCopy):name(myClassCopy.name) {
	std::cout << "Copy constructor called." << std::endl;
}

MyClass::MyClass(const char* name):name(name) {
	std::cout << "Custom constructor called." << std::endl;
}

MyClass::~MyClass() {
	std::cout << "Deconstructor called.\n:(" << std::endl;
}

/**
 * Gets the name of the class (this may be null or an empty string).
 * @return
 */
const char* MyClass::getName() {
	return name;
}

void MyClass::setName(const char*& newName) {
	std::cout << "Object has been passed by const reference" << std::endl;
	name = newName;
}


void MyClass::setMyPrivateVector(std::vector<int> vector) {
	std::cout << "Object has been passed by value" << std::endl;

	// Just assign to our private vector
	myPrivateVector = std::move(vector);
}

std::vector<int> MyClass::getMyPrivateVector() {
	return myPrivateVector;
}
