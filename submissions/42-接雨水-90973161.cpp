/**
 * Submission ID: 90973161
 * Question ID: 42
 * Question Title: 接雨水
 * Question URL: https://leetcode-cn.com/problems/trapping-rain-water/
 * Solution Time: 2020-07-24 11:27:52
 * Solution Test Result: 315 / 315
 * Solution Status: Accepted
 * Solution Memory: 7.2 MB
 * Solution Runtime: 8 ms
 */

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty())
            return 0;

        int n = height.size(), i, ret = 0;
        std::vector<int> lmax(n), rmax(n);

        lmax[0] = height[0];

        for (i = 1; i < n; ++i)
            lmax[i] = std::max(lmax[i - 1], height[i]);

        rmax[n - 1] = height[n - 1];

        for (i = n - 2; i > -1; --i)
            rmax[i] = std::max(rmax[i + 1], height[i]);

        for (i = 1; i < n - 1; ++i)
            ret += std::min(lmax[i], rmax[i]) - height[i];

        return ret;
    }
};
