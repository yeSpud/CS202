//
// Created by Stephen on 2/18/2021.
//

#ifndef LAB9_COMPLEX_HPP
#define LAB9_COMPLEX_HPP

#include <iostream>

class complex {

public:

	double real, imaginary;

	complex(double real, double i);

	explicit complex(double real);

	friend std::ostream& operator<<(std::ostream &os, const complex &c);

	friend complex operator+(const complex &c0, const complex &c1);

	friend complex& operator+=(complex &c0, const complex &c1);

};


#endif //LAB9_COMPLEX_HPP
