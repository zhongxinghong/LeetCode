/**
 * Submission ID: 91266286
 * Question ID: 119
 * Question Title: 杨辉三角 II
 * Question URL: https://leetcode-cn.com/problems/pascals-triangle-ii/
 * Solution Time: 2020-07-25 12:34:38
 * Solution Test Result: 34 / 34
 * Solution Status: Accepted
 * Solution Memory: 6.4 MB
 * Solution Runtime: 4 ms
 */

class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        int i, j, k = rowIndex;
        std::vector<int> ret(k + 1, 0);

        ret[0] = 1;

        for (i = 1; i <= k; ++i)
        {
            for (j = i - 1; j > -1; --j)
                ret[j + 1] += ret[j];
        }

        return ret;
    }
};
