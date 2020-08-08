/**
 * Submission ID: 88862329
 * Question ID: 1507
 * Question Title: 检查网格中是否存在有效路径
 * Question URL: https://leetcode-cn.com/problems/check-if-there-is-a-valid-path-in-a-grid/
 * Solution Time: 2020-07-18 00:08:03
 * Solution Test Result: 80 / 80
 * Solution Status: Accepted
 * Solution Memory: 48.9 MB
 * Solution Runtime: 452 ms
 */

class Solution {
public:

    struct point
    {
        int x;
        int y;
        int type;
    };

    bool hasValidPath(vector<vector<int>>& grid)
    {
        /* (dx, dy) */

        #define L { 0, -1}
        #define R { 0,  1}
        #define U {-1,  0}
        #define D { 1,  0}

        #define ISL(dx, dy) (dx ==  0 && dy == -1)
        #define ISR(dx, dy) (dx ==  0 && dy ==  1)
        #define ISU(dx, dy) (dx == -1 && dy ==  0)
        #define ISD(dx, dy) (dx ==  1 && dy ==  0)

        static int DIRS[6][2][2] = {{L, R}, {U, D}, {L, D}, {R, D}, {L, U}, {U, R}};

        int m = grid.size(), n = grid[0].size(), x, y, dx, dy, tp, i;
        std::vector<std::vector<bool>> mask(m, std::vector<bool>(n, false));
        std::stack<point> st;
        point p;

        st.push({0, 0, grid[0][0]});

        while (!st.empty())
        {
            p = st.top();
            st.pop();

            mask[p.x][p.y] = true;

            if (p.x == m - 1 && p.y == n - 1)
                return true;

            for (i = 0; i < 2; ++i)
            {
                dx = DIRS[p.type - 1][i][0];
                dy = DIRS[p.type - 1][i][1];
                x = p.x + dx;
                y = p.y + dy;

                if (x < 0 || x >= m || y < 0 || y >= n)
                    continue;

                if (mask[x][y])
                    continue;

                tp = grid[x][y];

                switch (p.type)
                {
                case 1:
                    if (tp == 3 && ISR(dx, dy) || tp == 4 && ISL(dx, dy) ||
                        tp == 5 && ISR(dx, dy) || tp == 6 && ISL(dx, dy) ||
                        tp == 1)
                        goto ST_PUSH;
                    break;
                case 2:
                    if (tp == 3 && ISU(dx, dy) || tp == 4 && ISU(dx, dy) ||
                        tp == 5 && ISD(dx, dy) || tp == 6 && ISD(dx, dy) ||
                        tp == 2)
                        goto ST_PUSH;
                    break;
                case 3:
                    if (tp == 1 && ISL(dx, dy) || tp == 2 && ISD(dx, dy) ||
                        tp == 4 && ISL(dx, dy) || tp == 5 && ISD(dx, dy) ||
                        tp == 6)
                        goto ST_PUSH;
                    break;
                case 4:
                    if (tp == 1 && ISR(dx, dy) || tp == 2 && ISD(dx, dy) ||
                        tp == 3 && ISR(dx, dy) || tp == 6 && ISD(dx, dy) ||
                        tp == 5)
                        goto ST_PUSH;
                    break;
                case 5:
                    if (tp == 1 && ISL(dx, dy) || tp == 2 && ISU(dx, dy) ||
                        tp == 3 && ISU(dx, dy) || tp == 6 && ISL(dx, dy) ||
                        tp == 4)
                        goto ST_PUSH;
                    break;
                case 6:
                    if (tp == 1 && ISR(dx, dy) || tp == 2 && ISU(dx, dy) ||
                        tp == 4 && ISU(dx, dy) || tp == 5 && ISR(dx, dy) ||
                        tp == 3)
                        goto ST_PUSH;
                    break;
                }

                continue;

            ST_PUSH:
                st.push({x, y, grid[x][y]});
            }
        }

        return false;
    }
};
