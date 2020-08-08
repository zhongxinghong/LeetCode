/**
 * Submission ID: 91286965
 * Question ID: 139
 * Question Title: 单词拆分
 * Question URL: https://leetcode-cn.com/problems/word-break/
 * Solution Time: 2020-07-25 14:35:49
 * Solution Test Result: 36 / 36
 * Solution Status: Accepted
 * Solution Memory: 13.6 MB
 * Solution Runtime: 32 ms
 */

class Solution {
public:

    bool __wordBreak(
        const std::string &s,
        const std::unordered_set<std::string> &dict,
        std::vector<int> &f,
        int i)
    {
        if (f[i] != -1)
            return f[i];

        int j, n = s.size();

        if (i == n)
            return f[i] = true;

        for (j = i; j < n; ++j)
        {
            if (dict.find(s.substr(i, j - i + 1)) == dict.end())
                continue;

            if (__wordBreak(s, dict, f, j + 1))
                return f[i] = true;
        }

        return f[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict)
    {
        int i, n = s.size();
        std::vector<int> f(n + 1, -1);
        std::unordered_set<std::string> dict;

        for (i = 0; i < wordDict.size(); ++i)
            dict.insert(wordDict[i]);

        return __wordBreak(s, dict, f, 0);
    }
};
