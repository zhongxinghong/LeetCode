/**
 * Submission ID: 89892039
 * Question ID: 1117
 * Question Title: 地图分析
 * Question URL: https://leetcode-cn.com/problems/as-far-from-land-as-possible/
 * Solution Time: 2020-07-21 10:24:36
 * Solution Test Result: 35 / 35
 * Solution Status: Accepted
 * Solution Memory: 120.4 MB
 * Solution Runtime: 496 ms
 */

class Solution {
public:

    struct point_s { int x, y; };

    void calcDistToLand(
        std::vector<std::vector<int>> &dp,
        point_s p)
    {
        static const int DIRS[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int n = dp.size(), x, y, k;
        std::queue<point_s> q;

        q.push(p);

        while (!q.empty())
        {
            p = q.front();
            q.pop();

            for (k = 0; k < 4; ++k)
            {
                x = p.x + DIRS[k][0];
                y = p.y + DIRS[k][1];

                if (x == -1 || x == n || y == -1 || y == n)
                    continue;

                if (dp[x][y] <= dp[p.x][p.y] + 1)
                    continue;

                dp[x][y] = dp[p.x][p.y] + 1;
                q.push({x, y});
            }
        }
    }

    int maxDistance(vector<vector<int>>& grid)
    {
        static const int INF = 1 << 16;

        int n = grid.size(), x, y, mx = -1;
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, INF));

        for (x = 0; x < n; ++x)
        {
            for (y = 0; y < n; ++y)
            {
                if (grid[x][y] == 1)
                    dp[x][y] = 0;
            }
        }

        for (x = 0; x < n; ++x)
        {
            for (y = 0; y < n; ++y)
            {
                if (grid[x][y] == 1)
                    calcDistToLand(dp, {x, y});
            }
        }

        for (x = 0; x < n; ++x)
        {
            for (y = 0; y < n; ++y)
            {
                mx = std::max(mx, dp[x][y]);
            }
        }

        if (mx == 0 || mx == INF)
            mx = -1;

        return mx;
    }
};
