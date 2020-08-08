/**
 * Submission ID: 90677072
 * Question ID: 100198
 * Question Title: 幂集
 * Question URL: https://leetcode-cn.com/problems/power-set-lcci/
 * Solution Time: 2020-07-23 14:05:47
 * Solution Test Result: 10 / 10
 * Solution Status: Accepted
 * Solution Memory: 7.2 MB
 * Solution Runtime: 0 ms
 */

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        int mask, i, j, n = nums.size(), d = 1 << n;
        std::vector<std::vector<int>> ret;
        std::vector<int> v(n);

        for (mask = 0; mask != d; ++mask)
        {
            v.clear();

            for (i = 0, j = 1; i != n; ++i, j <<= 1)
            {
                if (mask & j)
                    v.push_back(nums[i]);
            }

            ret.push_back(v);
        }

        return ret;
    }
};
