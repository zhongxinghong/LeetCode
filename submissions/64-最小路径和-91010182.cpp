/**
 * Submission ID: 91010182
 * Question ID: 64
 * Question Title: 最小路径和
 * Question URL: https://leetcode-cn.com/problems/minimum-path-sum/
 * Solution Time: 2020-07-24 14:06:55
 * Solution Test Result: 61 / 61
 * Solution Status: Accepted
 * Solution Memory: 8.7 MB
 * Solution Runtime: 4 ms
 */

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int n = grid.size(), m = grid[0].size(), i, j;
        std::vector<std::vector<int>> dp(n, std::vector<int>(m));

        dp[0][0] = grid[0][0];

        for (i = 1, j = 0; i < n; ++i)
            dp[i][j] = dp[i - 1][j] + grid[i][j];

        for (i = 0, j = 1; j < m; ++j)
            dp[i][j] = dp[i][j - 1] + grid[i][j];

        for (i = 1; i < n; ++i)
        {
            for (j = 1; j < m; ++j)
            {
                dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[n - 1][m - 1];
    }
};
