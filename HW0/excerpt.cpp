/**
 * excerpt.cpp
 * Created by Stephen on 1/22/2021.
 * Extracts and prints an excerpts from a text file.
 * For this example it should be a copy of Wuthering Heights from Project Gutenberg.
 */

#include <iostream>
#include <vector>
#include <random>
#include <fstream>

/**
 * Function used to parse the entries in the book.
 * @param fileStream The file stream (think file object).
 * If there is an issue with the fileStream the function will return an emtpy vector.
 * @return Returns a vector containing all the passages from the book (seperated by new lines).
 * If there was an error with the fileStream this will return an empty vector instead.
 */
std::vector<std::string> parseBook(std::ifstream &fileStream) {

	// Create a vector to store all the entries.
	std::vector<std::string> entries;

	// Make sure the file stream is valid
	if (fileStream.fail()) {
		std::cout << "File stream error.\n(Is the file path valid?)" << std::endl;

		// Just return the empty entry array.
		return entries;
	}

	// Create a string to act as a character buffer
	std::string bufferString;

	while (std::getline(fileStream, bufferString)) {

		// Make sure we arent adding newlines or nulls.
		if (bufferString != "\n" && bufferString != "\0") {

			// Append the string to the entries vector
			entries.push_back(bufferString);
		}
	}

	return entries;
}

int main(int argc, char *argv[]) {

	// Check for valid arguments\
	// This tends to be picky so be sure to use the full file path if you can.
	if (argc != 2) {
		std::cout << "Usage: ./excerpt <file>" << std::endl;
		return -1;
	}

	// Create a filestream based on the argument given
	std::ifstream file(argv[1]);

	// Parse the book
	std::vector<std::string> entries = parseBook(file);
	file.close();

	// Get an entry index dependent on the array size.
	// This will get an int between 0 and the size of the entries vector.
	std::random_device randomDevice;
	std::mt19937 randomGenerator(randomDevice());
	std::uniform_int_distribution<int> distribution(0, entries.size());
	int excerptIndex = distribution(randomGenerator);

	std::cout << "Excerpt from line " << excerptIndex << ":\""<< entries.at(excerptIndex) << "\"" << std::endl;

	return 0;
}