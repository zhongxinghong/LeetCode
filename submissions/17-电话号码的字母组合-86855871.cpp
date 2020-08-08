/**
 * Submission ID: 86855871
 * Question ID: 17
 * Question Title: 电话号码的字母组合
 * Question URL: https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
 * Solution Time: 2020-07-11 20:12:45
 * Solution Test Result: 25 / 25
 * Solution Status: Accepted
 * Solution Memory: 6.8 MB
 * Solution Runtime: 0 ms
 */

class Solution {
public:

    std::vector<std::string> i2a = {
        "",
        "",     "abc", "def",
        "ghi",  "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    void dfs_build(
        std::vector<std::string> &ret,
        const std::string &digits,
        std::string tmp,
        size_t dep)
    {
        const std::string &s = i2a[digits[dep] - '0'];
        for (size_t i = 0; i < s.size(); ++i)
        {
            tmp[dep] = s[i];
            if (dep + 1 == digits.size())
                ret.push_back(tmp);
            else
                dfs_build(ret, digits, tmp, dep + 1);
        }
    }

    vector<string> letterCombinations(string digits) {

        std::vector<std::string> ret;
        std::string tmp(digits.size(), '\x00');

        if (digits.empty())
            return ret;

        dfs_build(ret, digits, tmp, 0);

        return ret;
    }
};
