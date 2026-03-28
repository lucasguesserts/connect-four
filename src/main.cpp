#include "connect_four/board.hpp"

#include <iostream>

int main() {
    connect_four::Board board;

    board.drop_piece(3, connect_four::Cell::X);
    board.drop_piece(3, connect_four::Cell::O);

    std::cout << "Connect Four project is ready." << '\n';
    std::cout << "Top token in column 4 is: "
              << (board.at(1, 3) == connect_four::Cell::O ? 'O' : '?')
              << '\n';

    return 0;
}
