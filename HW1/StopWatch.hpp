/**
 * StopWatch.hpp
 * Created by Stephen on 1/29/2021.
 * Class that tracks elapsed time.
 */

#ifndef HW1_STOPWATCH_HPP
#define HW1_STOPWATCH_HPP

#include <chrono>

class StopWatch {

private:

	std::chrono::high_resolution_clock::time_point startTime,  endTime;

public:

	StopWatch();

	/**
	 * (Re)starts the clock.
	 */
	void Start();

	/**
	 * Stops the clock.
	 */
	void Stop();

	/**
	 * Gets the elapsed time in seconds.
	 * @return The elapsed time in seconds.
	 */
	double getSeconds();

	/**
	 * Gets the elapsed time in milliseconds
	 * @return The elapsed time in milliseconds.
	 */
	double getMilliseconds();
};


#endif //HW1_STOPWATCH_HPP
