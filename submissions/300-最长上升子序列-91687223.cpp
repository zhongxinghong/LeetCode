/**
 * Submission ID: 91687223
 * Question ID: 300
 * Question Title: 最长上升子序列
 * Question URL: https://leetcode-cn.com/problems/longest-increasing-subsequence/
 * Solution Time: 2020-07-26 20:34:25
 * Solution Test Result: 24 / 24
 * Solution Status: Accepted
 * Solution Memory: 7.6 MB
 * Solution Runtime: 100 ms
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        if (nums.empty())
            return 0;

        int i, j, n = nums.size(), ret = 1;
        std::vector<int> dp(n + 1, 1);

        dp[0] = 1;

        for (i = 1; i < n; ++i)
        {
            for (j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                    dp[i] = std::max(dp[i], dp[j] + 1);
            }

            ret = std::max(ret, dp[i]);
        }

        return ret;
    }
};
