/**
 * Submission ID: 90017168
 * Question ID: 1000040
 * Question Title: 变位词组
 * Question URL: https://leetcode-cn.com/problems/group-anagrams-lcci/
 * Solution Time: 2020-07-21 16:34:44
 * Solution Test Result: 101 / 101
 * Solution Status: Accepted
 * Solution Memory: 15.6 MB
 * Solution Runtime: 112 ms
 */

class Solution {
public:

    struct node_s
    {
        std::string s;
        int ix;

        bool operator<(const node_s &nd) const
        {
            return s != nd.s ? s < nd.s : ix < nd.ix;
        }
    };

    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        int i, n = strs.size();
        std::vector<node_s> v(n);
        std::vector<std::vector<std::string>> ret;

        if (n == 0)
            return ret;

        std::sort(strs.begin(), strs.end());

        for (i = 0; i < n; ++i)
        {
            v[i] = {strs[i], i};
            std::sort(v[i].s.begin(), v[i].s.end());
        }

        std::sort(v.begin(), v.end());

        ret.push_back({strs[v[0].ix]});

        for (i = 1; i < n; ++i)
        {
            if (v[i].s == v[i - 1].s)
                ret.back().push_back(strs[v[i].ix]);
            else
                ret.push_back({strs[v[i].ix]});
        }

        return ret;
    }
};
