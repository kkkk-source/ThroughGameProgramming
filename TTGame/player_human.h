#ifndef TTTGAME_PLAYER_HUMAN_H_
#define TTTGAME_PLAYER_HUMAN_H_

#include <string>

#include "board.h"
#include "player.h"

namespace game {

class Human : public Player {
 public:
  Human(std::string name, const game::Board& board);
  int Move() const override;
};

}  // namespace game

#endif  // TTTGAME_PLAYER_HUMAN_H_
