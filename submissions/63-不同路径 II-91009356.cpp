/**
 * Submission ID: 91009356
 * Question ID: 63
 * Question Title: 不同路径 II
 * Question URL: https://leetcode-cn.com/problems/unique-paths-ii/
 * Solution Time: 2020-07-24 14:03:11
 * Solution Test Result: 41 / 41
 * Solution Status: Accepted
 * Solution Memory: 8.1 MB
 * Solution Runtime: 4 ms
 */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size(), i, j;
        std::vector<std::vector<int>> dp(n, std::vector<int>(m));
        bool found_obs;

        for (found_obs = false, i = 0, j = 0; j < m; ++j)
        {
            if (!found_obs && obstacleGrid[i][j] == 1)
                found_obs = true;

            dp[i][j] = !found_obs;
        }

        for (found_obs = false, i = 0, j = 0; i < n; ++i)
        {
            if (!found_obs && obstacleGrid[i][j] == 1)
                found_obs = true;

            dp[i][j] = !found_obs;
        }

        for (i = 1; i < n; ++i)
        {
            for (j = 1; j < m; ++j)
            {
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[n - 1][m - 1];
    }
};
