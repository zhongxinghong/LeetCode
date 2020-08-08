/**
 * Submission ID: 90983534
 * Question ID: 55
 * Question Title: 跳跃游戏
 * Question URL: https://leetcode-cn.com/problems/jump-game/
 * Solution Time: 2020-07-24 11:51:50
 * Solution Test Result: 75 / 75
 * Solution Status: Accepted
 * Solution Memory: 12.9 MB
 * Solution Runtime: 24 ms
 */

class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int n = nums.size(), i, j;
        std::vector<bool> dp(n, false);

        dp[n - 1] = true;

        for (i = n - 2; i > -1; --i)
        {
            if (nums[i] == 0)
                continue;

            if (nums[i] <= nums[i + 1] + 1 || dp[i + 1])
            {
                dp[i] = dp[i + 1];
                continue;
            }

            for (j = nums[i + 1] + 2; j <= nums[i]; ++j)
            {
                if (i + j > n - 1)
                    continue;

                if (dp[i + j])
                {
                    dp[i] = dp[i + j];
                    break;
                }
            }
        }

        return dp[0];
    }
};
