/**
 * Submission ID: 91285072
 * Question ID: 136
 * Question Title: 只出现一次的数字
 * Question URL: https://leetcode-cn.com/problems/single-number/
 * Solution Time: 2020-07-25 14:27:21
 * Solution Test Result: 16 / 16
 * Solution Status: Accepted
 * Solution Memory: 11.8 MB
 * Solution Runtime: 20 ms
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i, n = nums.size(), x = 0;
        for (i = 0; i < n; ++i)
            x ^= nums[i];
        return x;
    }
};
