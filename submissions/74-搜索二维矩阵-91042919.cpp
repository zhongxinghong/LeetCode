/**
 * Submission ID: 91042919
 * Question ID: 74
 * Question Title: 搜索二维矩阵
 * Question URL: https://leetcode-cn.com/problems/search-a-2d-matrix/
 * Solution Time: 2020-07-24 15:31:22
 * Solution Test Result: 136 / 136
 * Solution Status: Accepted
 * Solution Memory: 7.7 MB
 * Solution Runtime: 12 ms
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if (matrix.empty())
            return false;

        int n = matrix.size(), m = matrix[0].size(), x = 0, y = m - 1;

        while (x != n && y != -1)
        {
            if (matrix[x][y] == target)
                return true;
            else if (matrix[x][y] > target)
                y--;
            else
                x++;
        }

        return false;
    }
};
