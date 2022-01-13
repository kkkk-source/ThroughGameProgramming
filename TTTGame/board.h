#ifndef TTTGAME_BOARD_H_
#define TTTGAME_BOARD_H_

#include <vector>

namespace game {

class Board {
 public:
  Board();
  void Draw();
  bool Move(int move);
  bool Valid(int move);

 private:
  std::vector<char> board;
};

}  // namespace game

#endif  // TTTGAME_BOARD_H_
