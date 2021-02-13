/**
 * main.cpp
 * Created by Stephen on 2/2/2021.
 * Used for CS 202 lab 4.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void readFromFile(const std::string& filePath);
void getInputs(int& n, std::string& str);
void appendToFile(const std::string& filePath, int n, const std::string& str);

int main(int argc, char *argv[]) {

	// Check for valid arguments
	// This tends to be picky so be sure to use the full file path if you can.
	if (argc != 2) {
		std::cout << "Usage: ./main <file>" << std::endl;
		return -1;
	}

	// Read the contents of the file. This function should output to the console.
	readFromFile(argv[1]);

	// Get our inputs.
	int n;
	std::string str;
	getInputs(n, str);

	// Append the string to the file n number of times.
	appendToFile(argv[1], n, str);

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

void getInputs(int& n, std::string& str) {

	// Get a number and string from the user (all on one line).
	std::cout << "Gimme number and a line of text: ";

	// Store both the input number and text all in one string for future processing.
	std::string rawInput;
	std::getline(std::cin, rawInput);

	// String stream for parsing
	std::istringstream istring(rawInput);

	// Get our number from our stream.
	istring >> n;

	// Get our string from our stream.
	std::getline(istring, str);

	// Replace the first space left over from parsing.
	str.replace(0, 1, "");
}

void appendToFile(const std::string& filePath, int n, const std::string& str) {

	// Open our file for writing in append mode.
	std::ofstream outFile(filePath, std::ofstream::app);

	// Make sure the file stream is valid
	if (outFile.fail()) {
		std::cout << "File stream error.\n(Is the file path valid?)" << std::endl;

		// Just return early.
		return;
	}

	for (int i = 0; i < n; i++) {
		// Im choosing to add a new line before the input for style reasons.
		// If the string literally needs to be appended with nothing fancy added before and after feel free to remove.
		outFile << "\n" << str;
	}

	// We could close the file here, but the destructor does that for us.
}