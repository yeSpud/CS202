/**
 * main.cpp
 * Created by Stephen on 2/2/2021.
 * Used for CS 202 lab 4.
 */

#include <iostream>
#include <fstream>
#include <string>

void readFromFile(const std::string& filePath);
void appendToFile(const std::string& filePath, const int n, const std::string str);

int main(int argc, char *argv[]) {

	// Check for valid arguments
	// This tends to be picky so be sure to use the full file path if you can.
	if (argc != 2) {
		std::cout << "Usage: ./main <file>" << std::endl;
		return -1;
	}

	// Read the contents of the file. This function should output to the console.
	readFromFile(argv[1]);

	return 0;
}


void readFromFile(const std::string& filePath) {

	// Create a filestream based on file path.
	std::ifstream file(filePath);

	// Make sure the file stream is valid
	if (file.fail()) {
		std::cout << "File stream error.\n(Is the file path valid?)" << std::endl;

		// Just return early.
		return;
	}

	// Create a string to act as a character buffer
	std::string bufferString;

	// Read from the file.
	while (std::getline(file, bufferString)) {

		// Print the stream to the console
		std::cout << bufferString << std::endl; // This seems to not like unicode :(
	}

	// We could close the file here, but the destructor does that for us.
}

void appendToFile(const std::string& filePath, const int n, const std::string str) {
	// TODO
}