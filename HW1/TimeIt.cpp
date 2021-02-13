/**
 * TimeIt.cpp
 * Created by Stephen on 1/29/2021.
 * Times various STL algorithms against varying array sizes.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include "StopWatch.hpp"

void test(const unsigned int& size);

// Helper functions
std::vector<int> getRandomVector(const unsigned int& size);
int getRandom();

// Random devices
static std::random_device rd;
static std::mt19937 rng{rd()};

int main(int argc, char *argv[]) {

	// Run various tests
	test(10);
	test(10e1);
	test(10e2);
	test(10e3);
	test(10e4);
	test(10e5);
	test(10e6);
	test(10e7);
	test(10e8);

	return 0;
}

void test(const unsigned int& size) {

	// Create our vector to be searched.
	std::cout << "Generating new vector" << std::endl;
	const std::vector<int> v = getRandomVector(size);

	// Create a small vector to compare
	const std::vector<int> c = {0,1,2,3};

	std::cout << "Measuring search on size " << size << std::endl;
	StopWatch watch = StopWatch();
	std::search(v.begin(), v.end(), c.begin(), c.end());
	watch.Stop();
	std::cout << "Time elapsed: " << watch.getSeconds() << "s (" << watch.getMilliseconds() << "ms)\n" << std::endl;


	std::cout << "Measuring binary_search on size " << size << std::endl;
	watch.Start();
	// Add an impossible value (as I kinda want this to fail to see the max time)
	std::binary_search(v.begin(), v.end(), 1e10);
	watch.Stop();
	std::cout << "Time elapsed: " << watch.getSeconds() << "s (" << watch.getMilliseconds() << "ms)\n" << std::endl;


	std::cout << "Measuring sort on search_n " << size << std::endl;
	watch.Start();
	// Add an impossible value (as I kinda want this to fail to see the max time)
	std::search_n(v.begin(), v.end(), 1,1e10);
	watch.Stop();
	std::cout << "Time elapsed: " << watch.getSeconds() << "s (" << watch.getMilliseconds() << "ms)\n" << std::endl;


	std::cout << "Measuring find on size " << size << std::endl;
	watch.Start();
	// Add an impossible value (as I kinda want this to fail to see the max time)
	std::find(v.begin(), v.end(),1e10);
	watch.Stop();
	std::cout << "Time elapsed: " << watch.getSeconds() << "s (" << watch.getMilliseconds() << "ms)\n" << std::endl;

	std::cout << "\n\n" << std::endl;
}

std::vector<int> getRandomVector(const unsigned int& size) {

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