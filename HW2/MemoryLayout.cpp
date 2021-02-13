/**
 * MemoryLayout.cpp
 * Created by Stephen on 2/12/2021.
 * Tells the order of static storage, the stack, and free storage are layed out in memory.
 */

#include <iostream>

void printPointer(int i) {
	int* iptr = &i;

	// the unary * operator dereferences the pointer
	std::cout << "i  =" << *iptr << "\n";
	std::cout << "&i = " << iptr << "\n";
}

int main(int argc, char *argv[]) {
	// TODO

	return 0;
}