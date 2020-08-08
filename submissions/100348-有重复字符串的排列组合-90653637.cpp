/**
 * Submission ID: 90653637
 * Question ID: 100348
 * Question Title: 有重复字符串的排列组合
 * Question URL: https://leetcode-cn.com/problems/permutation-ii-lcci/
 * Solution Time: 2020-07-23 12:34:14
 * Solution Test Result: 29 / 29
 * Solution Status: Accepted
 * Solution Memory: 6.9 MB
 * Solution Runtime: 4 ms
 */

class Solution {
public:

    void dfs(
        const std::string &S,
        std::unordered_map<char, int> &cnt,
        std::vector<std::string> &ret,
        std::string &tmp,
        int ix)
    {
        int i, n = S.size();

        if (ix == n)
        {
            ret.push_back(tmp);
            return;
        }

        for (auto it = cnt.begin(); it != cnt.end(); ++it)
        {
            if (it->second == 0)
                continue;

            it->second--;
            tmp[ix] = it->first;

            dfs(S, cnt, ret, tmp, ix + 1);

            it->second++;
        }
    }

    vector<string> permutation(string S)
    {
        int i, n = S.size();
        std::vector<std::string> ret;
        std::unordered_map<char, int> cnt;
        std::string tmp(n, 0);

        for (i = 0; i < n; ++i)
            cnt[S[i]]++;

        dfs(S, cnt, ret, tmp, 0);

        return ret;
    }
};
