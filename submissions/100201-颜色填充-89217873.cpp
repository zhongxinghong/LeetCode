/**
 * Submission ID: 89217873
 * Question ID: 100201
 * Question Title: 颜色填充
 * Question URL: https://leetcode-cn.com/problems/color-fill-lcci/
 * Solution Time: 2020-07-19 10:16:33
 * Solution Test Result: 277 / 277
 * Solution Status: Accepted
 * Solution Memory: 13.9 MB
 * Solution Runtime: 16 ms
 */

class Solution {
public:

    struct point_s { int x, y; };

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        static const int DIRS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int n = image.size(), m = image[0].size(), x, y, k;
        std::vector<std::vector<bool>> vis(n, std::vector<bool>(m, false));
        std::queue<point_s> q;
        point_s p;

        if (image[sr][sc] == newColor)
            return image;

        q.push({sr, sc});
        vis[sr][sc] = true;

        while (!q.empty())
        {
            p = q.front();
            q.pop();

            for (k = 0; k < 4; ++k)
            {
                x = p.x + DIRS[k][0];
                y = p.y + DIRS[k][1];

                if (x == -1 || x == n || y == -1 || y == m || vis[x][y] || image[x][y] != image[p.x][p.y])
                    continue;

                vis[x][y] = true;
                q.push({x, y});
            }

            image[p.x][p.y] = newColor;
        }

        return image;
    }
};
