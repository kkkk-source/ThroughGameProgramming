#include "player.h"

#include <string>

#include "board.h"

namespace game {

Player::Player(std::string name, const game::Board& board)
    : name{name}, board{board} {}

std::string Player::GetName() const { return name; }

}  // namespace game
