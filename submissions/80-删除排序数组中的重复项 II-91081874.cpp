/**
 * Submission ID: 91081874
 * Question ID: 80
 * Question Title: 删除排序数组中的重复项 II
 * Question URL: https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/
 * Solution Time: 2020-07-24 16:56:12
 * Solution Test Result: 166 / 166
 * Solution Status: Accepted
 * Solution Memory: 6.8 MB
 * Solution Runtime: 16 ms
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.empty())
            return 0;

        int n = nums.size(), i, m = 1, cur = nums[0], cnt = 1;

        for (i = 1; i < n; ++i)
        {
            if (nums[i] == cur)
            {
                if (cnt++ < 2)
                    nums[m++] = nums[i];
            }
            else
            {
                cur = nums[i];
                cnt = 1;
                nums[m++] = nums[i];
            }
        }

        return m;
    }
};
