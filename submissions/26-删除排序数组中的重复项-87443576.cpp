/**
 * Submission ID: 87443576
 * Question ID: 26
 * Question Title: 删除排序数组中的重复项
 * Question URL: https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
 * Solution Time: 2020-07-13 18:22:41
 * Solution Test Result: 161 / 161
 * Solution Status: Accepted
 * Solution Memory: 7.5 MB
 * Solution Runtime: 20 ms
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        int m = 1;

        for (size_t i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > nums[m - 1])
            {
                nums[m++] = nums[i];
            }
        }

        return m;
    }
};
