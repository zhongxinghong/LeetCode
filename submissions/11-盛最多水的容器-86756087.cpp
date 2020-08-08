/**
 * Submission ID: 86756087
 * Question ID: 11
 * Question Title: 盛最多水的容器
 * Question URL: https://leetcode-cn.com/problems/container-with-most-water/
 * Solution Time: 2020-07-11 14:04:14
 * Solution Test Result: 50 / 50
 * Solution Status: Accepted
 * Solution Memory: 7.5 MB
 * Solution Runtime: 20 ms
 */

class Solution {
public:

    int max(int i, int j)
    {
        return i > j ? i : j;
    }

    int min(int i, int j)
    {
        return i < j ? i : j;
    }

    int maxArea(vector<int>& height) {
        size_t i = 0, j = height.size() - 1;
        int ret = 0;

        while (i < j)
        {
            ret = max(ret, (j - i) * min(height[i], height[j]));

            if (height[i] < height[j])
                ++i;
            else
                --j;
        }

        return ret;
    }
};
