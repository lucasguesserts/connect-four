
#ifndef CONNECT_FOUR_BOARD_HPP
#define CONNECT_FOUR_BOARD_HPP

#include <array>
#include <cstdint>
#include <string>

namespace connect_four {

enum class Piece {
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

    using Move = std::tuple<Piece, int, int>; // Piece, row, col

    Board();

    bool add_piece(int col, Piece piece);
    [[nodiscard]] Piece at(int row, int col) const;
    [[nodiscard]] bool is_full() const;
    [[nodiscard]] bool has_winner(Piece piece) const;
    void clear();

    std::string to_string() const;

    // Move history accessors
    int turn() const { return turn_; }
    const std::array<Move, nrows * ncols>& history() const { return move_history_; }

private:
    std::array<std::array<Piece, ncols>, nrows> grid_{};
    std::array<Move, nrows * ncols> move_history_{};
    int turn_ = 0;

    static char cell_to_char(Piece cell);

    [[nodiscard]] bool in_bounds(int row, int col) const;
};

} // namespace connect_four

#endif // CONNECT_FOUR_BOARD_HPP
