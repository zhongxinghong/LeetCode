/**
 * Submission ID: 87476204
 * Question ID: 34
 * Question Title: 在排序数组中查找元素的第一个和最后一个位置
 * Question URL: https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 * Solution Time: 2020-07-13 20:30:48
 * Solution Test Result: 88 / 88
 * Solution Status: Accepted
 * Solution Memory: 13.8 MB
 * Solution Runtime: 24 ms
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size(), st = 0, ed = n - 1, mid;
        bool found = false;
        std::vector<int> ret(2, -1);

        while (st <= ed)
        {
            mid = (st + ed) / 2;

            if (nums[mid] < target)
            {
                st = mid + 1;
            }
            else if (nums[mid] > target)
            {
                ed = mid - 1;
            }
            else
            {
                found = true;
                break;
            }
        }

        if (!found)
            return ret;

        for (st = mid; st > 0; --st)
        {
            if (nums[st - 1] != target)
                break;
        }

        for (ed = mid; ed < n - 1; ++ed)
        {
            if (nums[ed + 1] != target)
                break;
        }

        ret[0] = st;
        ret[1] = ed;

        return ret;
    }
};
