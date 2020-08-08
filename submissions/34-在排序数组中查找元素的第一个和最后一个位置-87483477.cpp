/**
 * Submission ID: 87483477
 * Question ID: 34
 * Question Title: 在排序数组中查找元素的第一个和最后一个位置
 * Question URL: https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 * Solution Time: 2020-07-13 20:48:19
 * Solution Test Result: 88 / 88
 * Solution Status: Accepted
 * Solution Memory: 13.7 MB
 * Solution Runtime: 36 ms
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size(), st = 0, ed = n - 1, mid;
        bool found = false;
        std::vector<int> ret(2, -1);

        if (nums.empty())
            return ret;

        while (st < ed)
        {
            mid = st + (ed - st) / 2;
            if (nums[mid] >= target)
                ed = mid;
            else
                st = mid + 1;
        }

        if (nums[st] != target)
            return ret;

        ret[0] = st;
        ed = n;

        while (st < ed)
        {
            mid = st + (ed - st) / 2;
            if (nums[mid] == target)
                st = mid + 1;
            else
                ed = mid;
        }

        ret[1] = st - 1;

        return ret;
    }
};
