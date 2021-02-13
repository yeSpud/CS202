#include <iostream>
#include <fstream>
#include <vector>

int main() {

	// Open the file using ifstream in bin mode.
	std::ifstream infile(R"(C:\Users\Stephen\Programs\CS202\Lab5\data.dat)", std::ios::binary);

	// Check that it was opened
	if (!infile) {
		std::cout << "Unable to open file" << std::endl;
		return -1;
	}

	// Get all the numbers from the file
	int n;
	std::vector<int> inputs;
	while (!infile.eof()) {
		infile.read((char *) &n, sizeof(int));

		if (!infile) {
			break;
		}

		inputs.push_back(n);
		//std::cout << n << std::endl;
	}

	std::cout << "Number of integers: " << inputs.size() << std::endl;

	// Get the sum
	int sum = 0;
	for (int v : inputs) {
		sum+=v;
	}

	// Print the sum and average
	std::cout << "Sum: " << sum << std::endl;
	std::cout << "Average: " << ((double) sum/inputs.size()) << std::endl;

	return 0;
}
