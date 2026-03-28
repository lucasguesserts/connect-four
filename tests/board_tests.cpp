#include <doctest/doctest.h>

#include "connect_four/board.hpp"

using connect_four::Board;
using connect_four::Piece;

TEST_CASE("A dropped piece falls to the lowest row") {
    Board board;

    CHECK(board.add_piece(0, Piece::X));
    CHECK(board.at(0, 0) == Piece::X);

    CHECK(board.has_winner() == false);
    CHECK(board.winner() == Piece::Empty);
}

TEST_CASE("Pieces stack in a column") {
    Board board;

    CHECK(board.add_piece(2, Piece::X));
    CHECK(board.add_piece(2, Piece::O));

    CHECK(board.at(0, 2) == Piece::X);
    CHECK(board.at(1, 2) == Piece::O);

    CHECK_FALSE(board.has_winner());
    CHECK(board.winner() == Piece::Empty);
}

TEST_CASE("Board detects horizontal winner") {
    Board board;

    CHECK(board.add_piece(0, Piece::X));
    CHECK(board.add_piece(1, Piece::X));
    CHECK(board.add_piece(2, Piece::X));
    CHECK(board.add_piece(3, Piece::X));

    CHECK(board.has_winner());
    CHECK(board.winner() == Piece::X);
}

TEST_CASE("Board detects vertical winner") {
    Board board;

    CHECK(board.add_piece(1, Piece::O));
    CHECK(board.add_piece(1, Piece::O));
    CHECK(board.add_piece(1, Piece::O));
    CHECK(board.add_piece(1, Piece::O));

    CHECK(board.has_winner());
    CHECK(board.winner() == Piece::O);
}

TEST_CASE("Board detects anti-diagonal winner") {
    Board board;

    CHECK(board.add_piece(3, Piece::X));

    CHECK(board.add_piece(2, Piece::O));
    CHECK(board.add_piece(2, Piece::X));

    CHECK(board.add_piece(1, Piece::O));
    CHECK(board.add_piece(6, Piece::X));
    CHECK(board.add_piece(1, Piece::O));
    CHECK(board.add_piece(1, Piece::X));

    CHECK(board.add_piece(0, Piece::O));
    CHECK(board.add_piece(1, Piece::X));
    CHECK(board.add_piece(0, Piece::O));
    CHECK(board.add_piece(1, Piece::X));
    CHECK(board.add_piece(0, Piece::O));

    // This move should win the game
    CHECK(board.add_piece(0, Piece::X));
    CHECK(board.has_winner());
    CHECK(board.winner() == Piece::X);

    // Further moves should not be allowed
    CHECK(!board.add_piece(0, Piece::O));
}

TEST_CASE("Board detects diagonal winner") {
    Board board;

    CHECK(board.add_piece(0, Piece::X));

    CHECK(board.add_piece(1, Piece::O));
    CHECK(board.add_piece(1, Piece::X));

    CHECK(board.add_piece(2, Piece::O));
    CHECK(board.add_piece(2, Piece::O));
    CHECK(board.add_piece(2, Piece::X));

    CHECK(board.add_piece(3, Piece::O));
    CHECK(board.add_piece(3, Piece::O));
    CHECK(board.add_piece(3, Piece::O));
    CHECK(board.add_piece(3, Piece::X));

    CHECK(board.has_winner());
    CHECK(board.winner() == Piece::X);
}
