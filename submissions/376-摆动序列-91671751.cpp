/**
 * Submission ID: 91671751
 * Question ID: 376
 * Question Title: 摆动序列
 * Question URL: https://leetcode-cn.com/problems/wiggle-subsequence/
 * Solution Time: 2020-07-26 19:25:30
 * Solution Test Result: 27 / 27
 * Solution Status: Accepted
 * Solution Memory: 7.8 MB
 * Solution Runtime: 4 ms
 */

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums)
    {
        if (nums.empty())
            return 0;

        int i, n = nums.size(), ret = 1;
        std::vector<std::vector<int>> dp(n, std::vector<int>(2));

        dp[0][0] = dp[0][1] = 1;

        for (i = 1; i < n; ++i)
        {
            if (nums[i] > nums[i - 1])
            {
                dp[i][0] = dp[i - 1][1] + 1;
                dp[i][1] = dp[i - 1][1];
            }
            else if (nums[i] < nums[i - 1])
            {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 1][0] + 1;
            }
            else
            {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 1][1];
            }

            ret = std::max(ret, std::max(dp[i][0], dp[i][1]));
        }

        return ret;
    }
};
