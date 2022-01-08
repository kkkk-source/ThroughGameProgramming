// Tic-Tac-Toe
// Plays the game of tic-tac-toe against a human opponent

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// global constants
const char X = 'X'; 
const char O = 'O'; 
const char EMPTY = ' '; 
const char TIE = 'T'; 
const char NO_ONE = 'N'; 

// function prototypes
void instructions();
bool askYesNo(std::string questionl);
int askNumber(std::string question, int high = 8, int low = 0);
char humanPiece();
char opponent(char piece);
void displayBoard(const std::vector<char>& board);
char winner(const std::vector<char>& board);
bool isLegal(int move, const std::vector<char>& board);
int humanMove(const std::vector<char>& board, char human);
int computerMove(std::vector<char> board, char computer);
void announceWinner(char winner, char computer, char human);

int main() {
	int move;
	const int NUM_SQUARES = 9;
	std::vector<char> board(NUM_SQUARES, EMPTY);

	instructions();
	char human = humanPiece();
	char computer = opponent(human);
	char turn = X;

        displayBoard(board);

	while (winner(board) == NO_ONE) {
		if (turn == human) {
			move = humanMove(board, human);
			board[move] = human;
		} else {
			move = computerMove(board, computer);
			board[move] = computer;
		}

		displayBoard(board);
		turn = opponent(turn);
	}

	announceWinner(winner(board), computer, human);
	return 0;
}

void instructions() {
	std::cout << "Welcome to the ultimate main-machine showdown: Tic-Tac-Toe.\n";
	std::cout << "--where human brain is pit against silicon processor\n\n";
	std::cout << "Make your move known by entering a number, 0 - 8. The number\n";
	std::cout << "corresponds to the desired desired board position, as illustrated:\n\n";
	std::cout << " 0 | 1 | 2\n";
	std::cout << " 3 | 4 | 5\n";
	std::cout << " 6 | 7 | 8\n\n";
	std::cout << "Prepare yourself, human. The battle is about to begin.\n\n";
}

void displayBoard(const std::vector<char>& board) {
	std::cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
	std::cout << "\n\t---------";
	std::cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
	std::cout << "\n\t---------";
	std::cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
	std::cout << "\n\n";
}

char winner(const std::vector<char>& board) {
	// all possible winning rows
	const int WINNING_ROWS[8][3] = {
		{ 0, 1, 2},
		{ 3, 4, 5},
		{ 6, 7, 8},
		{ 0, 3, 6},
		{ 1, 4, 7},
		{ 2, 5, 8},
		{ 0, 4, 8},
		{ 2, 4, 6},
	};

	const int TOTAL_ROWS = 8;

	// if any winning row has three values that are the same (and not
	// EMPTY), then we have a winner
	for (int row = 0; row < TOTAL_ROWS; row++) {
		if (
			board[WINNING_ROWS[row][0]] != EMPTY &&
			board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]] &&
			board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]
		   ) {
			return board[WINNING_ROWS[row][0]];
		}
	}

	// since nobody has won, check for a tie (no empty squares left)
	if (std::count(board.begin(), board.end(), EMPTY) == 0) {
		return TIE;
	}

	// since nobody has won and it isn't a tie, the game ain't over
	return NO_ONE;
}


char humanPiece() {
	char wantGoFirst = askYesNo("Do you require the first move?");
	if (wantGoFirst) {
		std::cout << "\nThen take the first move. You will need it.\n";
		return X;
	} else {
		std::cout << "\nYour bravery will be your undoing...I will go first.\n";
		return O;
	}
}

bool askYesNo(std::string question) {
	char response;
	do {
		std::cout << question << " (y\\n): ";
		std::cin >> response;
	} while (response != 'y' && response != 'n');

	return response == 'y';
}

int humanMove(const std::vector<char>& board, char human) {
	int move = askNumber("Where will you move?");
	while (!isLegal(move, board)) {
		std::cout << "\nThat square is already occupied, foolish human.\n";
		move = askNumber("Where will you move?");
	}
	std::cout << "Fine...\n";

	return move;
}

int askNumber(std::string question, int high, int low) {
	int number;
	do {
		std::cout << question << " (" << low << " - " << high << "): ";
		std::cin >> number;
	} while (number > high || number < low);

	return number;
}

int computerMove(std::vector<char> board, char computer) {
	unsigned int move = 0;
	bool found = false;

	// if computer con win on next move, that's the move to make
	while (!found && move < board.size()) {
		if (isLegal(move, board)) {
			board[move] = computer;
			found = winner(board) == computer;
			board[move] = EMPTY;
		}

		if (!found) {
			move++;
		}
	}

	if (found) {
		std::cout << "I shall take square number " << move << std::endl;
		return move;
	}

	move = 0;
	char human = opponent(computer);

	while (!found && move < board.size()) {
		if (isLegal(move, board)) {
			board[move] = human;
			found = winner(board) == human;
			board[move] = EMPTY;
		}

		if (!found) {
			move++;
		}
	}

	if (found) {
		std::cout << "I shall take square number " << move << std::endl;
		return move;
	}

	move = 0;
	const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};
	for (unsigned int i = 0; !found && i < board.size(); i++) {
		move = BEST_MOVES[i];
		if (isLegal(move, board)) {
			found = true;
		}
	}

	std::cout << "I shall take square number " << move << std::endl;
	return move;
}

inline bool isLegal(int move, const std::vector<char>& board) {
	return board[move] == EMPTY;
}

inline char opponent(char piece) {
	return piece == X ? O : X;
}

void announceWinner(char winner, char computer, char human) {
	if (winner == computer) {
		std::cout << winner << "'s won!\n";
		std::cout << "As I predicted, human, I am triumphant once more -- proof\n";
		std::cout << "that computers are superior to humans in all regards.\n";
	} else if (winner == human) {
		std::cout << winner << "'s won!\n";
		std::cout << "No, no! It cannot be! Somehow you tricked me, human.\n";
		std::cout << "But never again! I, the computer, so swear it!\n";
	} else {
		std::cout << "It's a tie.\n";
		std::cout << "You were most lucky, human, and somehow managed to tie me.\n";
		std::cout << "Celebrate...for this is the best you will ever achieve.\n";
	}
}
