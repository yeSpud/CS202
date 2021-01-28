#include <iostream>
#include "MyClass.hpp"

int main() {

	std::cout << "Creating raw pointer dynamically" << std::endl;
	MyClass* myClassPointer;
	myClassPointer = new MyClass("Raw pointer class");
	// Seems that this object is never destroyed, so well take care of that
	delete myClassPointer;

	std::cout << "Creating unique pointer" << std::endl;
	// TODO

	std::cout << "Transferring ownership of unique pointer" << std::endl;
	// TODO

	std::cout << "Calling function within class" << std::endl;
	// TODO

	std::cout << "Creating shared pointer" << std::endl;
	// TODO

	std::cout << "Creating another shared pointer based off of the first one" << std::endl;
	// TODO

	return 0;
}
