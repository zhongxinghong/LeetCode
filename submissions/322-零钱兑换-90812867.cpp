/**
 * Submission ID: 90812867
 * Question ID: 322
 * Question Title: 零钱兑换
 * Question URL: https://leetcode-cn.com/problems/coin-change/
 * Solution Time: 2020-07-23 20:44:04
 * Solution Test Result: 182 / 182
 * Solution Status: Accepted
 * Solution Memory: 13.9 MB
 * Solution Runtime: 100 ms
 */

class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        static const int INF = 1 << 16;

        int i, j, k, n = amount, m = coins.size();
        std::vector<int> dp(n + 1, INF);

        dp[0] = 0;

        for (i = 1; i <= n; ++i)
        {
            for (j = 0; j < m; ++j)
            {
                k = coins[j];

                if (i >= k)
                    dp[i] = std::min(dp[i], dp[i - k] + 1);
            }
        }

        return dp[n] == INF ? -1 : dp[n];
    }
};
