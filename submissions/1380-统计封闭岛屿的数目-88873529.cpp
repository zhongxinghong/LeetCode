/**
 * Submission ID: 88873529
 * Question ID: 1380
 * Question Title: 统计封闭岛屿的数目
 * Question URL: https://leetcode-cn.com/problems/number-of-closed-islands/
 * Solution Time: 2020-07-18 02:10:44
 * Solution Test Result: 47 / 47
 * Solution Status: Accepted
 * Solution Memory: 13.8 MB
 * Solution Runtime: 32 ms
 */

class Solution {
public:

    struct point_s
    {
        int x;
        int y;
    };

    void land2water(std::vector<std::vector<int>> &grid, point_s p)
    {
        static const int DIRS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        if (grid[p.x][p.y] == 1)
            return;

        int n = grid.size(), m = grid[0].size(), x, y, k;
        std::stack<point_s> st;

        st.push(p);
        grid[p.x][p.y] = 1;

        while (!st.empty())
        {
            p = st.top();
            st.pop();

            for (k = 0; k < 4; ++k)
            {
                x = p.x + DIRS[k][0];
                y = p.y + DIRS[k][1];

                if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 1)
                    continue;

                st.push({x, y});
                grid[x][y] = 1;
            }
        }
    }

    void visitLand(std::vector<std::vector<int>> &grid, std::vector<std::vector<bool>> &vis, point_s p)
    {
        static const int DIRS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int n = grid.size(), m = grid[0].size(), x, y, k;
        std::stack<point_s> st;

        st.push(p);
        vis[p.x][p.y] = true;

        while (!st.empty())
        {
            p = st.top();
            st.pop();

            for (k = 0; k < 4; ++k)
            {
                x = p.x + DIRS[k][0];
                y = p.y + DIRS[k][1];

                if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || grid[x][y] == 1)
                    continue;

                st.push({x, y});
                vis[x][y] = true;
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid)
    {
        int n = grid.size(), m = grid[0].size(), x, y, cnt = 0;
        std::vector<std::vector<bool>> vis(n, std::vector<bool>(m, false));

        for (x = 0, y = 0; x < n; ++x)
            land2water(grid, {x, y});

        for (x = 0, y = 0; y < m; ++y)
            land2water(grid, {x, y});

        for (x = n - 1, y = m - 1; x; --x)
            land2water(grid, {x, y});

        for (x = n - 1, y = m - 1; y; --y)
            land2water(grid, {x, y});

        for (x = 1; x < n - 1; ++x)
        {
            for (y = 1; y < m - 1; ++y)
            {
                if (vis[x][y] || grid[x][y] == 1)
                    continue;

                cnt++;
                visitLand(grid, vis, {x, y});
            }
        }

        return cnt;
    }
};
