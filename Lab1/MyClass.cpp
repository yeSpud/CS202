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
	return MyClass::name;
}

std::vector<int> MyClass::createVector() {
	return std::vector<int>{0,1,2,3,4};
}

void MyClass::setName(const char*& newName) {
	std::cout << "Object has been passed by const reference" << std::endl;
	name = newName;
}

void MyClass::vectorReference(std::vector<int>& vectorReference) {
	std::cout << "Object has been passed by reference" << std::endl;

	// For this example just change the values of the vector
	vectorReference = {5,6,7,8,9};
}

void MyClass::setMyPrivateVector(std::vector<int> vector) {
	std::cout << "Object has been passed by value" << std::endl;

	// Just assign to our private vector
	myPrivateVector = std::move(vector);
}

std::vector<int> MyClass::getMyPrivateVector() {
	return myPrivateVector;
}

void MyClass::selfReferenceConst(const MyClass &myClass) {
	std::cout << "Class passed by const reference" << std::endl;
	//std::cout << "Name: " << myClass.name << std::endl;
	//std::cout << "Size of array: " << myClass.myPrivateVector.capacity() << std::endl;
}

void MyClass::selfReference(MyClass& myClass) {
	std::cout << "Class passed by reference" << std::endl;
	//std::cout << "Name: " << myClass.getName() << std::endl;
	//std::cout << "Size of array: " << myClass.getMyPrivateVector().capacity() << std::endl;
	//myClass.myPrivateVector.clear();
}

void MyClass::selfValue(MyClass myClass) {
	std::cout << "Class passed by value" << std::endl;
	const char* newName = "myClass 2 - electric boogaloo";
	myClass.setName(newName);
	myClass.setMyPrivateVector({202,201,0});
	//std::cout << "Name: " << myClass.getName() << std::endl;
	//std::cout << "Size of array: " << myClass.getMyPrivateVector().capacity() << std::endl;
}

MyClass MyClass::getMyClass() {
	std::cout << "Getting a new Class object" << std::endl;
	return MyClass();
}
