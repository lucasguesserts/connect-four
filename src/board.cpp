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
}

bool Board::add_piece(int col, Piece piece) {
    if (col >= ncols || piece == Piece::Empty) {
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
            return true;
        }
    }

    return false;
}

Piece Board::at(int row, int col) const {
    if (row >= nrows || col >= ncols) {
        return Piece::Empty;
    }

    return grid_[row][col];
}

bool Board::is_full() const {
    for (const auto& row : grid_) {
        for (Piece cell : row) {
            if (cell == Piece::Empty) {
                return false;
            }
        }
    }

    return true;
}

bool Board::has_winner(Piece piece) const {
    if (piece == Piece::Empty) {
        return false;
    }

    constexpr int directions[4][2] = {
        {1, 0},
        {0, 1},
        {1, 1},
        {1, -1},
    };

    for (int row = 0; row < nrows; ++row) {
        for (int col = 0; col < ncols; ++col) {
            if (grid_[row][col] != piece) {
                continue;
            }

            for (const auto& dir : directions) {
                int matches = 1;
                int r = row;
                int c = col;

                while (matches < 4) {
                    r += dir[0];
                    c += dir[1];

                    if (!in_bounds(r, c)) {
                        break;
                    }

                    if (grid_[r][c] != piece) {
                        break;
                    }

                    ++matches;
                }

                if (matches == 4) {
                    return true;
                }
            }
        }
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
