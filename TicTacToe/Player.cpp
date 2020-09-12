#include "Player.h"

namespace Players
{
    bool Player::makeMove(Boards::Board &b, int target)
    {
        return b.makeMove(target, get_move_char());
    };
}; // namespace Players