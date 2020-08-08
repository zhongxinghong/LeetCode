/**
 * Submission ID: 91267979
 * Question ID: 121
 * Question Title: 买卖股票的最佳时机
 * Question URL: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
 * Solution Time: 2020-07-25 12:44:01
 * Solution Test Result: 200 / 200
 * Solution Status: Accepted
 * Solution Memory: 13.2 MB
 * Solution Runtime: 12 ms
 */

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int i, n = prices.size(), ret = 0;
        std::vector<int> lmin(n), rmax(n);

        if (n == 0)
            return ret;

        lmin[0] = prices[0];

        for (i = 1; i < n; ++i)
            lmin[i] = std::min(lmin[i - 1], prices[i]);

        rmax[n - 1] = prices[n - 1];

        for (i = n - 2; i > -1; --i)
            rmax[i] = std::max(rmax[i + 1], prices[i]);

        for (i = 0; i < n - 1; ++i)
            ret = std::max(ret, rmax[i + 1] - lmin[i]);

        return ret;
    }
};
