/**
 * Submission ID: 90643563
 * Question ID: 51
 * Question Title: N皇后
 * Question URL: https://leetcode-cn.com/problems/n-queens/
 * Solution Time: 2020-07-23 11:54:10
 * Solution Test Result: 9 / 9
 * Solution Status: Accepted
 * Solution Memory: 7.3 MB
 * Solution Runtime: 4 ms
 */

class Solution {
public:

    bool check(
        const std::vector<std::string> &tmp,
        const int &n,
        int x,
        int y)
    {
        int i, j;

        for (j = y - 1; j != -1; --j)
        {
            if (tmp[x][j] == 'Q')
                return false;
        }

        for (i = x - 1, j = y - 1; i != -1 && j != -1; --i, --j)
        {
            if (tmp[i][j] == 'Q')
                return false;
        }

        for (i = x + 1, j = y - 1; i != n && j != -1; ++i, --j)
        {
            if (tmp[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void dfs(
        std::vector<std::vector<std::string>> &ret,
        std::vector<std::string> &tmp,
        int n,
        int j)
    {
        if (j == n)
        {
            ret.push_back(tmp);
            return;
        }

        for (int i = 0; i < n; ++i)
        {
            if (!check(tmp, n, i, j))
                continue;

            tmp[i][j] = 'Q';
            dfs(ret, tmp, n, j + 1);
            tmp[i][j] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        std::vector<std::vector<std::string>> ret;
        std::vector<std::string> tmp(n, std::string(n, '.'));

        dfs(ret, tmp, n, 0);

        return ret;
    }
};
