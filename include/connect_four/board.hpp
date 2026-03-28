
#ifndef CONNECT_FOUR_BOARD_HPP
#define CONNECT_FOUR_BOARD_HPP

#include <array>
#include <cstddef>

namespace connect_four {

enum class Cell {
    Empty,
    X,
    O,
};

class Board {
public:
    static constexpr std::size_t rows = 6;
    static constexpr std::size_t cols = 7;

    Board();

    bool drop_piece(std::size_t col, Cell piece);
    [[nodiscard]] Cell at(std::size_t row, std::size_t col) const;
    [[nodiscard]] bool is_full() const;
    [[nodiscard]] bool has_winner(Cell piece) const;
    void clear();

private:
    std::array<std::array<Cell, cols>, rows> grid_{};

    [[nodiscard]] bool in_bounds(int row, int col) const;
};

} // namespace connect_four

#endif // CONNECT_FOUR_BOARD_HPP
