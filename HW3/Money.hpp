/**
 * Money.hpp
 * Created by Stephen on 2/26/2021.
 * Whats my purpose?
 */

#ifndef HW3_MONEY_HPP
#define HW3_MONEY_HPP

#include <iostream>

class Money {

private:

	float dollarValue = 0.0;

public:

	Money();

	explicit Money(float amount);

	friend std::ostream& operator<<(std::ostream &os, const Money &m);

	friend bool operator==(const Money &m1, const Money& m2);

	friend bool operator!=(const Money &m1, const Money& m2);

	friend bool operator<=(const Money &m1, const Money& m2);

	friend bool operator<(const Money &m1, const Money& m2);

	friend bool operator>(const Money &m1, const Money& m2);

	friend bool operator>=(const Money &m1, const Money& m2);

	friend Money& operator-=(const Money &m1, const Money& m2);

	friend Money& operator+=(const Money &m1, const Money& m2);

	friend Money& operator/=(const Money &m1, const Money& m2);

	friend Money& operator*=(const Money &m1, const Money& m2);

	friend Money operator+(const Money &m1, const Money& m2);

	friend Money operator-(const Money &m1, const Money& m2);

	friend Money operator*(const Money &m1, const Money& m2);

	friend Money operator/(const Money &m1, const Money& m2);

};


#endif //HW3_MONEY_HPP
