/**
 * Submission ID: 90966296
 * Question ID: 48
 * Question Title: 旋转图像
 * Question URL: https://leetcode-cn.com/problems/rotate-image/
 * Solution Time: 2020-07-24 11:12:32
 * Solution Test Result: 21 / 21
 * Solution Status: Accepted
 * Solution Memory: 7.1 MB
 * Solution Runtime: 4 ms
 */

class Solution {
public:

    void __rotate(std::vector<std::vector<int>> &matrix, const int &n, int x, int y)
    {
        int cx = n - 1 - x, cy = n - 1 - y;
        int t = matrix[x][y];
        matrix[x][y] = matrix[cy][x];
        matrix[cy][x] = matrix[cx][cy];
        matrix[cx][cy] = matrix[y][cx];
        matrix[y][cx] = t;
    }

    void rotate(vector<vector<int>>& matrix)
    {
        int n = matrix.size(), x, y, a = n / 2, b = (n % 2 == 0) ? n / 2 : n / 2 + 1;

        for (x = 0; x < a; ++x)
        {
            for (y = 0; y < b; ++y)
            {
                __rotate(matrix, n, x, y);
            }
        }
    }
};
