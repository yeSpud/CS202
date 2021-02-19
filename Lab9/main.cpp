#include <iostream>
#include "complex.hpp"

int main() {

	// Create a test complex numbers.
	complex complex1 = complex(1.1, 1.1);
	complex complex2 = complex(2.2, 2.2);

	// Test the output stream.
	std::cout << "Complex 1: " << complex1 << std::endl;
	std::cout << "Complex 2: " << complex2 << std::endl;

	// Test the + operator.
	complex complex3 = complex1 + complex2;
	std::cout << "\nComplex 1: " << complex1 << std::endl;
	std::cout << "Complex 2: " << complex2 << std::endl;
	std::cout << "Complex 3: " << complex3 << std::endl;
}
