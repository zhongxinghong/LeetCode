/**
 * Submission ID: 87492919
 * Question ID: 36
 * Question Title: 有效的数独
 * Question URL: https://leetcode-cn.com/problems/valid-sudoku/
 * Solution Time: 2020-07-13 21:15:53
 * Solution Test Result: 504 / 504
 * Solution Status: Accepted
 * Solution Memory: 7.2 MB
 * Solution Runtime: 32 ms
 */

class Solution {
public:

    std::vector<bool> mask = std::vector<bool>(10, false);

    void resetMask()
    {
        for (size_t i = 0; i < mask.size(); ++i)
            mask[i] = false;
    }

    bool fillMask(const std::vector<std::vector<char>> &board, int i, int j)
    {
        if (board[i][j] == '.')
            return true;
        if (mask[board[i][j] - '0'])
            return false;
        mask[board[i][j] - '0'] = true;
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int i, j, a, b;
        bool mask[9];

        for (i = 0; i < 9; ++i)
        {
            resetMask();
            for (j = 0; j < 9; ++j)
            {
                if (!fillMask(board, i, j))
                    return false;
            }
        }

        for (j = 0; j < 9; ++j)
        {
            resetMask();
            for (i = 0; i < 9; ++i)
            {
                if (!fillMask(board, i, j))
                    return false;
            }
        }

        for (a = 0; a < 3; ++a)
        {
            for (b = 0; b < 3; ++b)
            {
                resetMask();
                for (i = a * 3; i < (a + 1) * 3; ++i)
                {
                    for (j = b * 3; j < (b + 1) * 3; ++j)
                    {
                        if (!fillMask(board, i, j))
                            return false;
                    }
                }
            }
        }

        return true;
    }
};
