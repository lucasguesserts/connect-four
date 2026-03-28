#include "connect_four/board.hpp"

#include <fmt/core.h>

int main() {
    connect_four::Board board;

    fmt::print("Initial board state:\n{}\n", board.to_string());

    fmt::print("Adding pieces to the board...\n");
    board.add_piece(3, connect_four::Piece::X);
    board.add_piece(3, connect_four::Piece::O);
    fmt::print("{}\n", board.to_string());
    fmt::print("Is the board full? {}\n", board.is_full() ? "Yes" : "No");
    fmt::print("Is there a winner? {}\n", board.has_winner() ? "Yes" : "No");
    if (board.has_winner()) {
        fmt::print("Winner: {}\n", board.cell_to_char(board.winner()));
    }

    return 0;
}
