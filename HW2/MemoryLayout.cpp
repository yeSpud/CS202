/**
 * MemoryLayout.cpp
 * Created by Stephen on 2/12/2021.
 * Tells the order of static storage, the stack, and free storage are laid out in memory.
 */

#include <iostream>

static int static1 = 201;
static int static2 = 202;

void printPointer(int i) {
	int* iptr = &i;

	// the unary * operator dereferences the pointer
	std::cout << "i = " << *iptr << "\n";
	std::cout << "&i = " << iptr << "\n";
}

int main(int argc, char *argv[]) {

	// Print static storage usage first.
	std::cout << "Static variables:" << std::endl;
	std::cout << static1 << "=" << &static1 << std::endl;
	std::cout << static2 << "=" << &static2 << std::endl;

	// Print stack variables next.
	int i = 202;
	std::cout << "\nStack variables:" << std::endl;
	std::cout << i << "=" << &i << std::endl;
	printPointer(i);
	printPointer(201);

	// Print the location of free space.
	std::cout << "\nFree storage:" << std::endl;
	char* heap = (char *) malloc(4);
	std::cout << "heap=" << &heap << std::endl;
	int* additionalHeap = (int *) malloc(8);
	std::cout << "additionHeap=" << &additionalHeap << std::endl;
	free(heap);
	free(additionalHeap);


	return 0;
}