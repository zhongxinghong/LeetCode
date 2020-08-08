/**
 * Submission ID: 90515810
 * Question ID: 53
 * Question Title: 最大子序和
 * Question URL: https://leetcode-cn.com/problems/maximum-subarray/
 * Solution Time: 2020-07-22 23:02:32
 * Solution Test Result: 202 / 202
 * Solution Status: Accepted
 * Solution Memory: 6.9 MB
 * Solution Runtime: 8 ms
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i, n = nums.size(), sum = 0, ret = INT_MIN;

        for (i = 0; i < n; ++i)
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
