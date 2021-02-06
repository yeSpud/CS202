/**
 * TimeItII.cpp
 * Created by Stephen on 1/29/2021.
 * Whats my purpose?
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <fstream>
#include <sstream>
#include "StopWatch.hpp"

std::string readFileAsString(const std::string& filePath);
std::vector<std::string> readFileAsVector(const std::string& filePath);
std::list<std::string> readFileAsList(std::string filePath);
std::deque<std::string> readFileAsDeque(std::string filePath);

int main(int argc, char *argv[]) {

	std::string books[] = {"../books/The Manhattaners.txt", "../books/The Armenians.txt", "../books/A Modest Proposal.txt",
						"../books/The Jungle.txt", "../books/Ulysses.txt"};

	const std::string str = "with"; // Try searching for the string "with"

	for (const std::string& file : books) {
		StopWatch watch = StopWatch();
		readFileAsString(file);
		watch.Stop();
		std::cout << "\nRead file to string in " << watch.getSeconds() << "s\n" << std::endl;


		watch.Start();
		std::vector<std::string> v = readFileAsVector(file);
		watch.Stop();
		std::cout << "Read file to vector in " << watch.getSeconds() << "s" << std::endl;
		watch.Start();
		std::find(v.begin(), v.end(), str);
		watch.Stop();
		std::cout << "Found '" << str << "' in vector in " << watch.getSeconds() << "s" << std::endl;
		watch.Start();
		std::sort(v.begin(), v.end());
		watch.Stop();
		std::cout << "Sorted vector in " << watch.getSeconds() << "s\n" << std::endl;

		/*
		watch.Start();
		std::list<std::string> l = readFileAsList(file);
		watch.Stop();
		std::cout << "Read file to list in " << watch.getSeconds() << "s" << std::endl;
		watch.Start();
		std::find(l.begin(), l.end(), str);
		watch.Stop();
		std::cout << "Found '" << str << "' in list in " << watch.getSeconds() << "s" << std::endl;
		watch.Start();
		std::sort(l.begin(), l.end());
		watch.Stop();
		std::cout << "Sorted list in " << watch.getSeconds() << "s\n" << std::endl;

		watch.Start();
		std::deque<std::string> d = readFileAsDeque(file);
		watch.Stop();
		std::cout << "Read file to queue in " << watch.getSeconds() << "s" << std::endl;
		watch.Start();
		std::find(d.begin(), d.end(), str);
		watch.Stop();
		std::cout << "Found '"<< str << "' in queue in " << watch.getSeconds() << "s" << std::endl;
		watch.Start();
		std::sort(d.begin(), d.end());
		watch.Stop();
		std::cout << "Sorted queue in " << watch.getSeconds() << "s\n" << std::endl;
		 */
	}

	return 0;
}

std::string readFileAsString(const std::string& filePath) {

	// Create a filestream based on file path.
	std::ifstream file(filePath);

	if (file.fail()) {
		std::cout << "File stream error.\nIs the file path valid?" << std::endl;

		// Just return early.
		return "";
	}

	// Buffer string
	std::string str;
	if (file) {

		// Create a string stream to read into the buffer
		std::ostringstream ss;

		// Read the data from the file
		ss << file.rdbuf();
		str = ss.str();
	}

	return str;
}

std::vector<std::string> readFileAsVector(const std::string& filePath) {

	// Create a filestream based on file path.
	std::ifstream file(filePath);

	if (file.fail()) {
		std::cout << "File stream error.\nIs the file path valid?" << std::endl;
	}

	// Vector to be returned
	std::vector<std::string> v;

	// Create a string buffer
	std::string buff;
	while (std::getline(file, buff)) {

		// Add the string to the buffer
		v.push_back(buff);
	}

	return v;
}

std::list<std::string> readFileAsList(std::string filePath) {
	// TODO

	std::list<std::string> l;
	return l;
}

std::deque<std::string> readFileAsDeque(std::string filePath) {
	// TODO

	std::deque<std::string> d;
	return d;
}