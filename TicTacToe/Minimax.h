#ifndef MINIMAX_H
#define MINIMAX_H

#include "Board.h"

using Boards::Board;

namespace Minimaxes
{
    class Minimax
    {
    public:
        Minimax(char given_min, char given_max)
            : min_char(given_min), max_char(given_max) {}
        int findBestMove(Board &);

    private:
        char b_copy[9];
        char min_char;
        char max_char;
        int evaluate(char[]);
        int minimax(char[], int, bool, int, int);
        int maximizer(char[], int, int, int);
        int minimizer(char[], int, int, int);
    };
}; // namespace Minimaxes

#endif