/**
 * Submission ID: 87472944
 * Question ID: 33
 * Question Title: 搜索旋转排序数组
 * Question URL: https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
 * Solution Time: 2020-07-13 20:21:05
 * Solution Test Result: 196 / 196
 * Solution Status: Accepted
 * Solution Memory: 6.4 MB
 * Solution Runtime: 0 ms
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), st = 0, ed = n - 1, mid;

        while (st <= ed)
        {
            mid = (st + ed) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[mid] < nums[ed])
            {
                if (nums[mid] < target && target <= nums[ed])
                    st = mid + 1;
                else
                    ed = mid - 1;
            }
            else
            {
                if (nums[st] <= target && target < nums[mid])
                    ed = mid - 1;
                else
                    st = mid + 1;
            }
        }

        return -1;
    }
};
