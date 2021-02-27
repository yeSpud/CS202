/**
 * Money.cpp
 * Created by Stephen on 2/26/2021.
 * Whats my purpose?
 */

#include "Money.hpp"

Money::Money() : dollarValue(0.0) {}

Money::Money(float amount) : dollarValue(amount) {}

std::ostream &operator<<(std::ostream &os, const Money &m) {
	// TODO

	return os;
}

/* Boolean operators */

bool operator==(const Money &m1, const Money &m2) {
	return m1.dollarValue == m2.dollarValue;
}

bool operator!=(const Money &m1, const Money &m2) {
	return m1.dollarValue != m2.dollarValue;
}

bool operator<=(const Money &m1, const Money &m2) {
	return m1.dollarValue <= m2.dollarValue;
}

bool operator<(const Money &m1, const Money &m2) {
	return m1.dollarValue < m2.dollarValue;
}

bool operator>(const Money &m1, const Money &m2) {
	return m1.dollarValue > m2.dollarValue;
}

bool operator>=(const Money &m1, const Money &m2) {
	return m1.dollarValue >= m2.dollarValue;
}

/* Math operators - I don't have a good name for these sorry :( */

Money &Money::operator-=(const Money &m) {
	this->dollarValue -= m.dollarValue;
	return *this;
}

Money &Money::operator+=(const Money &m) {
	this->dollarValue += m.dollarValue;
	return *this;
}

Money &Money::operator/=(float value) {
	this->dollarValue /= value;
	return *this;
}

Money &Money::operator*=(float value) {
	this->dollarValue *= value;
	return *this;
}

Money operator+(const Money &m1, const Money &m2) {
	return Money(m1.dollarValue + m2.dollarValue);
}

Money operator-(const Money &m1, const Money &m2) {
	return Money(m1.dollarValue - m2.dollarValue);
}

Money operator*(const Money &m, const float value) {
	return Money(m.dollarValue * value);
}

Money operator*(float value, const Money &m) {
	return Money(m.dollarValue * value);
}

Money operator/(const Money &m, float value) {
	return Money(m.dollarValue / value);
}