/**
 * Submission ID: 91057268
 * Question ID: 75
 * Question Title: 颜色分类
 * Question URL: https://leetcode-cn.com/problems/sort-colors/
 * Solution Time: 2020-07-24 16:02:47
 * Solution Test Result: 87 / 87
 * Solution Status: Accepted
 * Solution Memory: 8.5 MB
 * Solution Runtime: 8 ms
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(), p0 = 0, p2 = n - 1, i = 0;

        while (i <= p2)
        {
            if (nums[i] == 0)
                std::swap(nums[p0++], nums[i++]);
            else if (nums[i] == 2)
                std::swap(nums[p2--], nums[i]);
            else
                i++;
        }
    }
};
