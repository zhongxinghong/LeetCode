/**
 * Submission ID: 87449866
 * Question ID: 31
 * Question Title: 下一个排列
 * Question URL: https://leetcode-cn.com/problems/next-permutation/
 * Solution Time: 2020-07-13 18:56:15
 * Solution Test Result: 265 / 265
 * Solution Status: Accepted
 * Solution Memory: 12.3 MB
 * Solution Runtime: 16 ms
 */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty())
            return;

        int i, j, n = nums.size();

        for (i = n - 1; i > 0; --i)
        {
            if (nums[i - 1] < nums[i])
                break;
        }

        if (i == 0)
        {
            std::reverse(nums.begin(), nums.end());
            return;
        }

        for (j = n - 1; ; --j)
        {
            if (nums[j] > nums[i - 1])
                break;
        }

        std::swap(nums[i - 1], nums[j]);
        std::reverse(nums.begin() + i, nums.end());
    }
};
