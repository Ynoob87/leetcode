#include <iostream>
#include <vector>

#include <unordered_map>

using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
    unordered_map<char, int> rowCount;
    unordered_map<char, int> colCount;
    unordered_map<char, int> boxCount;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            char val = board[i][j];
            if (val == '.')
            {
                continue;
            }

            int boxIndex = (i / 3) * 3 + (j / 3);

            if (rowCount.count(val) == 1 || colCount.count(val) == 1 || boxCount.count(val) == 1)
                return false;

            boxCount[boxIndex] = val;
            rowCount[i] = val;
            colCount[j] = val;

            cout << board[i][j];
        }
    }

    return true;
}