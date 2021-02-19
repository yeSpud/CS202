//
// Created by Stephen on 1/19/2021.
//

#include "MyClass.hpp"
#include <iostream>
#include <vector>
#include <cstring>

// Define our static count
int MyClass::classCount = 0;

MyClass::MyClass():name("") {
	std::cout << "Default constructor called." << std::endl;
	classCount++;
}

MyClass::MyClass(const MyClass &myClassCopy):name(myClassCopy.name) {
	std::cout << "Copy constructor called." << std::endl;
	classCount++;
}

MyClass::MyClass(const char* name):name(name) {
	std::cout << "Custom constructor called." << std::endl;
	classCount++;
}

MyClass::~MyClass() {
	if (std::strcmp(name, "") != 0) {
		std::cout << "Destructor called for " << name << "\n:(" << std::endl;
	} else {
		std::cout << "Destructor called.\n:(" << std::endl;
	}
	classCount--;
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

int MyClass::getClassCount() {
	return classCount;
}