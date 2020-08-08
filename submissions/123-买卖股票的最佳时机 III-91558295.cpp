/**
 * Submission ID: 91558295
 * Question ID: 123
 * Question Title: 买卖股票的最佳时机 III
 * Question URL: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/
 * Solution Time: 2020-07-26 12:14:33
 * Solution Test Result: 200 / 200
 * Solution Status: Accepted
 * Solution Memory: 15.6 MB
 * Solution Runtime: 32 ms
 */

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        static const int INF = 1 << 30;

        if (prices.empty())
            return 0;

        int i, n = prices.size(), ret;
        std::vector<std::vector<int>> dp(n, std::vector<int>(5));

        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = -INF;
        dp[0][3] = -INF;
        dp[0][4] = -INF;

        for (i = 1; i < n; ++i)
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = std::max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = std::max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = std::max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }

        ret = dp[n - 1][0];
        ret = std::max(ret, dp[n - 1][2]);
        ret = std::max(ret, dp[n - 1][4]);

        return ret;
    }
};
