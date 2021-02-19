#include <iostream>
#include "MyClass.hpp"

void addAndPrint() {
	static int myStaticVar = 0;
	std::cout << "My static variable value: " << myStaticVar << std::endl;
	myStaticVar++;
}


int main() {

	// Demonstrate local static variable.
	addAndPrint();
	addAndPrint();
	addAndPrint();

	// Demonstrate number 4.
	std::cout << "My class count: " << MyClass::getClassCount() << std::endl;

	// Create a few new classes for 3 and 4.
	MyClass class1 = MyClass("My first class :D");
	MyClass class2 = MyClass("My second class :D");
	MyClass class3 = MyClass("My third class D:");

	// Demonstrate 3 and 4.
	std::cout << "My class count after creating classes: " << MyClass::getClassCount() << std::endl;

	return 0;
}


