/**
 * Submission ID: 87444031
 * Question ID: 27
 * Question Title: 移除元素
 * Question URL: https://leetcode-cn.com/problems/remove-element/
 * Solution Time: 2020-07-13 18:25:04
 * Solution Test Result: 113 / 113
 * Solution Status: Accepted
 * Solution Memory: 6.3 MB
 * Solution Runtime: 0 ms
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty())
            return 0;

        int m = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != val)
            {
                nums[m++] = nums[i];
            }
        }

        return m;
    }
};
