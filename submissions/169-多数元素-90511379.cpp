/**
 * Submission ID: 90511379
 * Question ID: 169
 * Question Title: 多数元素
 * Question URL: https://leetcode-cn.com/problems/majority-element/
 * Solution Time: 2020-07-22 22:52:27
 * Solution Test Result: 46 / 46
 * Solution Status: Accepted
 * Solution Memory: 8.7 MB
 * Solution Runtime: 20 ms
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i, n = nums.size(), x = nums[0], cnt = 1;
        for (i = 1; i < n; ++i)
        {
            if (nums[i] == x)
                cnt++;
            else
                cnt--;

            if (cnt == -1)
            {
                x = nums[i];
                cnt = 1;
            }
        }
        return x;
    }
};
