#ifndef CONNECT_FOUR_GAME_HPP
#define CONNECT_FOUR_GAME_HPP

#include "connect_four/board.hpp"

#include <istream>
#include <ostream>

namespace connect_four {

class Game {
public:
    Game(std::istream& in, std::ostream& out);

    void run();

private:
    Board board_;
    std::istream& in_;
    std::ostream& out_;

    // Returns 0-indexed column, or -1 on EOF
    int prompt_column(Piece current_player);
};

} // namespace connect_four

#endif // CONNECT_FOUR_GAME_HPP
