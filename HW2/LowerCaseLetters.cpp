/**
 * LowerCaseLetters.cpp
 * Created by Stephen on 2/12/2021.
 * Set uppercase letters to lowercase.
 */

#include <iostream>

void to_lower(char* s) {

	// Make sure s isn't null
	if (s == nullptr) {
		return;
	}

	// Iterate though each character in the string of characters
	int i = 0;
	while (s[i] != '\0') {

		// Check if that character is within the capital ascii range.
		if (s[i] >= 'A' && s[i] <= 'Z') {

			// Add 32 ascii character values to get to the next index
			s[i] = char(s[i] + 32);
		}

		// Go to the next index
		i++;
	}
}

int main(int argc, char *argv[]) {

	// Create a test string.
	char str[] = "Hello, world!";
	std::cout << str << std::endl;

	// Set the string to lowercase
	to_lower(str);

	// Show the changes.
	std::cout << str << std::endl;
	return 0;
}