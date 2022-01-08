#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	std::srand(static_cast<unsigned int>(std::time(0)));
	std::cout << "\tWelcome to Guessing Your Number\n\n";
	std::cout << "Enter your secret number: ";

	int secretNumber;
	std::cin >> secretNumber;

	if (secretNumber > 100 || secretNumber < 1) {
		std::cout << "You choose an illegal number" << std::endl;
		return 1;
	}

	int tries = 0;
	int guess;
	do {
		guess = rand() % 100 + 1;
		tries++;
	} while (guess != secretNumber);

	std::cout << "Your number is " << guess << " and it has taken " <<
		tries << " attempts to be guessed" << std::endl;
	return 0;
}
