/**
 * Submission ID: 89650447
 * Question ID: 1396
 * Question Title: 统计参与通信的服务器
 * Question URL: https://leetcode-cn.com/problems/count-servers-that-communicate/
 * Solution Time: 2020-07-20 16:20:23
 * Solution Test Result: 55 / 55
 * Solution Status: Accepted
 * Solution Memory: 20 MB
 * Solution Runtime: 152 ms
 */

class Solution {
public:

    class disjoint_set
    {
    public:
        disjoint_set(int n)
        {
            ps.resize(n);
            for (int i = 0; i < n; ++i)
                ps[i] = i;
        }

        int find(int x)
        {
            if (x == ps[x])
                return x;
            ps[x] = find(ps[x]);
            return ps[x];
        }

        void merge(int x, int y)
        {
            ps[find(y)] = find(x);
        }

    private:
        std::vector<int> ps;
    };

    struct point_s
    {
        int x;
        int y;
        int id;
    };

    struct point_cmp_y_s
    {
        bool operator()(const point_s &p1, const point_s &p2)
        {
            return p1.y < p2.y;
        }
    };

    int countServers(vector<vector<int>>& grid)
    {
        int n = grid.size(), m = grid[0].size(), k = 0, i, x, y, sum = 0;
        std::vector<point_s> points;

        for (x = 0; x < n; ++x)
        {
            for (y = 0; y < m; ++y)
            {
                if (grid[x][y] == 1)
                    points.push_back({x, y, k++});
            }
        }

        disjoint_set djs(k);

        for (i = 0; i < k - 1; ++i)
        {
            if (points[i].x == points[i + 1].x)
                djs.merge(points[i].id, points[i + 1].id);
        }

        std::sort(points.begin(), points.end(), point_cmp_y_s());

        for (i = 0; i < k - 1; ++i)
        {
            if (points[i].y == points[i + 1].y)
                djs.merge(points[i].id, points[i + 1].id);
        }

        std::vector<std::vector<int>> eqclz(k);

        for (i = 0; i < k; ++i)
            eqclz[djs.find(i)].push_back(i);

        for (i = 0; i < k; ++i)
        {
            if (eqclz[i].size() > 1)
                sum += eqclz[i].size();
        }

        return sum;
    }
};
