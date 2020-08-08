/**
 * Submission ID: 91267409
 * Question ID: 120
 * Question Title: 三角形最小路径和
 * Question URL: https://leetcode-cn.com/problems/triangle/
 * Solution Time: 2020-07-25 12:40:11
 * Solution Test Result: 43 / 43
 * Solution Status: Accepted
 * Solution Memory: 8.5 MB
 * Solution Runtime: 8 ms
 */

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int i, j, n = triangle.size();
        std::vector<int> dp = triangle.back();

        for (i = n - 2; i > -1; --i)
        {
            for (j = 0; j <= i; ++j)
                dp[j] = std::min(dp[j], dp[j + 1]) + triangle[i][j];
        }

        return dp[0];
    }
};
