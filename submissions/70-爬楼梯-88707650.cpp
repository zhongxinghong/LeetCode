/**
 * Submission ID: 88707650
 * Question ID: 70
 * Question Title: 爬楼梯
 * Question URL: https://leetcode-cn.com/problems/climbing-stairs/
 * Solution Time: 2020-07-17 16:27:29
 * Solution Test Result: 45 / 45
 * Solution Status: Accepted
 * Solution Memory: 6.4 MB
 * Solution Runtime: 0 ms
 */

class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; ++i)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }
};
