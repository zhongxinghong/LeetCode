/**
 * Submission ID: 90799574
 * Question ID: 100231
 * Question Title: 硬币
 * Question URL: https://leetcode-cn.com/problems/coin-lcci/
 * Solution Time: 2020-07-23 20:08:34
 * Solution Test Result: 30 / 30
 * Solution Status: Accepted
 * Solution Memory: 14.5 MB
 * Solution Runtime: 84 ms
 */

class Solution {
public:
    int waysToChange(int n)
    {
        static const int M = 1e9 + 7;
        static const int coins[4] = {25, 10, 5, 1};

        int i, j;
        std::vector<int> dp(n + 1);

        dp[0] = 1;

        for (i = 0; i < 4; ++i)
        {
            for (j = coins[i]; j <= n; ++j)
                dp[j] = (dp[j] + dp[j - coins[i]]) % M;
        }

        return dp[n];
    }
};
