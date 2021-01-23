/**
 * temperature.cpp
 * Created by Stephen on 1/22/2021.
 * Converts temperature from degrees Fahrenheit to degrees Celsius.
 */

#include <iostream>
#include <string>

// Functions that we will use for the conversion later.
double cpp_ftoc(const char* str);
double c_ctof(const char* str);

int main(int argc, char* argv[]) {

    // Check for correct program arguments.
    if (argc != 3) {
    	std::cout << "Usage:./temperature --<ctof | ftoc> <temperature>" << std::endl;
	    return -1;
    }

    // Parse the argument and temperature as a string.
    std::string command = argv[1];
    const char* temp = argv[2];

    // Check which function to run based off of the argument.
    if (command == "--ctof") {
	    std::cout << temp <<" degrees C = " << c_ctof(temp) << " degrees F" << std::endl;
    } else if (command == "--ftoc") {
    	std::cout << temp <<" degrees F = " << cpp_ftoc(temp) << " degrees C" << std::endl;
    } else {
    	// Because an invalid argument was given, return an error message.
    	std::cout << "Invalid argument given: " << command << "\nExpected either --ctof or --ftoc" << std::endl;
	    return -2;
    }
}

double cpp_ftoc(const char* str) {
	double temp = std::stod(str);
	return ((temp-32.0) * (5.0/9.0));
}

double c_ctof(const char* str) {
	char* endPointer;
	double temp = std::strtod(str, &endPointer);
	return (temp * (9.0/5.0) + 32.0);
}