#include "Minimax.h"
#include <algorithm>

namespace Minimaxes
{

    int Minimax::findBestMove(Board &b)
    {
        int best_val = std::numeric_limits<int>::min();
        int best_move = 0;
        int moves_left = 0;

        for (int i = 0; i < 9; i++)
        {
            b_copy[i] = b.get_board_position(i);
            if (b_copy[i] == '\0')
                moves_left++;
        }

        for (int i = 0; i < 9; i++)
        {
            if (b_copy[i] == '\0')
            {
                b_copy[i] = max_char;
                int new_val = minimax(b_copy, moves_left - 1, false, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
                if (new_val > best_val)
                {
                    best_val = new_val;
                    best_move = i;
                }

                b_copy[i] = '\0';
            }
        }

        return best_move;
    }

    int Minimax::minimax(char b[], int moves_left, bool is_max, int alpha, int beta)
    {
        int score = evaluate(b);

        if (score > 0)
        {
            return score - (9 - moves_left);
        }

        if (score < 0)
        {
            return score + (9 - moves_left);
        }

        if (moves_left == 0)
            return 0;

        if (is_max)
        {
            return maximizer(b, moves_left, alpha, beta);
        }
        else
        {
            return minimizer(b, moves_left, alpha, beta);
        }

        return 0;
    }

    int Minimax::evaluate(char b[])
    {
        // row win
        if ((b[0] != '\0' && (b[0] == b[1] && b[1] == b[2])))
        {
            if (b[0] == max_char)
                return +10;
            return -10;
        }

        if ((b[3] != '\0' && (b[3] == b[4] && b[4] == b[5])))
        {
            if (b[3] == max_char)
                return +10;
            return -10;
        }

        if ((b[6] != '\0' && (b[6] == b[7] && b[7] == b[8])))
        {
            if (b[6] == max_char)
                return +10;
            return -10;
        }

        // column win
        if ((b[0] != '\0' && (b[0] == b[3] && b[3] == b[6])))
        {
            if (b[0] == max_char)
                return +10;
            return -10;
        }

        if ((b[1] != '\0' && (b[1] == b[4] && b[4] == b[7])))
        {
            if (b[1] == max_char)
                return +10;
            return -10;
        }

        if ((b[2] != '\0' && (b[2] == b[5] && b[5] == b[8])))
        {
            if (b[2] == max_char)
                return +10;
            return -10;
        }

        // diagonal win
        if ((b[0] != '\0' && (b[0] == b[4] && b[4] == b[8])))
        {
            if (b[0] == max_char)
                return +10;
            return -10;
        }

        if ((b[2] != '\0' && (b[2] == b[4] && b[4] == b[6])))
        {
            if (b[2] == max_char)
                return +10;
            return -10;
        }

        return 0;
    }

    int Minimax::maximizer(char b[], int moves_left, int alpha, int beta)
    {
        int best_val = std::numeric_limits<int>::min();

        for (int i = 0; i < 9; i++)
        {
            if (b[i] == '\0')
            {
                b[i] = max_char;
                best_val = std::max(best_val, minimax(b, moves_left - 1, false, alpha, beta));
                alpha = std::max(alpha, best_val);

                b[i] = '\0';
            }

            if (beta <= alpha)
                break;
        }

        return best_val;
    }

    int Minimax::minimizer(char b[], int moves_left, int alpha, int beta)
    {
        int best_val = std::numeric_limits<int>::max();

        for (int i = 0; i < 9; i++)
        {
            if (b[i] == '\0')
            {
                b[i] = min_char;
                best_val = std::min(best_val, minimax(b, moves_left - 1, true, alpha, beta));
                beta = std::min(beta, best_val);

                b[i] = '\0';
            }

            if (beta <= alpha)
                break;
        }

        return best_val;
    }

} // namespace Minimaxes