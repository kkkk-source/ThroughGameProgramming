#ifndef TTTGAME_PLAYER_TURING_H_
#define TTTGAME_PLAYER_TURING_H_

#include <string>

#include "board.h"
#include "player.h"

namespace game {

class Turing : public Player {
 public:
  Turing(const game::Board& board);
  int Move() const override;
};

}  // namespace game

#endif  // TTTGAME_PLAYER_TURING_H_
