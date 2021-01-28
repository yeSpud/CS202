#include <iostream>
#include <memory>
#include "MyClass.hpp"

int main() {

	std::cout << "Creating raw pointer dynamically" << std::endl;
	MyClass* myClassPointer;
	myClassPointer = new MyClass("Raw pointer class");
	// Seems that this object is never destroyed, so well take care of that
	delete myClassPointer;

	std::cout << "\nCreating unique pointer" << std::endl;
	std::unique_ptr<MyClass> myUniquePtr = std::make_unique<MyClass>("My unique pointer");

	std::cout << "\nTransferring ownership of unique pointer" << std::endl;
	std::unique_ptr<MyClass> myUniqueCopy = move(myUniquePtr);

	std::cout << "\nCalling function within class" << std::endl;
	// Calling member function of original pointer results in an error
	std::cout << "Name of my class: " << myUniqueCopy->getName() << std::endl;

	std::cout << "\nCreating shared pointer" << std::endl;
	std::shared_ptr<MyClass> mySharedPointer = std::make_shared<MyClass>();

	std::cout << "\nCreating another shared pointer based off of the first one" << std::endl;
	const std::shared_ptr<MyClass>& myOtherSharedPointer(mySharedPointer);

	std::cout << "\nEnd of program" << std::endl;

	return 0;
}
