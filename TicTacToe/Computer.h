#ifndef COMPUTER_H
#define COMPUTER_H

#include "Board.h"
#include "Minimax.h"

using Minimaxes::Minimax;

namespace Computers
{
    class Computer
    {
    public:
        Computer(char p_move_char)
            : m(p_move_char, move_char) {};
        void makeMove(Boards::Board &);
        char get_move_char() const { return move_char; };

    private:
        char move_char = 'O';
        Minimax m;
    };
} // namespace Computers

#endif