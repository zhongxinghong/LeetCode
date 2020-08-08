/**
 * Submission ID: 90628646
 * Question ID: 218
 * Question Title: 天际线问题
 * Question URL: https://leetcode-cn.com/problems/the-skyline-problem/
 * Solution Time: 2020-07-23 11:16:08
 * Solution Test Result: 36 / 36
 * Solution Status: Accepted
 * Solution Memory: 13 MB
 * Solution Runtime: 56 ms
 */

class Solution {
public:

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
    {
        int i, cur, prev;
        std::multiset<int> ms;
        std::vector<std::pair<int, int>> v;
        std::vector<std::vector<int>> ret;

        for (i = 0; i < buildings.size(); ++i)
        {
            v.push_back({buildings[i][0], -buildings[i][2]});
            v.push_back({buildings[i][1], buildings[i][2]});
        }

        std::sort(v.begin(), v.end());

        prev = 0;
        ms.insert(prev);

        for (i = 0; i < v.size(); ++i)
        {
            if (v[i].second < 0)
                ms.insert(-v[i].second);
            else
                ms.erase(ms.find(v[i].second));

            cur = *ms.rbegin();

            if (cur != prev)
            {
                ret.push_back({v[i].first, cur});
                prev = cur;
            }
        }

        return ret;
    }
};
