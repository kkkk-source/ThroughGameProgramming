#include <iostream>

int main() {
	enum difficulty { EASY = 1, NORMAL, HARD }; 

	std::cout << "Difficulty Levels\n\n";
	std::cout << "1 - Easy\n";
	std::cout << "2 - Normal\n";
	std::cout << "3 - Hard\n";

	int choice;
	std::cout << "Choice: ";
	std::cin >> choice;

	switch (choice) {
		case difficulty::EASY:
			std::cout << "You picked Easy.\n";
			break;
		case difficulty::NORMAL:
			std::cout << "You picked Normal.\n";
			break;
		case difficulty::HARD:
			std::cout << "You picked Hard.\n";
			break;
		default:
			std::cout << "You made an illegal choice.\n";
	}

	return 0;
}
