#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<char, int> rowMap;
        unordered_map<char, int> colMap;
        unordered_map<char, int> boxMap;

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board.size(); j++)
            {
                char value = board[i][j];

                if (value == '.')
                    continue;

                int boxIndex = (i / 3) * 3 + (j / 3);

                if (rowMap[i] == value || colMap[j] == value || boxMap[boxIndex] == value)
                    return false;

                boxMap[boxIndex] = value;
                rowMap[i] = value;
                colMap[j] = value;
            }
        }

        return true;
    }
};