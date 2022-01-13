#ifndef TTTGAME_PLAYER_H_
#define TTTGAME_PLAYER_H_

#include <string>

#include "board.h"

namespace game {
class Player {
 public:
  Player(std::string name, const game::Board& board);
  virtual int Move() const = 0;
  virtual std::string GetName() const;

 private:
  std::string name;
  const game::Board& board;
};
}  // namespace game

#endif  // TTTGAME_PLAYER_H_
