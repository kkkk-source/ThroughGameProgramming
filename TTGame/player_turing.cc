#include "player_turing.h"

#include "board.h"

namespace game {

Turing::Turing(const game::Board& board) : Player("Turing", board) {}

int Turing::Move() const { return 0; }

}  // namespace game
