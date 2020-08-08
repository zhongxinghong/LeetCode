/**
 * Submission ID: 89256203
 * Question ID: 971
 * Question Title: 最短的桥
 * Question URL: https://leetcode-cn.com/problems/shortest-bridge/
 * Solution Time: 2020-07-19 11:41:03
 * Solution Test Result: 96 / 96
 * Solution Status: Accepted
 * Solution Memory: 19.3 MB
 * Solution Runtime: 128 ms
 */

class Solution {
public:

    struct point_s
    {
        int x;
        int y;
        int dist;
    };

    int shortestBridge(vector<vector<int>>& A)
    {
        static const int DIRS[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

        int n = A.size(), m = A[0].size(), x, y, k;
        std::vector<std::vector<bool>> vis(n, std::vector<bool>(m, false));
        std::stack<point_s> st;
        std::queue<point_s> q;
        point_s p;

        for (x = 0; x < n; ++x)
        {
            for (y = 0; y < m; ++y)
            {
                if (A[x][y] == 1)
                    goto FOUND_1;
            }
        }

    FOUND_1:

        st.push({x, y, 0});
        vis[x][y] = true;

        while (!st.empty())
        {
            p = st.top();
            st.pop();

            for (k = 0; k < 4; ++k)
            {
                x = p.x + DIRS[k][0];
                y = p.y + DIRS[k][1];

                if (x == -1 || x == n || y == -1 || y == m || vis[x][y])
                    continue;

                vis[x][y] = true;

                if (A[x][y] == 1)
                    st.push({x, y, 0});
                else
                    q.push({x, y, 1});
            }
        }

        while (!q.empty())
        {
            p = q.front();
            q.pop();

            if (A[p.x][p.y] == 1)
                return p.dist - 1;

            for (k = 0; k < 4; ++k)
            {
                x = p.x + DIRS[k][0];
                y = p.y + DIRS[k][1];

                if (x == -1 || x == n || y == -1 || y == m || vis[x][y])
                    continue;

                vis[x][y] = true;
                q.push({x, y, p.dist + 1});
            }
        }

        return -1;
    }
};
