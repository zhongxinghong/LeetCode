/**
 * Submission ID: 89206598
 * Question ID: 794
 * Question Title: 水位上升的泳池中游泳
 * Question URL: https://leetcode-cn.com/problems/swim-in-rising-water/
 * Solution Time: 2020-07-19 09:34:18
 * Solution Test Result: 41 / 41
 * Solution Status: Accepted
 * Solution Memory: 9.7 MB
 * Solution Runtime: 88 ms
 */

class Solution {
public:

    struct point_s
    {
        int x;
        int y;
        int time;

        bool operator<(const point_s &p) const
            { return time < p.time; }

        bool operator>(const point_s &p) const
            { return time > p.time; }
    };

    int swimInWater(vector<vector<int>>& grid)
    {
        static const int INF = 1 << 16;
        static const int DIRS[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

        int n = grid.size(), x, y, k;
        std::vector<std::vector<int>> vtime(n, std::vector<int>(n, INF));
        std::priority_queue<point_s, std::vector<point_s>, std::greater<point_s>> pq;
        point_s p;

        pq.push({0, 0, grid[0][0]});

        while (!pq.empty())
        {
            p = pq.top();
            pq.pop();

            vtime[p.x][p.y] = p.time;

            if (p.x == n - 1 && p.y == n - 1)
                break;

            for (k = 0; k < 4; ++k)
            {
                x = p.x + DIRS[k][0];
                y = p.y + DIRS[k][1];

                if (x == -1 || x == n || y == -1 || y == n)
                    continue;

                if (vtime[x][y] == INF)
                {
                    pq.push({x, y, std::max(p.time, grid[x][y])});
                    continue;
                }
            }
        }

        return vtime[n - 1][n - 1];
    }
};
