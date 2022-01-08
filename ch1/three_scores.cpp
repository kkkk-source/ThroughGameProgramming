#include <iostream>


int main() {
	const int MAX_ATTEMPTS = 3;
	int attempts = 1;
	double total = 0.0;
	double score;

	while (attempts <= MAX_ATTEMPTS && std::cin >> score) {
		total += score;
		attempts++;
	}

	std::cout << "The average is: " << total / attempts << std::endl;
}
