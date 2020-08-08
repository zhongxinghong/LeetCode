/**
 * Submission ID: 91066755
 * Question ID: 77
 * Question Title: 组合
 * Question URL: https://leetcode-cn.com/problems/combinations/
 * Solution Time: 2020-07-24 16:23:05
 * Solution Test Result: 27 / 27
 * Solution Status: Accepted
 * Solution Memory: 9 MB
 * Solution Runtime: 32 ms
 */

class Solution {
public:

    void dfs(
        std::vector<std::vector<int>> &ret,
        std::vector<int> &tmp,
        const int &n,
        const int &k,
        int i,
        int dep)
    {
        if (dep == k)
        {
            ret.push_back(tmp);
            return;
        }

        if (i == n)
            return;

        for (int j = i; j < n; ++j)
        {
            tmp[dep] = j + 1;
            dfs(ret, tmp, n, k, j + 1, dep + 1);
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        std::vector<std::vector<int>> ret;
        std::vector<int> tmp(k);

        dfs(ret, tmp, n, k, 0, 0);
        return ret;
    }
};
