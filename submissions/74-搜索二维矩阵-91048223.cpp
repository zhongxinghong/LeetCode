/**
 * Submission ID: 91048223
 * Question ID: 74
 * Question Title: 搜索二维矩阵
 * Question URL: https://leetcode-cn.com/problems/search-a-2d-matrix/
 * Solution Time: 2020-07-24 15:41:54
 * Solution Test Result: 136 / 136
 * Solution Status: Accepted
 * Solution Memory: 7.5 MB
 * Solution Runtime: 8 ms
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if (matrix.empty())
            return false;

        int n = matrix.size(), m = matrix[0].size(), st = 0, ed = n * m, mid, x;

        while (st < ed)
        {
            mid = (st + ed) / 2;
            x = matrix[mid / m][mid % m];

            if (x == target)
                return true;
            else if (x > target)
                ed = mid;
            else
                st = mid + 1;
        }

        return false;
    }
};
