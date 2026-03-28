#include "connect_four/board.hpp"

namespace connect_four {

Board::Board() {
    clear();
}

void Board::clear() {
    for (auto& row : grid_) {
        row.fill(Cell::Empty);
    }
}

bool Board::drop_piece(std::size_t col, Cell piece) {
    if (col >= cols || piece == Cell::Empty) {
        return false;
    }

    for (std::size_t row = 0; row < rows; ++row) {
        if (grid_[row][col] == Cell::Empty) {
            grid_[row][col] = piece;
            return true;
        }
    }

    return false;
}

Cell Board::at(std::size_t row, std::size_t col) const {
    if (row >= rows || col >= cols) {
        return Cell::Empty;
    }

    return grid_[row][col];
}

bool Board::is_full() const {
    for (const auto& row : grid_) {
        for (Cell cell : row) {
            if (cell == Cell::Empty) {
                return false;
            }
        }
    }

    return true;
}

bool Board::has_winner(Cell piece) const {
    if (piece == Cell::Empty) {
        return false;
    }

    constexpr int directions[4][2] = {
        {1, 0},
        {0, 1},
        {1, 1},
        {1, -1},
    };

    for (int row = 0; row < static_cast<int>(rows); ++row) {
        for (int col = 0; col < static_cast<int>(cols); ++col) {
            if (grid_[static_cast<std::size_t>(row)][static_cast<std::size_t>(col)] != piece) {
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

                    if (grid_[static_cast<std::size_t>(r)][static_cast<std::size_t>(c)] != piece) {
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

bool Board::in_bounds(int row, int col) const {
    return row >= 0 && row < static_cast<int>(rows) && col >= 0 && col < static_cast<int>(cols);
}

} // namespace connect_four
