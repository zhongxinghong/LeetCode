/**
 * Submission ID: 86866840
 * Question ID: 22
 * Question Title: 括号生成
 * Question URL: https://leetcode-cn.com/problems/generate-parentheses/
 * Solution Time: 2020-07-11 21:00:35
 * Solution Test Result: 8 / 8
 * Solution Status: Accepted
 * Solution Memory: 7.1 MB
 * Solution Runtime: 4 ms
 */

class Solution {
public:

    void dfs_build(std::vector<std::string> &ret, std::string &tmp, int dep, int n, int left, int right)
    {
        if (dep == n * 2)
        {
            ret.push_back(tmp);
            return;
        }

        if (left < n)
        {
            tmp[dep] = '(';
            dfs_build(ret, tmp, dep + 1, n, left + 1, right);
        }
        if (right < n && right < left)
        {
            tmp[dep] = ')';
            dfs_build(ret, tmp, dep + 1, n, left, right + 1);
        }
    }

    vector<string> generateParenthesis(int n) {
        std::vector<std::string> ret;
        std::string tmp(n * 2, '\x00');

        if (n == 0)
            return ret;

        dfs_build(ret, tmp, 0, n, 0, 0);

        return ret;
    }
};
