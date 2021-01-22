#include <iostream>
#include "MyClass.hpp"

void printVector(const std::vector<int>& vector) {
	std::cout << "Entries in vector: ";
	for (int entry : vector) {
		std::cout << entry << ", ";
	}

	std::cout << std::endl;
}

int main() {

	// Setup our first class
	MyClass myClass = MyClass();
	//const char* myClassName = "My original class name";
	//myClass.setName(myClassName);

	// Setup our second class that should be a copy of our first class
	MyClass myClass2 = MyClass(myClass);

	// Setup another class as its own with its own name
	MyClass myClassWithName = MyClass("CS 202");

	// Print class names
	/*
	std::cout << "Class names:\n" << myClass.getName() << '\n';
	std::cout << myClass2.getName() << '\n';
	std::cout << myClassWithName.getName() << '\n' << std::endl;


	// Vector stuff by reference and by value
	std::cout << "Vector stuff:" << std::endl;
	std::vector myLocalVector = myClass.createVector();
	printVector(myLocalVector);
	myClass.vectorReference(myLocalVector);
	printVector(myLocalVector);
	myClass.setMyPrivateVector(myLocalVector);

	// Should call default constructor 5 times
	std::vector<MyClass> myClasses(5);
	*/

	// Passing my class to a function defined in my class
	// Class-ception
	std::cout << "\nClass passing by reference and value" << std::endl;

	// Because this is a const its essentially readonly
	myClass.selfReferenceConst(myClassWithName);

	// Since this was passed by value, any changes made will not be kept.
	// This is because a copy has been made (as shown by the copy constructor) and this function returns void
	myClass.selfValue(myClass2);

	// Show that no changes were kept, though since this is passed by reference any changes we make here will be kept...
	myClass.selfReference(myClass2);

	// Get a new class
	MyClass mClass = MyClass::getMyClass();


	std::cout << "\nCleaning up class..." << std::endl;
	return 0;
}
