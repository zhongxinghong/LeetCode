/**
 * Submission ID: 90508373
 * Question ID: 215
 * Question Title: 数组中的第K个最大元素
 * Question URL: https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
 * Solution Time: 2020-07-22 22:44:10
 * Solution Test Result: 32 / 32
 * Solution Status: Accepted
 * Solution Memory: 9.8 MB
 * Solution Runtime: 56 ms
 */

class Solution {
public:

    int __findKthLargest(std::vector<int> &nums, int st, int ed, int k)
    {
        if (st > ed)
            return -1;

        int i = st, j = ed, p = nums[st];

        while (i < j)
        {
            while (i < j && nums[j] < p)
                j--;

            if (i < j)
                nums[i++] = nums[j];

            while (i < j && nums[i] >= p)
                i++;

            if (i < j)
                nums[j--] = nums[i];
        }

        nums[i] = p;

        if (i == k - 1)
            return p;
        else if (i < k - 1)
            return __findKthLargest(nums, i + 1, ed, k);
        else
            return __findKthLargest(nums, st, i - 1, k);
    }

    int findKthLargest(vector<int>& nums, int k) {
        return __findKthLargest(nums, 0, nums.size() - 1, k);
    }
};
