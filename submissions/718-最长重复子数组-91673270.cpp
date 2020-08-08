/**
 * Submission ID: 91673270
 * Question ID: 718
 * Question Title: 最长重复子数组
 * Question URL: https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/
 * Solution Time: 2020-07-26 19:33:23
 * Solution Test Result: 54 / 54
 * Solution Status: Accepted
 * Solution Memory: 109.2 MB
 * Solution Runtime: 448 ms
 */

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B)
    {
        int n = A.size(), m = B.size(), i, j, ret = 0;
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

        for (i = 1; i <= n; ++i)
        {
            for (j = 1; j <= m; ++j)
            {
                if (A[i - 1] == B[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;

                ret = std::max(ret, dp[i][j]);
            }
        }

        return ret;
    }
};
