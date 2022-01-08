// Word Jumble
// The classic word jumble game where the player can ask for a hint

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int main() {
	enum fields { WORD, HINT, NUM_FIELDS };
	const int NUM_WORDS = 5;
	const std::string WORDS[NUM_WORDS][NUM_FIELDS] = {
		{"wall", "Do you feel you're banging your head against something?"},
		{"glasses", "These might help you see the answer."},
		{"labored", "Going slowly, is it?"},
		{"persistent", "Keep at it."},
		{"jumble", "It's what the game is all about."},
	};

	std::srand(static_cast<unsigned int>(std::time(0)));
	int choice = (rand() % NUM_WORDS);
	std::string theWord = WORDS[choice][WORD];
	std::string theHint = WORDS[choice][HINT];
	unsigned int score = theWord.size();

	std::string jumble = theWord;
	int length = jumble.size();
	for (std::string::size_type i = 0; i < length; i++) {
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}

	std::cout << "\t\t\tWelcome to Word Jumble!\n\n";
	std::cout << "Unscramble the letters to make a word.\n";
	std::cout << "Enter 'hint' for a hint.\n";
	std::cout << "Enter 'quit' to quit the game.\n";
	std::cout << "The jumble is: " << jumble;

	std::string guess;

	for (;;) {
		std::cout << "\n\nYour guess: ";
		std::cin >> guess;

		if (guess == "quit") {
			break;
		}

		if (guess == "hint") {
			std::cout << theHint;
			score--;
			continue;
		}

		if (guess == theWord) {
			std::cout << "\nThat's it! You gussed it!";
			std::cout << "\nYour score was " << score << std::endl;
			break;
		} else {
			std::cout << "Sorry, that's not it.";
		}
	}

	std::cout << "\nThanks for playing.\n";

	return 0;
}
