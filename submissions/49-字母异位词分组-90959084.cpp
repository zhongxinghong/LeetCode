/**
 * Submission ID: 90959084
 * Question ID: 49
 * Question Title: 字母异位词分组
 * Question URL: https://leetcode-cn.com/problems/group-anagrams/
 * Solution Time: 2020-07-24 10:56:43
 * Solution Test Result: 101 / 101
 * Solution Status: Accepted
 * Solution Memory: 13.4 MB
 * Solution Runtime: 88 ms
 */

class Solution {
public:

    struct node_s
    {
        int ix;
        std::string s;

        bool operator<(const node_s &other) const
        {
            return s < other.s;
        }
    };

    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        int n = strs.size(), i, j;
        std::vector<node_s> v(n);
        std::vector<std::string> tmp;
        std::vector<std::vector<std::string>> ret;

        for (i = 0; i < n; ++i)
        {
            v[i].ix = i;
            v[i].s = strs[i];
            std::sort(v[i].s.begin(), v[i].s.end());
        }

        std::sort(v.begin(), v.end());

        ret.push_back(std::vector<std::string>());
        ret.back().push_back(strs[v[0].ix]);

        for (i = 1; i < n; ++i)
        {
            if (v[i - 1].s != v[i].s)
                ret.push_back(std::vector<std::string>());

            ret.back().push_back(strs[v[i].ix]);
        }

        return ret;
    }
};
