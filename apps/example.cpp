#include "connect_four/board.hpp"

#include <fmt/core.h>

int main() {
    connect_four::Board board;

    fmt::print("Initial board state:\n{}\n", board.to_string());

    fmt::print("Adding pieces to the board...\n");
    board.add_piece(3, connect_four::Cell::X);
    board.add_piece(3, connect_four::Cell::O);;
    fmt::print("{}\n", board.to_string());
    fmt::print("Is the board full? {}\n", board.is_full() ? "Yes" : "No");
    fmt::print("Does X have a winning position? {}\n", board.has_winner(connect_four::Cell::X) ? "Yes" : "No");
    fmt::print("Does O have a winning position? {}\n", board.has_winner(connect_four::Cell::O) ? "Yes" : "No");

    return 0;
}
