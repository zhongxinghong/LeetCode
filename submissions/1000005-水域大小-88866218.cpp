/**
 * Submission ID: 88866218
 * Question ID: 1000005
 * Question Title: 水域大小
 * Question URL: https://leetcode-cn.com/problems/pond-sizes-lcci/
 * Solution Time: 2020-07-18 00:34:59
 * Solution Test Result: 27 / 27
 * Solution Status: Accepted
 * Solution Memory: 58.9 MB
 * Solution Runtime: 372 ms
 */

class Solution {
public:

    struct point_s
    {
        int x;
        int y;
    };

    int getArea(
        const std::vector<std::vector<int>> &land,
        std::vector<std::vector<bool>> &mask,
        const int &n,
        const int &m,
        point_s p)
    {
        static const int DIRS[8][2] = {{1, 1}, {1, 0}, {1, -1}, {0, 1},
                                       {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};

        int i, x, y, cnt = 0;
        std::stack<point_s> st;

        st.push(p);
        mask[p.x][p.y] = true;

        while (!st.empty())
        {
            p = st.top();
            st.pop();

            cnt++;

            for (i = 0; i < 8; ++i)
            {
                x = p.x + DIRS[i][0];
                y = p.y + DIRS[i][1];

                if (x < 0 || x >= n || y < 0 || y >= m || mask[x][y] || land[x][y] != 0)
                    continue;

                st.push({x, y});
                mask[x][y] = true;
            }
        }

        return cnt;
    }

    vector<int> pondSizes(vector<vector<int>>& land)
    {
        int n = land.size(), m = land[0].size(), x, y, area;
        std::vector<int> ret;
        std::vector<std::vector<bool>> mask(n, std::vector<bool>(m, false));

        for (x = 0; x < n; ++x)
        {
            for (y = 0; y < m; ++y)
            {
                if (mask[x][y] || land[x][y] != 0)
                    continue;

                ret.push_back(getArea(land, mask, n, m, {x, y}));
            }
        }

        std::sort(ret.begin(), ret.end());
        return ret;
    }
};
