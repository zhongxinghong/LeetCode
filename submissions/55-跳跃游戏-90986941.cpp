/**
 * Submission ID: 90986941
 * Question ID: 55
 * Question Title: 跳跃游戏
 * Question URL: https://leetcode-cn.com/problems/jump-game/
 * Solution Time: 2020-07-24 11:57:46
 * Solution Test Result: 75 / 75
 * Solution Status: Accepted
 * Solution Memory: 12.8 MB
 * Solution Runtime: 20 ms
 */

class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int n = nums.size(), i;

        if (nums[0] == 0 && n > 1)
            return false;

        for (i = 1; i < n - 1; ++i)
        {
            nums[i] = std::max(nums[i - 1], nums[i] + i);
            if (nums[i] < i + 1)
                return false;
        }

        return true;
    }
};
