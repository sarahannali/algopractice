#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"

namespace Players
{
    class Player
    {
    public:
        bool makeMove(Boards::Board &, int);
        char get_move_char() const { return move_char; };

    private:
        char move_char = 'X';
    };
} // namespace Players

#endif