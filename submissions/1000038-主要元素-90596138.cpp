/**
 * Submission ID: 90596138
 * Question ID: 1000038
 * Question Title: 主要元素
 * Question URL: https://leetcode-cn.com/problems/find-majority-element-lcci/
 * Solution Time: 2020-07-23 10:03:38
 * Solution Test Result: 44 / 44
 * Solution Status: Accepted
 * Solution Memory: 18.9 MB
 * Solution Runtime: 36 ms
 */

class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        if (nums.empty())
            return -1;

        int i, n = nums.size(), cur = nums[0], cnt = 1;

        for (i = 1; i < n; ++i)
        {
            if (cur == nums[i])
                cnt++;
            else
                cnt--;

            if (cnt == -1)
            {
                cur = nums[i];
                cnt = 1;
            }
        }

        return cnt != 0 ? cur : -1;
    }
};
