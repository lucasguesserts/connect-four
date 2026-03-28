# Connect Four

Connect Four is a two-player strategy game played on a vertical grid with 7 columns and 6 rows.

## How the Game Works

1. Players take turns dropping one piece into a column.
2. The piece falls to the lowest available slot in that column.
3. The first player to connect 4 pieces in a row wins.
4. A winning line can be:
	- Horizontal
	- Vertical
	- Diagonal
5. If the board fills up and no player has connected 4, the game is a draw.

## Win Pattern Examples

For the examples below, rows use the letters A-F and columns use the numbers 1-7.

### Horizontal Win

X wins with 4 in a row on the bottom line.

|   | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| F |   |   |   |   |   |   |   |
| E |   |   |   |   |   |   |   |
| D |   |   |   |   |   |   |   |
| C |   |   |   |   |   |   |   |
| B |   |   |   |   |   |   |   |
| A | O | X | X | X | X | O | O |

### Vertical Win

O wins with 4 stacked in column 4.

|   | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| F |   |   |   |   |   |   |   |
| E |   |   |   |   |   |   |   |
| D |   |   |   | O |   |   |   |
| C |   |   | X | O |   |   |   |
| B |   | X | X | O |   |   |   |
| A | X | O | X | O |   |   |   |

### Diagonal Win

X wins with a diagonal from bottom-left to top-right.

|   | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| F |   |   |   |   |   |   |   |
| E |   |   |   |   |   |   |   |
| D |   |   |   | X |   |   |   |
| C |   |   | X | O |   |   |   |
| B |   | X | O | O |   |   |   |
| A | X | O | O | X |   |   |   |

## Example Move Sequence

Columns are numbered from 1 to 7.

### Start (Empty Board)

No moves have been played yet.

|   | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| F |   |   |   |   |   |   |   |
| E |   |   |   |   |   |   |   |
| D |   |   |   |   |   |   |   |
| C |   |   |   |   |   |   |   |
| B |   |   |   |   |   |   |   |
| A |   |   |   |   |   |   |   |

### Move 1

X drops in column 4.

|   | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| F |   |   |   |   |   |   |   |
| E |   |   |   |   |   |   |   |
| D |   |   |   |   |   |   |   |
| C |   |   |   |   |   |   |   |
| B |   |   |   |   |   |   |   |
| A |   |   |   | X |   |   |   |

### Move 2

O drops in column 4.

|   | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| F |   |   |   |   |   |   |   |
| E |   |   |   |   |   |   |   |
| D |   |   |   |   |   |   |   |
| C |   |   |   |   |   |   |   |
| B |   |   |   | O |   |   |   |
| A |   |   |   | X |   |   |   |

### Move 3

X drops in column 5.

|   | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| F |   |   |   |   |   |   |   |
| E |   |   |   |   |   |   |   |
| D |   |   |   |   |   |   |   |
| C |   |   |   |   |   |   |   |
| B |   |   |   | O |   |   |   |
| A |   |   |   | X | X |   |   |

### Move 4

O drops in column 5.

|   | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| F |   |   |   |   |   |   |   |
| E |   |   |   |   |   |   |   |
| D |   |   |   |   |   |   |   |
| C |   |   |   |   |   |   |   |
| B |   |   |   | O | O |   |   |
| A |   |   |   | X | X |   |   |

### Move 5

X drops in column 6.

|   | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| F |   |   |   |   |   |   |   |
| E |   |   |   |   |   |   |   |
| D |   |   |   |   |   |   |   |
| C |   |   |   |   |   |   |   |
| B |   |   |   | O | O |   |   |
| A |   |   |   | X | X | X |   |

### Move 6

O drops in column 6.

|   | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| F |   |   |   |   |   |   |   |
| E |   |   |   |   |   |   |   |
| D |   |   |   |   |   |   |   |
| C |   |   |   |   |   |   |   |
| B |   |   |   | O | O | O |   |
| A |   |   |   | X | X | X |   |

### Move 7

X drops in column 7 and wins with a horizontal connect four on row A (columns 4 through 7).

|   | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| F |   |   |   |   |   |   |   |
| E |   |   |   |   |   |   |   |
| D |   |   |   |   |   |   |   |
| C |   |   |   |   |   |   |   |
| B |   |   |   | O | O | O |   |
| A |   |   |   | X | X | X | X |
