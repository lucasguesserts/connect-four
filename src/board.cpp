#include "connect_four/board.hpp"

#include <fmt/core.h>

namespace connect_four {

Board::Board() {
    clear();
}

void Board::clear() {
    for (auto& row : grid_) {
        row.fill(Piece::Empty);
    }
    turn_ = 0;
    for (auto& move : move_history_) {
        move = std::make_tuple(Piece::Empty, -1, -1);
    }
    has_winner_ = false;
    winner_ = Piece::Empty;
}

bool Board::add_piece(int col, Piece piece) {
    if (col >= ncols || piece == Piece::Empty || has_winner_) {
        return false;
    }

    for (int row = 0; row < nrows; ++row) {
        if (grid_[row][col] == Piece::Empty) {
            grid_[row][col] = piece;
            // Record move in history
            if (turn_ < nrows * ncols) {
                move_history_[turn_] = std::make_tuple(piece, row, col);
                ++turn_;
            }
            // Check for winner only around this move
            if (check_winner(piece, row, col)) {
                has_winner_ = true;
                winner_ = piece;
            }
            return true;
        }
    }

    return false;
}

Piece Board::at(int row, int col) const {
    if (row < 0 || row >= nrows || col < 0 || col >= ncols) {
        return Piece::Empty;
    }

    return grid_[row][col];
}

bool Board::is_full() const {
    return turn_ >= nrows * ncols;
}


// Check if placing 'piece' at (row, col) wins the game
bool Board::check_winner(Piece piece, int row, int col) const {
    if (piece == Piece::Empty) return false;
    constexpr int directions[4][2] = {
        {1, 0},   // vertical
        {0, 1},   // horizontal
        {1, 1},   // diagonal up-right
        {1, -1},  // diagonal up-left
    };
    for (const auto& dir : directions) {
        int count = 1;
        // Check in the positive direction
        int r = row + dir[0];
        int c = col + dir[1];
        while (in_bounds(r, c) && grid_[r][c] == piece) {
            ++count;
            r += dir[0];
            c += dir[1];
        }
        // Check in the negative direction
        r = row - dir[0];
        c = col - dir[1];
        while (in_bounds(r, c) && grid_[r][c] == piece) {
            ++count;
            r -= dir[0];
            c -= dir[1];
        }
        if (count >= 4) return true;
    }
    return false;
}

std::string Board::to_string() const {
    std::string result;
    // Move history
    if (turn_ > 0) {
        result += "Move history (turn: piece, row, col):\n";
        for (int i = 0; i < turn_; ++i) {
            const auto& [piece, row, col] = move_history_[i];
            // Show row as label (A-F), col as label (1-7)
            result += fmt::format("    {:2d}: {} {} {}\n", i + 1, cell_to_char(piece), row_labels[row], column_labels[col]);
        }
    }
    // Header row using column_labels
    result += "Board:\n";
    result += "    ";
    for (char col_label : column_labels) {
        result += col_label;
        result += ' ';
    }
    result += "\n";
    // Separator
    result += "   --------------- \n";
    // Rows using row_labels, bottom to top
    for (int r = nrows - 1; r >= 0; --r) {
        result += row_labels[r];
        result += " | ";
        for (int c = 0; c < ncols; ++c) {
            char ch = cell_to_char(grid_[r][c]);
            result += ch;
            result += ' ';
        }
        result += "| ";
        result += row_labels[r];
        result += "\n";
    }
    result += "   --------------- \n";
    // Footer row with column labels
    result += "    ";
    for (char col_label : column_labels) {
        result += col_label;
        result += ' ';
    }
    return result;
}

char Board::cell_to_char(Piece cell) {
        switch (cell) {
            case Piece::X: return X_char;
            case Piece::O: return O_char;
            default: return Empty_char;
        }
    }

bool Board::in_bounds(int row, int col) const {
    return row >= 0 && row < nrows && col >= 0 && col < ncols;
}

} // namespace connect_four
