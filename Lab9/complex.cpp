//
// Created by Stephen on 2/18/2021.
//

#include "complex.hpp"

complex::complex(double real, double i):real(real),imaginary(i) {}

complex::complex(double real):real(real),imaginary(0.0) {}

std::ostream& operator<<(std::ostream &os, const complex &c) {
	return os << c.real << " + " << c.imaginary << "i";
}

complex operator+(const complex &c0, const complex &c1) {
	return complex(c0.real + c1.real, c0.imaginary + c1.real);
}

complex& operator+=(complex &c0, const complex &c1) {
	c0.real += c1.real;
	c0.imaginary += c1.imaginary;
	return c0;
}