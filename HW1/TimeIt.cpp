/**
 * TimeIt.cpp
 * Created by Stephen on 1/29/2021.
 * Whats my purpose?
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include "StopWatch.hpp"

void test(const int& size);

// Helper functions
std::vector<int> getRandomVector(const int& size);
int getRandom();

// Random devices
static std::random_device rd;
static std::mt19937 rng{rd()};

int main(int argc, char *argv[]) {

	test(10);

	return 0;
}

void test(const int& size) {

	// Create our vector to be searched.
	const std::vector<int> v = getRandomVector(size);

	std::cout << "Measuring search on size " << size << std::endl;
	//StopWatch watch = StopWatch();
	// TODO Time
	//watch.Stop();

	std::cout << "Measuring binary_search on size " << size << std::endl;
}

std::vector<int> getRandomVector(const int& size) {

	// Create a vector with a predetermined size
	std::vector<int> v(size);

	// Fill our vector with random ints
	for (int i = 0; i < size; i++) {

		// Get a random int, and add it to our vector
		int r = getRandom();
		v.push_back(r);
	}

	return v;
}

int getRandom() {
	// Get a random distribution between 0 and 1b.
	static std::uniform_int_distribution<int> random(0, 1e9);

	// Return a random distribution value using the mt19937 engine thingy.
	return random(rng);
}