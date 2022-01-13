#include <iostream>

#include "player.h"
#include "player_human.h"
#include "player_turing.h"

void TestPlayers(game::Player& player1, game::Player& player2) {
  std::cout << player1.GetName() << "\n";
  std::cout << player1.Move();

  std::cout << player2.GetName() << "\n";
  std::cout << player2.Move();
}

int main() {
  game::Board board;
  game::Human human{"moll-y", board};
  game::Turing turing{board};

  TestPlayers(human, turing);

  return 0;
}
