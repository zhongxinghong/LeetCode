/**
 * Submission ID: 91080072
 * Question ID: 79
 * Question Title: 单词搜索
 * Question URL: https://leetcode-cn.com/problems/word-search/
 * Solution Time: 2020-07-24 16:52:08
 * Solution Test Result: 89 / 89
 * Solution Status: Accepted
 * Solution Memory: 8.4 MB
 * Solution Runtime: 36 ms
 */

class Solution {
public:

    bool dfs(
        const std::vector<std::vector<char>> &board,
        const std::string &word,
        std::vector<std::vector<bool>> &vis,
        const int &n,
        const int &m,
        int x,
        int y,
        int ix)
    {
        if (vis[x][y] || board[x][y] != word[ix])
            return false;

        vis[x][y] = true;

        if (ix + 1 == word.size())
            return true;

        if (x - 1 != -1 && dfs(board, word, vis, n, m, x - 1, y, ix + 1))
            return true;

        if (y - 1 != -1 && dfs(board, word, vis, n, m, x, y - 1, ix + 1))
            return true;

        if (x + 1 != n && dfs(board, word, vis, n, m, x + 1, y, ix + 1))
            return true;

        if (y + 1 != m && dfs(board, word, vis, n, m, x, y + 1, ix + 1))
            return true;

        vis[x][y] = false;

        return false;
    }


    bool exist(vector<vector<char>>& board, string word)
    {
        int n = board.size(), m = board[0].size(), i, j;
        std::vector<std::vector<bool>> vis(n, std::vector<bool>(m, false));

        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < m; ++j)
            {
                if (board[i][j] != word[0])
                    continue;

                if (dfs(board, word, vis, n, m, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};
