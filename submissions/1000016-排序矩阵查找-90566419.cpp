/**
 * Submission ID: 90566419
 * Question ID: 1000016
 * Question Title: 排序矩阵查找
 * Question URL: https://leetcode-cn.com/problems/sorted-matrix-search-lcci/
 * Solution Time: 2020-07-23 08:28:02
 * Solution Test Result: 129 / 129
 * Solution Status: Accepted
 * Solution Memory: 10.6 MB
 * Solution Runtime: 160 ms
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if (matrix.empty())
            return false;

        int n = matrix.size(), m = matrix[0].size(), i = 0, j = m - 1;

        for (;;)
        {
            if (i == n || j == -1)
                return false;

            if (matrix[i][j] == target)
                return true;

            if (matrix[i][j] < target)
                i++;
            else
                j--;
        }

        return false;
    }
};
