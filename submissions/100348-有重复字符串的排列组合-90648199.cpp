/**
 * Submission ID: 90648199
 * Question ID: 100348
 * Question Title: 有重复字符串的排列组合
 * Question URL: https://leetcode-cn.com/problems/permutation-ii-lcci/
 * Solution Time: 2020-07-23 12:15:25
 * Solution Test Result: 29 / 29
 * Solution Status: Accepted
 * Solution Memory: 39.4 MB
 * Solution Runtime: 1036 ms
 */

class Solution {
public:

    void dfs(
        const std::string &S,
        std::vector<std::string> &ret,
        std::string &tmp,
        std::vector<bool> &used)
    {
        if (tmp.size() == S.size())
        {
            ret.push_back(tmp);
            return;
        }

        int i, n = S.size();

        for (i = 0; i < n; ++i)
        {
            if (used[i])
                continue;

            used[i] = true;
            tmp.push_back(S[i]);
            dfs(S, ret, tmp, used);
            tmp.pop_back();
            used[i] = false;
        }
    }

    vector<string> permutation(string S)
    {
        std::sort(S.begin(), S.end());
        std::vector<std::string> ret;
        std::string tmp;
        std::vector<bool> used(S.size(), false);

        dfs(S, ret, tmp, used);

        std::sort(ret.begin(), ret.end());
        ret.erase(std::unique(ret.begin(), ret.end()), ret.end());

        return ret;
    }
};
