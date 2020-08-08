/**
 * Submission ID: 91005321
 * Question ID: 62
 * Question Title: 不同路径
 * Question URL: https://leetcode-cn.com/problems/unique-paths/
 * Solution Time: 2020-07-24 13:44:06
 * Solution Test Result: 62 / 62
 * Solution Status: Accepted
 * Solution Memory: 6 MB
 * Solution Runtime: 0 ms
 */

class Solution {
public:
    int uniquePaths(int m, int n)
    {
        int i;
        std::vector<int> dp(n);

        for (i = 0; i < n; ++i)
            dp[i] = 1;

        while (--m)
        {
            for (i = 1; i < n; ++i)
                dp[i] += dp[i - 1];
        }

        return dp[n - 1];
    }
};
