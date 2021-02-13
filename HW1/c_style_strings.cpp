/**
 * c_style_strings.cpp
 * Created by Stephen on 1/29/2021.
 * Implements our own version of strdup and findx.
 */

#include <iostream>

char* strdup(const char* str);
char* findx(const char* s, const char* x);
int sizeOfString(const char* string);

int main(int argc, char *argv[]) {

	// Test strdup
	char* oString = (char*)"Foo";
	char* dString = strdup(oString);

	// Both the strings should be the same at this point
	std::cout << "oString: " << oString << std::endl;
	std::cout << "dString: " << dString << std::endl;

	// Change oString
	oString = (char*)"Bar";

	// At this point oString and dString should be different
	std::cout << "oString: " << oString << std::endl;
	std::cout << "dString: " << dString << std::endl;


	// Test findx
	char* test = (char*)"foobarbazq";
	char* x = (char*)"bar";

	// See where x string starts in the test string (the rest of the test string should also be printed).
	std::cout << "\n\nFind " << x << " in " << test << ": " << findx(test, x) << std::endl;

	return 0;
}

/**
 * Creates a C-style duplicate string into memory and allocated dynamically.
 */
char* strdup(const char* str) {

	// Get the length of our string.
	int size = sizeOfString(str);

	// Be sure to set the maximim number of entries in our char* array.
	char* dup = new char[size];

	// Copy upto and into the original string. (Basically <= instead of <).
	for (int i = 0; i <= size; i++) {
		char c = str[i];
		dup[i] = c;
	}

	// Return our duplicate string.
	return dup;
}

/**
 * Finds the first occurrence of the C-style string x in s.
 */
char* findx(const char* s, const char* x) {
	int sSize = sizeOfString(s), xSize = sizeOfString(x);
	int initPointer = 0;
	for (int i = 0; i < (sSize - xSize); i++) {

		// Iterate though S string for the start of X string.
		if (s[i] == x[0]) {

			// Iterate though x string to see if it matches the rest of s
			bool valid = false;
			for (int j = 0; j < xSize; j++) {

				// If x does not match s at any point for the rest of the size of x, break
				if (x[j] != s[i+j]) {
					valid = false;
					break;
				} else {
					valid = true;
				}
			}

			// If the characters were able to be validated, mark the init pointer where it starts within s, and break.
			if (valid) {
				initPointer = i;
				break;
			}
		}
	}

	// Create a new pointer for the character thats the size of the original size minus the offset initpointer.
	char* ptr = new char[sSize - initPointer];

	// Copy the rest of sString from the initpointer offset to the end of the string.
	for (int k = 0; k <= sSize - initPointer; k++) {
		ptr[k] = s[initPointer+k];
	}

	// Return the new pointer.
	return ptr;
}

int sizeOfString(const char* str) {
	int size = 0;
	while (str[size] != '\0') {
		size++;
	}
	return size;
}