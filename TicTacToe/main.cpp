#include <iostream>
#include <string>
#include <algorithm>

#include "Board.h"
#include "Player.h"
#include "Computer.h"

using Boards::Board;
using Computers::Computer;
using Players::Player;

int main()
{
    std::cout << "TIC TAC TOE" << std::endl;
    std::cout << "You are X, Computer is O" << std::endl;

    Board b;

    Player p;
    Computer c(p.get_move_char());

    while (!b.gameOver())
    {
        if (b.get_moves_left() == 0)
        {
            std::cout << "\nIt's a tie!";
            return 0;
        }

        int move;
        std::cout << "Where would you like to move? ";
        std::cin >> move;

        while (std::cin.fail())
        {
            std::cerr << "ERROR: You did not enter an integer" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Where would you like to move? ";
            std::cin >> move;
        }

        while (!p.makeMove(b, move))
        {
            std::cout << "Where would you like to move? ";
            std::cin >> move;
        }

        if (b.gameOver())
        {
            b.printBoard();
            std::cout << "\nPlayer wins!";
            return 0;
        }

        c.makeMove(b);
        b.printBoard();
        //tie
    }

    std::cout << "\nComputer wins!";

    return 0;
}