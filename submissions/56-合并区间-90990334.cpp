/**
 * Submission ID: 90990334
 * Question ID: 56
 * Question Title: 合并区间
 * Question URL: https://leetcode-cn.com/problems/merge-intervals/
 * Solution Time: 2020-07-24 12:14:14
 * Solution Test Result: 169 / 169
 * Solution Status: Accepted
 * Solution Memory: 10.4 MB
 * Solution Runtime: 44 ms
 */

class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        int i, n = intervals.size();
        std::vector<std::vector<int>> ret;
        std::vector<int> cur;

        if (n == 0)
            return ret;

        std::sort(intervals.begin(), intervals.end());

        cur = intervals[0];

        for (i = 1; i < n; ++i)
        {
            if (intervals[i][0] > cur[1])
            {
                ret.push_back(cur);
                cur = intervals[i];
            }
            else
            {
                cur[1] = std::max(cur[1], intervals[i][1]);
            }
        }

        ret.push_back(cur);

        return ret;
    }
};
