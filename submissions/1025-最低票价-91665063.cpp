/**
 * Submission ID: 91665063
 * Question ID: 1025
 * Question Title: 最低票价
 * Question URL: https://leetcode-cn.com/problems/minimum-cost-for-tickets/
 * Solution Time: 2020-07-26 18:48:54
 * Solution Test Result: 66 / 66
 * Solution Status: Accepted
 * Solution Memory: 9.5 MB
 * Solution Runtime: 4 ms
 */

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        static const int INF = 1 << 30;
        static const int valid[3] = {1, 7, 30};

        int i, j, m = days.size(), n = days.back();
        std::vector<int> dp(n + 1, -1);

        dp[0] = 0;

        for (i = 0; i < m; ++i)
            dp[days[i]] = INF;

        for (i = 1; i <= n; ++i)
        {
            if (dp[i] == -1)
                dp[i] = dp[i - 1];
            else
            {
                for (j = 0; j < 3; ++j)
                {
                    dp[i] = std::min(dp[i], dp[std::max(0, i - valid[j])] + costs[j]);
                }
            }
        }

        return dp[n];
    }
};
