/**
 * tokenizer.cpp
 * Created by Stephen on 2/26/2021.
 * Takes an input (file or standard input which is specified as a command line argument),
 * and prints the tokens along with the line and column each token occurs at.
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>
#include <iomanip>

// Declare a struct that we will use
struct TokenAndPosition {
	std::string _token;
	int _line;
	unsigned int _column;
};

// Declare methods to be implemented later
std::vector<std::string> lineToToken(const std::string &line);
std::vector<TokenAndPosition> readLines(std::istream &is);
void printTokens(std::ostream &os, const std::vector<TokenAndPosition> &tokens);

int main(int argc, char *argv[]) {

	// Check that we have at least a file.
	if (argc < 2) {
		std::cout << "Usage: ./tokenizer <file>" << std::endl;
		return -1;
	}

	// Try reading the file.
	std::ifstream file;
	file.open(argv[1]);
	if (file.fail()) {
		std::cout << "Unable to open file." << std::endl;
		return -2;
	}

	// Get our tokens
	std::vector<TokenAndPosition> tokens = readLines(file);

	// Print our tokens.
	printTokens(std::cout, tokens);

	return 0;
}

std::vector<std::string> lineToToken(const std::string &line) {

	// Create a string stream.
	std::istringstream iss(line);

	// Create an array to return, and fill it with our strings.
	std::vector<std::string> strings((std::istream_iterator<std::string>(iss)),std::istream_iterator<std::string>());

	// Return our string.
	return strings;

}

std::vector<TokenAndPosition> readLines(std::istream &is) {

	// Create a vector to return.
	std::vector<TokenAndPosition> tokens;

	// Read from the file line by line and convert the string to a token.
	std::string bufferString;
	int lineNumber = 0;
	while (std::getline(is, bufferString)) {
		// Start by getting each string in the line, and iterate over them.
		int columnNumber = 0;
		for (const std::string& str: lineToToken(bufferString)) {
			// Convert that line to a token
			TokenAndPosition token;
			token._token = str;
			token._column = columnNumber;
			token._line = lineNumber;

			// Add the token to the array.
			tokens.push_back(token);
			columnNumber++;
		}

		lineNumber++;
	}

	return tokens;
}

void printTokens(std::ostream &os, const std::vector<TokenAndPosition> &tokens) {

	// Iterate though each token.
	for (TokenAndPosition token : tokens) {
		// Print our token to the specified output stream.
		os << "Line" << std::setw(5) << token._line << ", Column" << std::setw(7) << token._column << ": " << std::quoted(token._token) << std::endl;
	}
}