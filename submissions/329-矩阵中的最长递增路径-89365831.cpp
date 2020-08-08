/**
 * Submission ID: 89365831
 * Question ID: 329
 * Question Title: 矩阵中的最长递增路径
 * Question URL: https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/
 * Solution Time: 2020-07-19 17:47:48
 * Solution Test Result: 138 / 138
 * Solution Status: Accepted
 * Solution Memory: 14 MB
 * Solution Runtime: 368 ms
 */

class Solution {
public:

    struct point_s { int x, y; };

    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        static const int DIRS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        if (matrix.empty())
            return 0;

        int n = matrix.size(), m = matrix[0].size(), i, j, k, x, y, maxlen = -1;
        std::vector<std::vector<int>> dp(n, std::vector<int>(m, 1));
        std::stack<point_s> st;
        point_s p;

        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < m; ++j)
            {
                st.push({i, j});

                while (!st.empty())
                {
                    p = st.top();
                    st.pop();

                    for (k = 0; k < 4; ++k)
                    {
                        x = p.x + DIRS[k][0];
                        y = p.y + DIRS[k][1];

                        if (x == -1 || x == n || y == -1 || y == m)
                            continue;

                        if (matrix[x][y] <= matrix[p.x][p.y])
                            continue;

                        if (dp[x][y] >= dp[p.x][p.y] + 1)
                            continue;

                        dp[x][y] = dp[p.x][p.y] + 1;
                        st.push({x, y});
                    }
                }
            }
        }

        for (x = 0; x < n; ++x)
        {
            for (y = 0; y < m; ++y)
            {
                if (maxlen < dp[x][y])
                    maxlen = dp[x][y];
            }
        }

        return maxlen;
    }
};
