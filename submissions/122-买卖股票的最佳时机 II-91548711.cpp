/**
 * Submission ID: 91548711
 * Question ID: 122
 * Question Title: 买卖股票的最佳时机 II
 * Question URL: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
 * Solution Time: 2020-07-26 12:00:28
 * Solution Test Result: 200 / 200
 * Solution Status: Accepted
 * Solution Memory: 7.2 MB
 * Solution Runtime: 8 ms
 */

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int i, n = prices.size(), ret = 0;
        for (i = 1; i < n; ++i)
        {
            if (prices[i] > prices[i - 1])
                ret += prices[i] - prices[i - 1];
        }
        return ret;
    }
};
