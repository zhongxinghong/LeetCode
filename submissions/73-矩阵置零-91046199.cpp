/**
 * Submission ID: 91046199
 * Question ID: 73
 * Question Title: 矩阵置零
 * Question URL: https://leetcode-cn.com/problems/set-matrix-zeroes/
 * Solution Time: 2020-07-24 15:36:56
 * Solution Test Result: 159 / 159
 * Solution Status: Accepted
 * Solution Memory: 13.3 MB
 * Solution Runtime: 20 ms
 */

class Solution {
public:

    void setRow(std::vector<std::vector<int>> &matrix, int m, int i)
    {
        for (int j = 0; j < m; ++j)
            matrix[i][j] = 0;
    }

    void setCol(std::vector<std::vector<int>> &matrix, int n, int j)
    {
        for (int i = 0; i < n; ++i)
            matrix[i][j] = 0;
    }

    void setZeroes(vector<vector<int>>& matrix)
    {
        int n = matrix.size(), m = matrix[0].size(), i, j;
        bool row0 = false, col0 = false;

        for (i = 0, j = 0; j < m; ++j)
        {
            if (matrix[i][j] == 0)
            {
                row0 = true;
                break;
            }
        }

        for (i = 0, j = 0; i < n; ++i)
        {
            if (matrix[i][j] == 0)
            {
                col0 = true;
                break;
            }
        }

        for (i = 1; i < n; ++i)
        {
            for (j = 1; j < m; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for (i = 1, j = 0; i < n; ++i)
        {
            if (matrix[i][j] == 0)
                setRow(matrix, m, i);
        }

        for (i = 0, j = 1; j < m; ++j)
        {
            if (matrix[i][j] == 0)
                setCol(matrix, n, j);
        }

        if (row0)
            setRow(matrix, m, 0);

        if (col0)
            setCol(matrix, n, 0);
    }
};
