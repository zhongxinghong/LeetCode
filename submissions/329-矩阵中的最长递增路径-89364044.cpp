/**
 * Submission ID: 89364044
 * Question ID: 329
 * Question Title: 矩阵中的最长递增路径
 * Question URL: https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/
 * Solution Time: 2020-07-19 17:41:08
 * Solution Test Result: 138 / 138
 * Solution Status: Accepted
 * Solution Memory: 145.3 MB
 * Solution Runtime: 524 ms
 */

class Solution {
public:

    struct point_s { int x, y; };

    void __longestIncreasingPath(
        std::vector<std::vector<int>> &matrix,
        std::vector<std::vector<int>> &dp,
        point_s p)
    {
        static const int DIRS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int n = matrix.size(), m = matrix[0].size(), x, y, k;
        std::queue<point_s> q;

        q.push(p);

        while (!q.empty())
        {
            p = q.front();
            q.pop();

            for (k = 0; k < 4; ++k)
            {
                x = p.x + DIRS[k][0];
                y = p.y + DIRS[k][1];

                if (x == -1 || x == n || y == -1 || y == m)
                    continue;

                if (matrix[x][y] <= matrix[p.x][p.y])
                    continue;

                if (dp[x][y] >= dp[p.x][p.y] + 1)
                    continue;

                dp[x][y] = dp[p.x][p.y] + 1;
                q.push({x, y});
            }
        }
    }

    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        if (matrix.empty())
            return 0;

        int n = matrix.size(), m = matrix[0].size(), x, y, maxlen = -1;
        std::vector<std::vector<int>> dp(n, std::vector<int>(m, 1));

        for (x = 0; x < n; ++x)
        {
            for (y = 0; y < m; ++y)
            {
                __longestIncreasingPath(matrix, dp, {x, y});
            }
        }

        for (x = 0; x < n; ++x)
        {
            for (y = 0; y < m; ++y)
            {
                if (maxlen < dp[x][y])
                    maxlen = dp[x][y];
            }
        }

        return maxlen;
    }
};
