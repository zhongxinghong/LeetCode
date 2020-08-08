/**
 * Submission ID: 91265541
 * Question ID: 118
 * Question Title: 杨辉三角
 * Question URL: https://leetcode-cn.com/problems/pascals-triangle/
 * Solution Time: 2020-07-25 12:29:41
 * Solution Test Result: 15 / 15
 * Solution Status: Accepted
 * Solution Memory: 6.6 MB
 * Solution Runtime: 4 ms
 */

class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        int i, j;
        std::vector<std::vector<int>> ret(numRows);

        if (numRows == 0)
            return ret;

        ret[0] = {1};

        for (i = 1; i < numRows; ++i)
        {
            ret[i] = ret[i - 1];
            ret[i].push_back(0);

            for (j = 1; j <= i; ++j)
                ret[i][j] += ret[i - 1][j - 1];
        }

        return ret;
    }
};
