#include "connect_four/game.hpp"

#include <fmt/ostream.h>
#include <limits>
#include <string>

namespace connect_four {

Game::Game(std::istream& in, std::ostream& out)
    : in_(in), out_(out) {}

int Game::prompt_column(Piece current_player) {
    const char player_char = (current_player == Piece::X) ? Board::X_char : Board::O_char;

    while (true) {
        fmt::print(out_, "Player {} - enter column (1-{}): ", player_char, Board::ncols);

        std::string line;
        if (!std::getline(in_, line)) {
            return -1;
        }

        // Validate: must be a single integer
        bool valid = !line.empty();
        for (char ch : line) {
            if (ch < '0' || ch > '9') {
                valid = false;
                break;
            }
        }

        if (!valid) {
            fmt::print(out_, "Invalid input. Please enter a number between 1 and {}.\n", Board::ncols);
            continue;
        }

        int col_input = std::stoi(line);
        if (col_input < 1 || col_input > Board::ncols) {
            fmt::print(out_, "Column must be between 1 and {}.\n", Board::ncols);
            continue;
        }

        return col_input - 1; // convert to 0-indexed
    }
}

void Game::run() {
    Piece players[2] = {Piece::X, Piece::O};
    int turn = 0;

    fmt::print(out_, "=== Connect Four ===\n\n");

    while (true) {
        Piece current = players[turn % 2];

        fmt::print(out_, "{}\n", board_.to_string());

        int col = prompt_column(current);
        if (col == -1) {
            fmt::print(out_, "\nInput ended. Game aborted.\n");
            return;
        }

        if (!board_.add_piece(col, current)) {
            fmt::print(out_, "Column {} is full. Choose another column.\n", col + 1);
            continue;
        }

        if (board_.has_winner(current)) {
            fmt::print(out_, "{}\n", board_.to_string());
            const char winner_char = (current == Piece::X) ? Board::X_char : Board::O_char;
            fmt::print(out_, "Player {} wins!\n", winner_char);
            return;
        }

        if (board_.is_full()) {
            fmt::print(out_, "{}\n", board_.to_string());
            fmt::print(out_, "The board is full. It's a draw!\n");
            return;
        }

        ++turn;
    }
}

} // namespace connect_four
