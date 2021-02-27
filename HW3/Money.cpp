/**
 * Money.cpp
 * Created by Stephen on 2/26/2021.
 * Implements functions (mostly overloaded operators) declared in Money.hpp.
 * Also setup the main constructor.
 */

#include "Money.hpp"
#include <iomanip>
#include <string>
#include <cmath>

Money::Money() : cents(0) {}

Money::Money(float input) {

	// Round be sure to round to the last 2 decimals
	input = std::round(input * 100.0) / 100.0;

	// Check if there are numbers after the decimal.
	int floor = (int) input;

	// Use the decimal test to determine if the number is an int or a float.
	if ((float) floor - input == 0.0) {
		// Int
		cents = (long) input;
	} else {
		// Float
		cents = (long) (input * 100);
	}
}

std::ostream &operator<<(std::ostream &os, const Money &m) {

	// Check if the value is positive or negative
	if (m.cents < 0) {
		// Negative

		// Because its negative we want to replace the negative sign in front of the value in order to place it before the dollar sign
		// Do this by setting it to be a positive value, and just manually insert it.
		long posVal = m.cents * -1;

		os << "-$" << std::setprecision(2) << std::fixed << (double) posVal / 100.0;

	} else {
		// Positive

		os << "$" << std::setprecision(2) << std::fixed << (double) m.cents / 100.0;
	}

	return os;
}

/* Boolean operators */

bool operator==(const Money &m1, const Money &m2) {
	return m1.cents == m2.cents;
}

bool operator!=(const Money &m1, const Money &m2) {
	return m1.cents != m2.cents;
}

bool operator<=(const Money &m1, const Money &m2) {
	return m1.cents <= m2.cents;
}

bool operator<(const Money &m1, const Money &m2) {
	return m1.cents < m2.cents;
}

bool operator>(const Money &m1, const Money &m2) {
	return m1.cents > m2.cents;
}

bool operator>=(const Money &m1, const Money &m2) {
	return m1.cents >= m2.cents;
}

/* Math operators - I don't have a good name for these sorry :( */

Money &Money::operator-=(const Money &m) {
	this->cents -= m.cents;
	return *this;
}

Money &Money::operator+=(const Money &m) {
	this->cents += m.cents;
	return *this;
}

Money &Money::operator/=(float value) {
	this->cents /= value;
	return *this;
}

Money &Money::operator*=(float value) {
	this->cents *= value;
	return *this;
}

Money operator+(const Money &m1, const Money &m2) {
	return Money(m1.cents + m2.cents);
}

Money operator-(const Money &m1, const Money &m2) {
	return Money(m1.cents - m2.cents);
}

Money operator*(const Money &m, const float value) {
	return Money(m.cents * value);
}

Money operator*(float value, const Money &m) {
	return Money(m.cents * value);
}

Money operator/(const Money &m, float value) {
	return Money(m.cents / value);
}