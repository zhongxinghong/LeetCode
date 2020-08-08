/**
 * Submission ID: 89349092
 * Question ID: 130
 * Question Title: 被围绕的区域
 * Question URL: https://leetcode-cn.com/problems/surrounded-regions/
 * Solution Time: 2020-07-19 16:57:01
 * Solution Test Result: 59 / 59
 * Solution Status: Accepted
 * Solution Memory: 10.7 MB
 * Solution Runtime: 48 ms
 */

class Solution {
public:

    void visitO(
        const std::vector<std::vector<char>> &board,
        std::vector<std::vector<bool>> &vis,
        const int &n, const int &m, int x, int y)
    {
        if (x == -1 || x == n || y == -1 || y == m || vis[x][y] || board[x][y] == 'X')
            return;

        vis[x][y] = true;

        visitO(board, vis, n, m, x + 1, y);
        visitO(board, vis, n, m, x - 1, y);
        visitO(board, vis, n, m, x, y + 1);
        visitO(board, vis, n, m, x, y - 1);
    }

    void solve(vector<vector<char>>& board)
    {
        if (board.empty())
            return;

        int n = board.size(), m = board[0].size(), x, y;
        std::vector<std::vector<bool>> vis(n, std::vector<bool>(m, false));

        for (x = 0, y = 0; x < n; ++x)
            visitO(board, vis, n, m, x, y);

        for (x = 0, y = 0; y < m; ++y)
            visitO(board, vis, n, m, x, y);

        for (x = n - 1, y = m - 1; x > -1; --x)
            visitO(board, vis, n, m, x, y);

        for (x = n - 1, y = m - 1; y > -1; --y)
            visitO(board, vis, n, m, x, y);

        for (x = 0; x < n; ++x)
        {
            for (y = 0; y < m; ++y)
            {
                if (vis[x][y] || board[x][y] == 'X')
                    continue;

                board[x][y] = 'X';
            }
        }
    }
};
