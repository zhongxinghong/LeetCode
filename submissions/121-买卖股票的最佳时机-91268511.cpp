/**
 * Submission ID: 91268511
 * Question ID: 121
 * Question Title: 买卖股票的最佳时机
 * Question URL: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
 * Solution Time: 2020-07-25 12:47:55
 * Solution Test Result: 200 / 200
 * Solution Status: Accepted
 * Solution Memory: 12.7 MB
 * Solution Runtime: 12 ms
 */

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int i, n = prices.size(), minp, maxp = 0;

        if (n <= 1)
            return maxp;

        minp = prices[0];

        for (i = 1; i < n; ++i)
        {
            maxp = std::max(maxp, prices[i] - minp);
            minp = std::min(minp, prices[i]);
        }

        return maxp;
    }
};
