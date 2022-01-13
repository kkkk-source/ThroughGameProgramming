#include "player_human.h"

#include <iostream>
#include <string>

#include "board.h"

namespace game {

Human::Human(std::string name, const game::Board& board)
    : Player(name, board) {}

int Human::Move() const {
  int move;
  std::cin >> move;
  return move;
}

}  // namespace game
