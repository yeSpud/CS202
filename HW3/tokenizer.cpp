/**
 * tokenizer.cpp
 * Created by Stephen on 2/26/2021.
 * Takes an input (file or standard input which is specified as a command line argument),
 * and prints the tokens along with the line and column each token occurs at.
 */

#include <iostream>
#include <vector>
#include <string>

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
	// TODO

	return 0;
}