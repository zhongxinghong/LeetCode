/**
 * Submission ID: 91534191
 * Question ID: 312
 * Question Title: 戳气球
 * Question URL: https://leetcode-cn.com/problems/burst-balloons/
 * Solution Time: 2020-07-26 11:19:51
 * Solution Test Result: 70 / 70
 * Solution Status: Accepted
 * Solution Memory: 8.7 MB
 * Solution Runtime: 32 ms
 */

class Solution {
public:

    int maxCoins(vector<int>& nums)
    {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);

        int n = nums.size(), i, j, k, len;
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

        for (len = 3; len <= n; ++len)
        {
            for (i = 0, j = len - 1; j < n; ++i, ++j)
            {
                for (k = i + 1; k < j; ++k)
                    dp[i][j] = std::max(dp[i][j],
                                        dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j]);
            }
        }

        return dp[0][n - 1];
    }
};
