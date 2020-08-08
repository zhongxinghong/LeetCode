/**
 * Submission ID: 87399269
 * Question ID: 792
 * Question Title: 二分查找
 * Question URL: https://leetcode-cn.com/problems/binary-search/
 * Solution Time: 2020-07-13 16:19:18
 * Solution Test Result: 46 / 46
 * Solution Status: Accepted
 * Solution Memory: 25.8 MB
 * Solution Runtime: 92 ms
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), i = 0, j = n - 1, mid;
        while (i <= j)
        {
            mid = (i + j) / 2;
            if (nums[mid] < target)
            {
                i = mid + 1;
            }
            else if (nums[mid] > target)
            {
                j = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};
