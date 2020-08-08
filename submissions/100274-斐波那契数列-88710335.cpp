/**
 * Submission ID: 88710335
 * Question ID: 100274
 * Question Title: 斐波那契数列
 * Question URL: https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/
 * Solution Time: 2020-07-17 16:34:03
 * Solution Test Result: 51 / 51
 * Solution Status: Accepted
 * Solution Memory: 6.4 MB
 * Solution Runtime: 4 ms
 */

class Solution {
public:
    int fib(int n) {
        static int M = 1e9 + 7;

        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        std::vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i)
            dp[i] = (dp[i - 1] + dp[i - 2]) % M;

        return dp[n];
    }
};
