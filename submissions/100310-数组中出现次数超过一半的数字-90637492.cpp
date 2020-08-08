/**
 * Submission ID: 90637492
 * Question ID: 100310
 * Question Title: 数组中出现次数超过一半的数字
 * Question URL: https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/
 * Solution Time: 2020-07-23 11:36:30
 * Solution Test Result: 45 / 45
 * Solution Status: Accepted
 * Solution Memory: 18.6 MB
 * Solution Runtime: 48 ms
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
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

        return cur;
    }
};
