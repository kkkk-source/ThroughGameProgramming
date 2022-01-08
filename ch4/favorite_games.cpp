#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main() {
	enum options { READ = 1, CREATE, DELETE, EXIT };
	std::vector<std::string> games;

	for (;;) {
		std::cout << "\n\nFavorite Games Maintainer\n";
		std::cout << "\n1 - List all games titles";
		std::cout << "\n2 - Add a game title";
		std::cout << "\n3 - Remove a game title";
		std::cout << "\n4 - Quit";
		std::cout << "\nChose what you want to do: ";
		int opt;
		std::cin >> opt;

		if (opt == options::CREATE) {
			std::cout << "\nEnter the new game title name: ";
			std::string name;
			std::cin >> name;
			games.push_back(name);
			continue;
		}

		if (opt == options::READ) { 
			for (std::vector<std::string>::const_iterator iter = games.begin(); iter != games.end(); iter++) {
				std::cout << *iter << " ";
			} 
			std::cout << std::endl;
			continue;
		}

		if (opt == options::DELETE) {
			std::cout << "\nWrite the name of the game title you want to delete: ";
			std::string name;
			std::cin >> name;

			std::vector<std::string>::iterator iter;
			iter = std::find(games.begin(), games.end(), name);

			if (iter == games.end()) {
				std::cout << "Could not find " << name << std::endl;
				continue;
			}

			games.erase(iter);
			continue;
		}

		if (opt == options::EXIT) {
			return 0;
		}
	}

	return 0;
}
