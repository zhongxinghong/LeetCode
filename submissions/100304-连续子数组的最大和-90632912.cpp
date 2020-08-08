/**
 * Submission ID: 90632912
 * Question ID: 100304
 * Question Title: 连续子数组的最大和
 * Question URL: https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
 * Solution Time: 2020-07-23 11:25:43
 * Solution Test Result: 202 / 202
 * Solution Status: Accepted
 * Solution Memory: 22.9 MB
 * Solution Runtime: 52 ms
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i, n = nums.size(), sum = nums[0], ret = sum;

        for (i = 1; i < n; ++i)
        {
            if (sum > 0)
                sum += nums[i];
            else
                sum = nums[i];

            ret = std::max(ret, sum);
        }

        return ret;
    }
};
