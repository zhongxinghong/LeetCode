/**
 * Submission ID: 90952247
 * Question ID: 54
 * Question Title: 螺旋矩阵
 * Question URL: https://leetcode-cn.com/problems/spiral-matrix/
 * Solution Time: 2020-07-24 10:41:25
 * Solution Test Result: 22 / 22
 * Solution Status: Accepted
 * Solution Memory: 6.8 MB
 * Solution Runtime: 4 ms
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        if (matrix.empty())
            return {};

        int n = matrix.size(), m = matrix[0].size(), k = 0, i = 0, j = 0;
        std::vector<std::vector<bool>> vis(n, std::vector<bool>(m, false));
        std::vector<int> ret(n * m);

        ret[k++] = matrix[i][j];
        vis[i][j] = true;

        while (k != n * m)
        {
            while (j + 1 != m && !vis[i][j + 1])
            {
                ret[k++] = matrix[i][++j];
                vis[i][j] = true;
            }

            while (i + 1 != n && !vis[i + 1][j])
            {
                ret[k++] = matrix[++i][j];
                vis[i][j] = true;
            }

            while (j - 1 != -1 && !vis[i][j - 1])
            {
                ret[k++] = matrix[i][--j];
                vis[i][j] = true;
            }

            while (i - 1 != -1 && !vis[i - 1][j])
            {
                ret[k++] = matrix[--i][j];
                vis[i][j] = true;
            }
        }

        return ret;
    }
};
