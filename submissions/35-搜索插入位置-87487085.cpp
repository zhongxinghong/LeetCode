/**
 * Submission ID: 87487085
 * Question ID: 35
 * Question Title: 搜索插入位置
 * Question URL: https://leetcode-cn.com/problems/search-insert-position/
 * Solution Time: 2020-07-13 20:59:00
 * Solution Test Result: 62 / 62
 * Solution Status: Accepted
 * Solution Memory: 6.7 MB
 * Solution Runtime: 4 ms
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size(), i = 0, j = n - 1, mid;

        while (i <= j)
        {
            mid = (i + j) / 2;
            if (nums[mid] < target)
                i = mid + 1;
            else if (nums[mid] > target)
                j = mid - 1;
            else
                return mid;
        }

        return i;
    }
};
