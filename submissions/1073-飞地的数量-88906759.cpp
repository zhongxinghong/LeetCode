/**
 * Submission ID: 88906759
 * Question ID: 1073
 * Question Title: 飞地的数量
 * Question URL: https://leetcode-cn.com/problems/number-of-enclaves/
 * Solution Time: 2020-07-18 09:39:07
 * Solution Test Result: 56 / 56
 * Solution Status: Accepted
 * Solution Memory: 40.9 MB
 * Solution Runtime: 204 ms
 */

class Solution {
public:

    struct point_s
    {
        int x;
        int y;
    };

    void land2water(std::vector<std::vector<int>> &A, point_s p)
    {
        static const int DIRS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        if (A[p.x][p.y] == 0)
            return;

        int n = A.size(), m = A[0].size(), x, y, k;
        std::stack<point_s> st;

        A[p.x][p.y] = 0;
        st.push(p);

        while (!st.empty())
        {
            p = st.top();
            st.pop();

            for (k = 0; k < 4; ++k)
            {
                x = p.x + DIRS[k][0];
                y = p.y + DIRS[k][1];

                if (x < 0 || x >= n || y < 0 || y >= m || A[x][y] == 0)
                    continue;

                A[x][y] = 0;
                st.push({x, y});
            }
        }
    }

    int visitAndGetArea(const std::vector<std::vector<int>> &A, std::vector<std::vector<bool>> &vis, point_s p)
    {
        static const int DIRS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int n = A.size(), m = A[0].size(), x, y, k, cnt = 0;
        std::stack<point_s> st;

        st.push(p);
        vis[p.x][p.y] = true;

        while (!st.empty())
        {
            p = st.top();
            st.pop();

            cnt++;

            for (k = 0; k < 4; ++k)
            {
                x = p.x + DIRS[k][0];
                y = p.y + DIRS[k][1];

                if (x < 0 || x >= n || y < 0 || y > m || vis[x][y] || A[x][y] == 0)
                    continue;

                st.push({x, y});
                vis[x][y] = true;
            }
        }

        return cnt;
    }

    int numEnclaves(vector<vector<int>>& A)
    {
        int n = A.size(), m = A[0].size(), x, y, cnt = 0;
        std::vector<std::vector<bool>> vis(n, std::vector<bool>(m, false));

        for (x = 0, y = 0; x < n; ++x)
            land2water(A, {x, y});

        for (x = 0, y = 0; y < m; ++y)
            land2water(A, {x, y});

        for (x = n - 1, y = m - 1; x; --x)
            land2water(A, {x, y});

        for (x = n - 1, y = m - 1; y; --y)
            land2water(A, {x, y});

        for (x = 1; x < n - 1; ++x)
        {
            for (y = 1; y < m - 1; ++y)
            {
                if (vis[x][y] || A[x][y] == 0)
                    continue;

                cnt += visitAndGetArea(A, vis, {x, y});
            }
        }

        return cnt;
    }
};
