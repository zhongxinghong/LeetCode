/**
 * Submission ID: 91676561
 * Question ID: 1020
 * Question Title: 最长湍流子数组
 * Question URL: https://leetcode-cn.com/problems/longest-turbulent-subarray/
 * Solution Time: 2020-07-26 19:51:01
 * Solution Test Result: 86 / 86
 * Solution Status: Accepted
 * Solution Memory: 62.6 MB
 * Solution Runtime: 320 ms
 */

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A)
    {
        int i, n = A.size(), ret = 1;
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(2));

        dp[0][0] = dp[0][1] = 1;

        for (i = 1; i < n; ++i)
        {
            if (A[i] > A[i - 1])
            {
                dp[i][0] = 1;
                dp[i][1] = dp[i - 1][0] + 1;
            }
            else if (A[i] < A[i - 1])
            {
                dp[i][0] = dp[i - 1][1] + 1;
                dp[i][1] = 1;
            }
            else
            {
                dp[i][0] = 1;
                dp[i][1] = 1;
            }

            ret = std::max(ret, std::max(dp[i][0], dp[i][1]));
        }

        return ret;
    }
};
