/**
 * Submission ID: 88973749
 * Question ID: 757
 * Question Title: 金字塔转换矩阵
 * Question URL: https://leetcode-cn.com/problems/pyramid-transition-matrix/
 * Solution Time: 2020-07-18 13:53:22
 * Solution Test Result: 65 / 65
 * Solution Status: Accepted
 * Solution Memory: 8.6 MB
 * Solution Runtime: 16 ms
 */

class Solution {
public:

    struct rule_cmp_s
    {
        bool operator()(const std::string &s1, const std::string &s2)
        {
            size_t i, n = std::min(s1.size(), s2.size());
            for (i = 0; i < n; ++i)
            {
                if (s1[i] != s2[i])
                    return s1[i] < s2[i];
            }
            return false;
        }
    };

    bool dfs_build(const std::set<std::string> &rules, std::string &bottom, std::string &top)
    {
        static const rule_cmp_s rule_cmp;

        if (bottom.size() == 1)
            return true;

        if (top.size() == bottom.size() - 1)
        {
            std::string bottom2 = top, top2;
            return dfs_build(rules, bottom2, top2);
        }

        std::string s = bottom.substr(top.size(), 2);

        auto range = std::equal_range(rules.begin(), rules.end(), s, rule_cmp);

        if (range.first == range.second)
            return false;

        for (auto it = range.first; it != range.second; ++it)
        {
            top.push_back((*it)[2]);
            if (dfs_build(rules, bottom, top))
                return true;
            top.pop_back();
        }

        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed)
    {
        std::set<std::string> rules(allowed.begin(), allowed.end());
        std::string top;
        return dfs_build(rules, bottom, top);
    }
};
