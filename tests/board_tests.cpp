#include <doctest/doctest.h>

#include "connect_four/board.hpp"

using connect_four::Board;
using connect_four::Cell;

TEST_CASE("A dropped piece falls to the lowest row") {
    Board board;

    CHECK(board.drop_piece(0, Cell::X));
    CHECK(board.at(0, 0) == Cell::X);
}

TEST_CASE("Pieces stack in a column") {
    Board board;

    CHECK(board.drop_piece(2, Cell::X));
    CHECK(board.drop_piece(2, Cell::O));

    CHECK(board.at(0, 2) == Cell::X);
    CHECK(board.at(1, 2) == Cell::O);
}

TEST_CASE("Board detects horizontal winner") {
    Board board;

    CHECK(board.drop_piece(0, Cell::X));
    CHECK(board.drop_piece(1, Cell::X));
    CHECK(board.drop_piece(2, Cell::X));
    CHECK(board.drop_piece(3, Cell::X));

    CHECK(board.has_winner(Cell::X));
}

TEST_CASE("Board detects vertical winner") {
    Board board;

    CHECK(board.drop_piece(1, Cell::O));
    CHECK(board.drop_piece(1, Cell::O));
    CHECK(board.drop_piece(1, Cell::O));
    CHECK(board.drop_piece(1, Cell::O));

    CHECK(board.has_winner(Cell::O));
}

TEST_CASE("Board detects diagonal winner") {
    Board board;

    CHECK(board.drop_piece(0, Cell::X));

    CHECK(board.drop_piece(1, Cell::O));
    CHECK(board.drop_piece(1, Cell::X));

    CHECK(board.drop_piece(2, Cell::O));
    CHECK(board.drop_piece(2, Cell::O));
    CHECK(board.drop_piece(2, Cell::X));

    CHECK(board.drop_piece(3, Cell::O));
    CHECK(board.drop_piece(3, Cell::O));
    CHECK(board.drop_piece(3, Cell::O));
    CHECK(board.drop_piece(3, Cell::X));

    CHECK(board.has_winner(Cell::X));
}
