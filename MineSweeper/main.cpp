#include <algorithm>
#include <queue>
#include <iostream>

class Board
{
public:
    Board()
    {
        createBombs();
    }; // make board, add bombs, count bombs? and have visual if true?
    bool makeMove()
    {
        int select;

        std::cout << "Would you like to select a box (0) or add a flag (1) or quit (3)? "; // error checking
        std::cin >> select;

        if (select == 3)
            return false;

        int row;
        int col;

        std::cout << "What row? ";
        std::cin >> row;

        std::cout << "What col? ";
        std::cin >> col;

        if (select == 0)
            return selectBox(row, col);
        else
            addFlag(row, col);

        return true;
    }
    void printBoard()
    {
        for (int c = 0; c < cols; c++)
        {
            std::cout << '\t' << c;
        }

        std::cout << std::endl;

        for (int r = 0; r < rows; r++)
        {
            std::cout << r << '\t';
            for (int c = 0; c < cols; c++)
            {
                if (board_visited[r][c] == false)
                    std::cout << 'X' << '\t';
                else
                {
                    if (flag[r][c] == true)
                        std::cout << 'F' << '\t';
                    else if (board[r][c] == -1)
                        std::cout << '*' << '\t';
                    else
                        std::cout << board[r][c] << '\t';
                }
            }

            std::cout << std::endl;
        }
    };
    bool gameOver()
    {
        return empty_spaces == needed_spaces;
    }

private:
    const static int rows = 8;
    const static int cols = 8;
    int board[rows][cols] = {0};
    bool board_visited[rows][cols] = {false};
    bool flag[rows][cols] = {false};
    int empty_spaces = 0;
    int needed_spaces = rows * cols;
    void createBombs()
    {
        for (int i = 1; i < 10; i++)
        {
            int row = rand() % 7;
            int col = rand() % 7;

            board[row][col] = -1;
            needed_spaces--;

            if (row + 1 < rows)
            {
                if (board[row + 1][col] != -1)
                    board[row + 1][col]++;

                if (col + 1 < cols && board[row + 1][col + 1] != -1)
                    board[row + 1][col + 1]++;

                if (col - 1 >= 0 && board[row + 1][col - 1] != -1)
                    board[row + 1][col - 1]++;
            }
            if (row - 1 >= 0)
            {
                if (board[row - 1][col] != -1)
                    board[row - 1][col]++;

                if (col + 1 < cols && board[row - 1][col + 1] != -1)
                    board[row - 1][col + 1]++;

                if (col - 1 >= 0 && board[row - 1][col - 1] != -1)
                    board[row - 1][col - 1]++;
            }
            if (col + 1 < cols && board[row][col + 1] != -1)
                board[row][col + 1]++;
            if (col - 1 >= 0 && board[row][col - 1] != -1)
                board[row][col - 1]++;
        }
    };
    bool selectBox(int row, int col)
    {
        if (board[row][col] == -1)
        {
            board_visited[row][col] = true;
            return false;
        }

        std::queue<std::pair<int, int>> to_visit;

        to_visit.push(std::make_pair(row, col));

        while (!to_visit.empty())
        {
            int r = to_visit.front().first;
            int c = to_visit.front().second;

            board_visited[r][c] = true;
            empty_spaces++;
            if (board[r][c] != 0)
            {
                to_visit.pop();
                continue;
            }

            if (r + 1 < rows && board_visited[r + 1][c] == false)
                to_visit.push(std::make_pair(r + 1, c));
            if (r - 1 >= 0 && board_visited[r - 1][c] == false)
                to_visit.push(std::make_pair(r - 1, c));
            if (c + 1 < cols && board_visited[r][c + 1] == false)
                to_visit.push(std::make_pair(r, c + 1));
            if (c - 1 >= 0 && board_visited[r][c - 1] == false)
                to_visit.push(std::make_pair(r, c - 1));

            to_visit.pop();
        }

        return true;
    }
    void addFlag(int row, int col)
    {
        board_visited[row][col] = true;
        flag[row][col] = true;
    }
};

int main()
{
    Board b;
    b.printBoard();

    while (b.makeMove())
    {
        b.printBoard();
        if (b.gameOver())
        {
            std::cout << "You've won :)";
            return 0;
        };
    }

    b.printBoard();
    std::cout << "You've lost :(";

    return 0;
}