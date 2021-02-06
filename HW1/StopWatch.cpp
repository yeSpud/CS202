/**
 * StopWatch.cpp
 * Created by Stephen on 1/29/2021.
 * Class that tracks elapsed time. See StopWatch.hpp for function documentation.
 */

#include "StopWatch.hpp"
#include <chrono>

StopWatch::StopWatch() {

	// Just start the timer.
	Start();
}

void StopWatch::Start() {
	// Set the start time point to when this was created.
	startTime = std::chrono::high_resolution_clock::now();
}

void StopWatch::Stop() {
	// Set the end time to the current time once this function is called.
	endTime = std::chrono::high_resolution_clock::now();
}

double StopWatch::getSeconds() {
	// This is in seconds by default.
	std::chrono::duration<double> finalTime = endTime - startTime;

	// Simply return the count of the final time.
	return finalTime.count();
}

double StopWatch::getMilliseconds() {

	// This is in seconds by default.
	std::chrono::duration<double> sec = endTime - startTime;

	// Because the duration defaults to seconds, we have to cast the duration to milliseconds.
	std::chrono::milliseconds finalTime = std::chrono::duration_cast<std::chrono::milliseconds>(sec);

	// Return the casted duration.
	return (double) finalTime.count();
}