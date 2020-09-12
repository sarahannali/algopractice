#include "Board.h"

namespace Boards
{
    Board::Board()
    {
        printBoard();
    };
    void Board::printBoard()
    {
        std::cout << std::endl;

        for (int i = 0; i < 9; i++)
        {
            std::string s = "";

            if (board[i] != '\0')
                s += board[i];
            else
                s += std::to_string(i);

            if ((i + 1) % 3 != 0)
            {
                s += " | ";
            }
            else if (i != 8)
            {
                s += "\n---------\n";
            }

            std::cout << s;
        }

        std::cout << std::endl << '\n';
    };
    bool Board::makeMove(int target, char move)
    {
        if (validMove(target))
        {
            moves_left--;
            board[target] = move;
            return true;
        }

        return false;
    }; // if valid
    bool Board::gameOver()
    {
        if (
            (board[0] != '\0' && ((board[0] == board[1] && board[1] == board[2]) || (board[0] == board[4] && board[4] == board[8]) || (board[0] == board[3] && board[3] == board[6]))) ||
            (board[1] != '\0' && (board[1] == board[4] && board[1] == board[7])) ||
            (board[2] != '\0' && ((board[2] == board[5] && board[5] == board[8]) || (board[2] == board[4] && board[4] == board[6]))) ||
            (board[3] != '\0' && (board[3] == board[4] && board[4] == board[5])) ||
            (board[6] != '\0' && (board[6] == board[7] && board[7] == board[8])))
            return true;

        return false;
    };
    bool Board::validMove(int target)
    {
        if (target < 0 || target > 8)
        {
            std::cerr << "ERROR: Move must be between 0 and 8" << std::endl;
            return false;
        }

        if (board[target] != '\0')
        {
            std::cerr << "ERROR: There is already a move there!" << std::endl;
            return false;
        }

        return true;
    }; // between 0 and 8, no move already in that spot
};     // namespace Boards