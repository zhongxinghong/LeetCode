/**
 * Submission ID: 91617500
 * Question ID: 343
 * Question Title: 整数拆分
 * Question URL: https://leetcode-cn.com/problems/integer-break/
 * Solution Time: 2020-07-26 16:08:32
 * Solution Test Result: 50 / 50
 * Solution Status: Accepted
 * Solution Memory: 6.3 MB
 * Solution Runtime: 0 ms
 */

class Solution {
public:
    int integerBreak(int n)
    {
        int i, j;
        std::vector<int> dp(n + 1, 0);

        for (i = 1; i < n; ++i)
            dp[i] = i;

        for (i = 2; i <= n; ++i)
        {
            for (j = 1; j < i; ++j)
            {
                dp[i] = std::max(dp[i], j * dp[i - j]);
            }
        }

        return dp[n];
    }
};
