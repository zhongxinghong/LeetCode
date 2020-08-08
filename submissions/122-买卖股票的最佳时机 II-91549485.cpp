/**
 * Submission ID: 91549485
 * Question ID: 122
 * Question Title: 买卖股票的最佳时机 II
 * Question URL: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
 * Solution Time: 2020-07-26 12:03:22
 * Solution Test Result: 200 / 200
 * Solution Status: Accepted
 * Solution Memory: 9.5 MB
 * Solution Runtime: 20 ms
 */

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.empty())
            return 0;

        int i, n = prices.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(2, 0));

        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (i = 1; i < n; ++i)
        {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        return dp[n - 1][0];
    }
};
