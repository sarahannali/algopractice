#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>

namespace Boards
{

    class Board
    {
    public:
        Board();
        void printBoard();
        bool makeMove(int, char);
        bool gameOver();
        char get_board_position(int i) const { return board[i]; };
        int get_moves_left() const { return moves_left; };

    private:
        char board[9] = {};
        int moves_left = 9;
        bool validMove(int); // between 0 and 8, no move already in that spot
    };
} // namespace Boards

#endif