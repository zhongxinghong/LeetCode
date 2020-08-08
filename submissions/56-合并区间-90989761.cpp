/**
 * Submission ID: 90989761
 * Question ID: 56
 * Question Title: 合并区间
 * Question URL: https://leetcode-cn.com/problems/merge-intervals/
 * Solution Time: 2020-07-24 12:10:51
 * Solution Test Result: 169 / 169
 * Solution Status: Accepted
 * Solution Memory: 10.7 MB
 * Solution Runtime: 56 ms
 */

class Solution {
public:

    struct range_s
    {
        int st;
        int ed;

        bool operator>(const range_s &other) const
        {
            return st > other.st;
        }
    };

    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        int i, n = intervals.size();
        std::vector<std::vector<int>> ret;
        std::priority_queue<range_s, std::vector<range_s>, std::greater<range_s>> pq;
        range_s r;

        for (i = 0; i < n; ++i)
            pq.push({intervals[i][0], intervals[i][1]});

        while (!pq.empty())
        {
            r = pq.top();
            pq.pop();

            if (pq.empty() || pq.top().st > r.ed)
            {
                ret.push_back({r.st, r.ed});
            }
            else
            {
                r.ed = std::max(r.ed, pq.top().ed);
                pq.pop();
                pq.push(r);
            }
        }

        return ret;
    }
};
