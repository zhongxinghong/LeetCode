/**
 * Submission ID: 89051792
 * Question ID: 529
 * Question Title: 扫雷游戏
 * Question URL: https://leetcode-cn.com/problems/minesweeper/
 * Solution Time: 2020-07-18 17:30:05
 * Solution Test Result: 54 / 54
 * Solution Status: Accepted
 * Solution Memory: 13.6 MB
 * Solution Runtime: 84 ms
 */

class Solution {
public:

    struct point_s { int x, y; };

    int count_M(const std::vector<std::vector<char>> &board, const point_s &p)
    {
        static const int DIRS[8][2] = {{1, 1}, {1, 0}, {1, -1}, {0, 1},
                                       {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};

        int n = board.size(), m = board[0].size(), x, y, k, cnt = 0;
        for (k = 0; k < 8; ++k)
        {
            x = p.x + DIRS[k][0];
            y = p.y + DIRS[k][1];

            if (x == -1 || x == n || y == -1 || y == m)
                continue;

            if (board[x][y] == 'M')
                cnt++;
        }

        return cnt;
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)
    {
        static const int DIRS[8][2] = {{1, 1}, {1, 0}, {1, -1}, {0, 1},
                                       {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};

        int n = board.size(), m = board[0].size(), x, y, k, cnt;

        std::queue<point_s> q;
        q.push({click[0], click[1]});

        for (; !q.empty(); q.pop())
        {
            const point_s &p = q.front();

            switch (board[p.x][p.y])
            {
            case 'E':
                cnt = count_M(board, p);

                if (cnt > 0)
                {
                    board[p.x][p.y] = cnt + '0';
                    break;
                }

                board[p.x][p.y] = 'B';

                for (k = 0; k < 8; ++k)
                {
                    x = p.x + DIRS[k][0];
                    y = p.y + DIRS[k][1];

                    if (x == -1 || x == n || y == -1 || y == m || board[x][y] != 'E')
                        continue;

                    q.push({x, y});
                }
                break;

            case 'M':
                board[p.x][p.y] = 'X';
                return board;

            case 'B':
            case 'X':
            default:
                break;
            }
        }

        return board;
    }
};
