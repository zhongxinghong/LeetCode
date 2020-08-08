/**
 * Submission ID: 91227983
 * Question ID: 81
 * Question Title: 搜索旋转排序数组 II
 * Question URL: https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/
 * Solution Time: 2020-07-25 10:16:55
 * Solution Test Result: 275 / 275
 * Solution Status: Accepted
 * Solution Memory: 6.5 MB
 * Solution Runtime: 8 ms
 */

class Solution {
public:
    bool search(vector<int>& nums, int target)
    {
        int n = nums.size(), st = 0, ed = n - 1, mid;

        while (st <= ed)
        {
            while (st + 1 <= ed && nums[st + 1] == nums[st])
                st++;

            while (ed - 1 >= st && nums[ed - 1] == nums[ed])
                ed--;

            mid = (st + ed) / 2;

            if (nums[mid] == target)
                return true;

            if (nums[mid] <= nums[ed])
            {
                if (nums[mid] < target && target <= nums[ed])
                    st = mid + 1;
                else
                    ed = mid - 1;
            }
            else
            {
                if (nums[mid] > target && target >= nums[st])
                    ed = mid - 1;
                else
                    st = mid + 1;
            }
        }

        return false;
    }
};
