#include "Computer.h"

namespace Computers
{
    void Computer::makeMove(Boards::Board &b)
    {
        b.makeMove(m.findBestMove(b), get_move_char());
    };
} // namespace Computers