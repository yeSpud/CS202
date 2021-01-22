#include <iostream>

bool foo();

int main() {

	// Function call
	std::cout << "\nFunction call: " << '\0';
	bool ret = foo();


	// If statement
	std::cout << "\nIf statement: " << '\0';
	if (ret) {
		std::cout << "Returned true\n" << '\0';
	} else {
		std::cout << "Returned false\n" << '\0';
	}


	// Switch
	std::cout << "\nSwitch: " << '\0';
	int swtch = 202;
	std::cin >> swtch; // Get from user input
	switch (swtch) {
		case 0:
			std::cout << "Case 0" << '\0';
			break;
		case 1:
			std::cout << "Case 1" << '\0';
			break;
		default:
			std::cout << "Default case" << '\0';
			break;
	}


	// While loop
	std::cout << "\n\nWhile loop: " << '\0';
	int wloop = 0;
	while (wloop < 202) {
		std::cout << wloop << '\n' << '\0';
		wloop += 10;
	}


	// Do while loop
	std::cout << "\nDo while loop: " << '\0';
	int dwloop = 0;
	do {
		std::cout << dwloop << '\n' << '\0';
		dwloop += 20;
	} while (dwloop < 202);


	// Basic for loop
	std::cout << "\nBasic for loop: " << '\0';
	for (int i = 0; i < 202; i += 2) {
		std::cout << i << '\n' << '\0';
	}


	// For each loop
	std::cout << "\nRange (for each) loop:\n" << '\0';
	int array[6] = {0, 1, 2, 3, 4, 5};
	for (int a : array) {
		std::cout << a << '\n' << '\0';
	}


	return 0;
}

// Print foo!
bool foo() {
	std::cout << "Foo\n" << '\0';

	return true;
}
