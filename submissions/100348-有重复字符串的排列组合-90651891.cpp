/**
 * Submission ID: 90651891
 * Question ID: 100348
 * Question Title: 有重复字符串的排列组合
 * Question URL: https://leetcode-cn.com/problems/permutation-ii-lcci/
 * Solution Time: 2020-07-23 12:22:32
 * Solution Test Result: 29 / 29
 * Solution Status: Accepted
 * Solution Memory: 7.2 MB
 * Solution Runtime: 420 ms
 */

class Solution {
public:

    void dfs(
        const std::string &S,
        std::set<std::string> &ret,
        std::vector<int> &used,
        int ix)
    {
        int i, n = S.size();

        if (ix == n)
        {
            std::string tmp(n, 0);
            for (i = 0; i < n; ++i)
                tmp[used[i]] = S[i];
            ret.insert(tmp);
            return;
        }

        for (i = 0; i < n; ++i)
        {
            if (used[i] != -1)
                continue;

            used[i] = ix;
            dfs(S, ret, used, ix + 1);
            used[i] = -1;
        }
    }

    vector<string> permutation(string S)
    {
        std::set<std::string> ret;
        std::vector<int> used(S.size(), -1);

        dfs(S, ret, used, 0);

        return std::vector<std::string>(ret.begin(), ret.end());
    }
};
