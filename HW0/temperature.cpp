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

    // Check for correct number of program arguments (3).
    if (argc != 3) {
    	std::cout << "Usage:./temperature --<ctof | ftoc> <temperature>" << std::endl;
	    return -1;
    }

    // Parse the argument and temperature as a string.
    std::string argument = argv[1];
    const char* temp = argv[2];

    // Check which function to run based off of the argument.
    if (argument == "--ctof") {
	    std::cout << temp <<" degrees celsius = " << c_ctof(temp) << " degrees fahrenheit" << std::endl;
    } else if (argument == "--ftoc") {
    	std::cout << temp <<" degrees fahrenheit = " << cpp_ftoc(temp) << " degrees celsius" << std::endl;
    } else {
    	// Because an invalid argument was given, return an error message.
    	std::cout << "Invalid argument given: " << argument << "\nExpected either --ctof or --ftoc" << std::endl;
	    return -2;
    }

	return 0;
}

/**
 * Converts the given temperature from fahrenheit to celsius.
 * @param str The temperature (as a string)
 * @return The temperature in celsius as a double.
 */
double cpp_ftoc(const char* str) {
	double temp = std::stod(str);
	return ((temp-32.0) * (5.0/9.0));
}

/**
 * Converts the given temperature from celsius to fahrenheit.
 * @param str
 * @return The temperature in fahrenheit as a double.
 */
double c_ctof(const char* str) {
	// strtod requires a string end pointer.
	char* endPointer;
	double temp = std::strtod(str, &endPointer);
	return (temp * (9.0/5.0) + 32.0);
}