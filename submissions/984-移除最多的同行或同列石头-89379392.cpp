/**
 * Submission ID: 89379392
 * Question ID: 984
 * Question Title: 移除最多的同行或同列石头
 * Question URL: https://leetcode-cn.com/problems/most-stones-removed-with-same-row-or-column/
 * Solution Time: 2020-07-19 18:38:04
 * Solution Test Result: 68 / 68
 * Solution Status: Accepted
 * Solution Memory: 13.9 MB
 * Solution Runtime: 72 ms
 */

class Solution {
public:

    class disjoint_set
    {
    public:
        disjoint_set(int n)
        {
            ps = std::vector<int>(n);
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
        int id;
        int x;
        int y;
    };

    struct point_cmp_x_s
    {
        bool operator()(const point_s &p1, const point_s &p2) const
            { return p1.x < p2.x; }
    };

    struct point_cmp_y_s
    {
        bool operator()(const point_s &p1, const point_s &p2) const
            { return p1.y < p2.y; }
    };

    int removeStones(vector<vector<int>>& stones)
    {
        int n = stones.size(), i;
        std::vector<point_s> points(n);
        disjoint_set djs(n);
        std::set<int> s;

        for (int i = 0; i < n; ++i)
            points[i] = {i, stones[i][0], stones[i][1]};

        std::sort(points.begin(), points.end(), point_cmp_x_s());

        for (i = 0; i < n - 1; ++i)
        {
            if (points[i].x == points[i + 1].x)
                djs.merge(points[i].id, points[i + 1].id);
        }

        std::sort(points.begin(), points.end(), point_cmp_y_s());

        for (i = 0; i < n - 1; ++i)
        {
            if (points[i].y == points[i + 1].y)
                djs.merge(points[i].id, points[i + 1].id);
        }

        for (i = 0; i < n; ++i)
            s.insert(djs.find(i));

        return n - s.size();
    }
};
