
#include "Vector3f.hpp"

int main() {

	// Create a test vector object
	Vector3f allZeros = Vector3f();
	Vector3f myVector3f = Vector3f(1.1, 2.2, 3.0);

	// Print my objects
	std::cout << "All zeros: " << allZeros << std::endl;
	std::cout << "My vector: " << myVector3f << std::endl;

}