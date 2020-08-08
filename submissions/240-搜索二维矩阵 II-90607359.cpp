/**
 * Submission ID: 90607359
 * Question ID: 240
 * Question Title: 搜索二维矩阵 II
 * Question URL: https://leetcode-cn.com/problems/search-a-2d-matrix-ii/
 * Solution Time: 2020-07-23 10:31:21
 * Solution Test Result: 129 / 129
 * Solution Status: Accepted
 * Solution Memory: 10.7 MB
 * Solution Runtime: 152 ms
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;

        int n = matrix.size(), m = matrix[0].size(), i = 0, j = m - 1;

        while (i != n && j != -1)
        {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] < target)
                i++;
            else
                j--;
        }

        return false;
    }
};
