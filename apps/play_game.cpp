#include "connect_four/game.hpp"

#include <iostream>

int main() {
    connect_four::Game game(std::cin, std::cout);
    game.run();
    return 0;
}
