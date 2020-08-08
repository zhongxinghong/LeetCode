/**
 * Submission ID: 89362976
 * Question ID: 329
 * Question Title: 矩阵中的最长递增路径
 * Question URL: https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/
 * Solution Time: 2020-07-19 17:37:29
 * Solution Test Result: 138 / 138
 * Solution Status: Accepted
 * Solution Memory: 56.4 MB
 * Solution Runtime: 388 ms
 */

class Solution {
public:

    struct point_s { int x, y; };

    bool isMinimalPoint(const std::vector<std::vector<int>> &matrix, int px, int py)
    {
        static const int DIRS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int n = matrix.size(), m = matrix[0].size(), x, y, k;

        for (k = 0; k < 4; ++k)
        {
            x = px + DIRS[k][0];
            y = py + DIRS[k][1];

            if (x == -1 || x == n || y == -1 || y == m)
                continue;

            if (matrix[x][y] < matrix[px][py])
                return false;
        }

        return true;
    }

    void __longestIncreasingPath(
        std::vector<std::vector<int>> &matrix,
        std::vector<std::vector<int>> &dp,
        point_s p)
    {
        static const int DIRS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int n = matrix.size(), m = matrix[0].size(), x, y, k;
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

                if (x == -1 || x == n || y == -1 || y == m)
                    continue;

                if (matrix[x][y] <= matrix[p.x][p.y])
                    continue;

                if (dp[x][y] >= dp[p.x][p.y] + 1)
                    continue;

                dp[x][y] = dp[p.x][p.y] + 1;
                q.push({x, y});
            }
        }
    }

    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        if (matrix.empty())
            return 0;

        int n = matrix.size(), m = matrix[0].size(), x, y, i, maxlen = -1;
        std::vector<point_s> st_points;
        std::vector<std::vector<int>> dp(n, std::vector<int>(m, 1));

        for (x = 0; x < n; ++x)
        {
            for (y = 0; y < m; ++y)
            {
                if (isMinimalPoint(matrix, x, y))
                    st_points.push_back({x, y});
            }
        }

        for (i = 0; i < st_points.size(); ++i)
            __longestIncreasingPath(matrix, dp, st_points[i]);

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
