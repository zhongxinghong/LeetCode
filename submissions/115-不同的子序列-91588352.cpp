/**
 * Submission ID: 91588352
 * Question ID: 115
 * Question Title: 不同的子序列
 * Question URL: https://leetcode-cn.com/problems/distinct-subsequences/
 * Solution Time: 2020-07-26 14:48:37
 * Solution Test Result: 63 / 63
 * Solution Status: Accepted
 * Solution Memory: 13.4 MB
 * Solution Runtime: 24 ms
 */

class Solution {
public:

    int numDistinct(string s, string t)
    {
        int n = s.size(), m = t.size(), i, j;
        std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(m + 1));

        for (i = 0, j = 0; i <= n; ++i)
            dp[i][j] = 1;

        for (i = 1; i <= n; ++i)
        {
            for (j = 1; j <= m; ++j)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][m];
    }
};
