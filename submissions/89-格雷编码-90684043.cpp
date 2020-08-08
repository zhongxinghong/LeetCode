/**
 * Submission ID: 90684043
 * Question ID: 89
 * Question Title: 格雷编码
 * Question URL: https://leetcode-cn.com/problems/gray-code/
 * Solution Time: 2020-07-23 14:30:03
 * Solution Test Result: 12 / 12
 * Solution Status: Accepted
 * Solution Memory: 6.7 MB
 * Solution Runtime: 0 ms
 */

class Solution {
public:
    vector<int> grayCode(int n)
    {
        int d = 1 << n, m = 0, i, j;
        std::vector<int> ret(d);

        ret[m++] = 0;

        for (i = 1; i != d; i <<= 1)
        {
            for (j = i - 1; j != -1; --j)
            {
                ret[m++] = i | ret[j];
            }
        }

        return ret;
    }
};
