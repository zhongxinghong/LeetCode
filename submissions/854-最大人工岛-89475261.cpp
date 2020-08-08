/**
 * Submission ID: 89475261
 * Question ID: 854
 * Question Title: 最大人工岛
 * Question URL: https://leetcode-cn.com/problems/making-a-large-island/
 * Solution Time: 2020-07-20 00:55:14
 * Solution Test Result: 63 / 63
 * Solution Status: Accepted
 * Solution Memory: 12.2 MB
 * Solution Runtime: 40 ms
 */

class Solution {
public:

    struct point_s { int x, y; };

    void calcArea(
        std::vector<int> &areas,
        std::vector<std::vector<int>> &grid,
        point_s p)
    {
        static const int DIRS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int n = grid.size(), m = grid[0].size(), ix = areas.size(), x, y, k, area = 0;
        std::stack<point_s> st;

        st.push(p);
        grid[p.x][p.y] = ix;

        while (!st.empty())
        {
            p = st.top();
            st.pop();

            area++;


            for (k = 0; k < 4; ++k)
            {
                x = p.x + DIRS[k][0];
                y = p.y + DIRS[k][1];

                if (x == -1 || x == n || y == -1 || y == m || grid[x][y] != -1)
                    continue;

                st.push({x, y});
                grid[x][y] = ix;
            }
        }

        areas.push_back(area);
    }

    int largestIsland(vector<vector<int>>& grid)
    {
        static const int DIRS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int n = grid.size(), m = grid[0].size(), k, x, y, px, py, area, max_area = -1;
        std::vector<int> areas;
        std::set<int> lands;

        for (x = 0; x < n; ++x)
        {
            for (y = 0; y < m; ++y)
            {
                grid[x][y] -= 2;
            }
        }

        for (x = 0; x < n; ++x)
        {
            for (y = 0; y < m; ++y)
            {
                if (grid[x][y] != -1)
                    continue;
                calcArea(areas, grid, {x, y});
                max_area = std::max(max_area, areas.back());
            }
        }

        for (px = 0; px < n; ++px)
        {
            for (py = 0; py < m; ++py)
            {
                if (grid[px][py] != -2)
                    continue;

                area = 1;
                lands.clear();

                for (k = 0; k < 4; ++k)
                {
                    x = px + DIRS[k][0];
                    y = py + DIRS[k][1];

                    if (x == -1 || x == n || y == -1 || y == m || grid[x][y] < 0)
                        continue;

                    if (lands.find(grid[x][y]) != lands.end())
                        continue;

                    lands.insert(grid[x][y]);
                    area += areas[grid[x][y]];
                }

                max_area = std::max(max_area, area);
            }
        }

        return max_area;
    }
};
