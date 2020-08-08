/**
 * Submission ID: 90993185
 * Question ID: 59
 * Question Title: 螺旋矩阵 II
 * Question URL: https://leetcode-cn.com/problems/spiral-matrix-ii/
 * Solution Time: 2020-07-24 12:30:45
 * Solution Test Result: 20 / 20
 * Solution Status: Accepted
 * Solution Memory: 6.9 MB
 * Solution Runtime: 4 ms
 */

class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int i = 0, j = 0, m = 1;
        std::vector<std::vector<int>> ret(n, std::vector<int>(n, -1));

        if (n == 0)
            return ret;

        ret[i][j] = m++;

        while (m != n * n + 1)
        {
            while (j + 1 != n && ret[i][j + 1] == -1)
                ret[i][++j] = m++;

            while (i + 1 != n && ret[i + 1][j] == -1)
                ret[++i][j] = m++;

            while (j - 1 != -1 && ret[i][j - 1] == -1)
                ret[i][--j] = m++;

            while (i - 1 != -1 && ret[i - 1][j] == -1)
                ret[--i][j] = m++;
        }

        return ret;
    }
};
