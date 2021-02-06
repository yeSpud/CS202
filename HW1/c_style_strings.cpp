/**
 * c_style_strings.cpp
 * Created by Stephen on 1/29/2021.
 * Whats my purpose?
 */

#include <iostream>

char* strdup(const char* str);
char* findx(const char* s, const char* x);
int sizeOfString(const char* string);

int main(int argc, char *argv[]) {
	// TODO

	char* test = findx("foobarbaz", "bar");
	std::cout << test << std::endl;

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
				if (x[j] != s[i+j]) {
					valid = false;
					break;
				} else {
					valid = true;
				}
			}

			if (valid) {
				initPointer = i;
				break;
			}
		}
	}

	char* ptr = new char[sSize - initPointer];
	for (int k = 0; k <= sSize - initPointer; k++) {
		ptr[k] = s[initPointer+k];
	}

	return ptr;
}

int sizeOfString(const char* str) {
	int size = 0;
	while (str[size] != '\0') {
		size++;
	}
	return size;
}