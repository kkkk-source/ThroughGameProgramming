// Game Lobby
// Simulates a game lobby where players wait

#include <iostream>
#include <string>

class Player {
	public:
		Player(const std::string& name = "");
		std::string GetName() const;
		Player* GetNext() const;
		void SetNext(Player* next);

	private:
		std::string m_Name;
		Player* m_pNext; // Pointer to next player in list
};

Player::Player(const std::string& name):
	m_Name(name),
	m_pNext(0)
{}

std::string Player::GetName() const {
	return m_Name;
}

Player* Player::GetNext() const {
	return m_pNext;
}

void Player::SetNext(Player* next) {
	m_pNext = next;
}




class Lobby {
	friend std::ostream& operator<<(std::ostream& os, const Lobby& aLobby);

	public:
		Lobby();
		~Lobby();
		void AddPlayer();
		void RemovePlayer();
		void Clear();

	private:
		Player* m_pHead;
		Player* m_pTail;
};

Lobby::Lobby(): m_pHead(0) {}

Lobby::~Lobby() {
	Clear();
}

void Lobby::AddPlayer() {
	// create a new player node
	std::cout << "Please enter the name of the new player: ";
	std::string name;
	std::cin >> name;
	Player* pNewPlayer = new Player(name);

	// if list is empty, make a head of list this new player
	if (m_pHead == 0) {
		m_pHead = pNewPlayer;
		m_pTail = pNewPlayer;
		return;
	}

	m_pTail->SetNext(pNewPlayer);
	m_pTail = pNewPlayer;
}


void Lobby::RemovePlayer() {
	if (m_pHead == 0) {
		std::cout << "The game lobby is empty. No one to remove!\n";
		return;
	}

	Player* pTemp = m_pHead;
	m_pHead = m_pHead->GetNext();
	delete pTemp;
}

void Lobby::Clear() {
	while (m_pHead != 0) {
		RemovePlayer();
	}
}

std::ostream& operator<<(std::ostream& os, const Lobby& aLobby) {
	Player* pIter = aLobby.m_pHead;
	os << "\nHere's who's in the game lobby:\n";
	if (pIter == 0) {
		os << "The lobby is empty.\n";
		return os;
	}

	while (pIter != 0) {
		os << pIter->GetName() << std::endl;
		pIter = pIter->GetNext();
	}

	return os;
}


int main() {
	Lobby myLobby;
	int choice;

	do {
		std::cout << myLobby;
		std::cout << "\nGAME LOBBY\n";
		std::cout << "0 - Exit the program.\n";
		std::cout << "1 - Add a player to the lobby.\n";
		std::cout << "2 - Remove a player from the lobby.\n";
		std::cout << "3 - Clear the lobby.\n";
		std::cout << std::endl << "Choice: ";
		std::cin >> choice;

		switch (choice) {
			case 0: 
				std::cout << "Good-bye.\n";
				break;
			case 1:
				myLobby.AddPlayer();
				break;
			case 2:
				myLobby.RemovePlayer();
				break;
			case 3:
				myLobby.Clear();
				break;
			default:
				std::cout << "That was not a valid choice.\n";
		}

	} while (choice != 0);

	return 0;
}
