/**
 * Money.cpp
 * Created by Stephen on 2/26/2021.
 * Whats my purpose?
 */

#include "Money.hpp"

Money::Money():dollarValue(0.0) {}

Money::Money(float amount):dollarValue(amount) {}

std::ostream& operator<<(std::ostream &os, const Money &m) {
	// TODO

	return os;
}

bool operator==(const Money &m1, const Money& m2) {
	return m1.dollarValue == m2.dollarValue;
}

bool operator != (const Money &m1, const Money& m2) {
	return m1.dollarValue != m2.dollarValue;
}

bool operator <= (const Money &m1, const Money& m2) {
	return m1.dollarValue <= m2.dollarValue;
}

bool operator < (const Money &m1, const Money& m2) {
	return m1.dollarValue < m2.dollarValue;
}

bool operator > (const Money &m1, const Money& m2) {
	return m1.dollarValue > m2.dollarValue;
}

bool operator >= (const Money &m1, const Money& m2) {
	return m1.dollarValue >= m2.dollarValue;
}