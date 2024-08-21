#include <deque>
#include <iostream>

int main() {
	std::deque<int> myDeque;

	myDeque.push_back(10);
	myDeque.push_back(20);
	myDeque.push_back(30);
	myDeque.push_back(40);

	// Access elements using the [] operator
	std::cout << "Element at index 2: " << myDeque[2] << std::endl;
	std::cout << "Element at index 0: " << myDeque[0] << std::endl;


	std::cout << "Element at index 1: " << myDeque.at(1) << std::endl;
	std::cout << "Element at index 3: " << myDeque.at(3) << std::endl;

	// Example of at() throwing an exception for out-of-range access
	try {
		std::cout << "Element at index 4: " << myDeque.at(4) << std::endl;
	} catch (const std::out_of_range& e) {
		std::cerr << "Exception: " << e.what() << std::endl;  // Output: Exception: deque::_M_range_check: __n (which is 4) >= this->size() (which is 4)
	}

	return 0;
}