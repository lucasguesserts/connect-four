
#ifndef CONNECT_FOUR_BOARD_HPP
#define CONNECT_FOUR_BOARD_HPP

#include <array>
#include <cstdint>
#include <string>

namespace connect_four {

enum class Cell {
    Empty,
    X,
    O,
};

class Board {
public:
    static constexpr int nrows = 6;
    static constexpr int ncols = 7;
    static constexpr std::array<char, ncols> column_labels = {'1', '2', '3', '4', '5', '6', '7'};
    static constexpr std::array<char, nrows> row_labels = {'A', 'B', 'C', 'D', 'E', 'F'};
    static constexpr char X_char = 'X';
    static constexpr char O_char = 'O';
    static constexpr char Empty_char = '.';

    Board();

    bool add_piece(int col, Cell piece);
    [[nodiscard]] Cell at(int row, int col) const;
    [[nodiscard]] bool is_full() const;
    [[nodiscard]] bool has_winner(Cell piece) const;
    void clear();

    std::string to_string() const;

private:
    std::array<std::array<Cell, ncols>, nrows> grid_{};

    static char cell_to_char(Cell cell);

    [[nodiscard]] bool in_bounds(int row, int col) const;
};

} // namespace connect_four

#endif // CONNECT_FOUR_BOARD_HPP
