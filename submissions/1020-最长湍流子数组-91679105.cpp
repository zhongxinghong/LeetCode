/**
 * Submission ID: 91679105
 * Question ID: 1020
 * Question Title: 最长湍流子数组
 * Question URL: https://leetcode-cn.com/problems/longest-turbulent-subarray/
 * Solution Time: 2020-07-26 20:04:02
 * Solution Test Result: 86 / 86
 * Solution Status: Accepted
 * Solution Memory: 38 MB
 * Solution Runtime: 180 ms
 */

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A)
    {
        int i, n = A.size(), ret = 1, a = 1, b = 1;

        for (i = 1; i < n; ++i)
        {
            if (A[i] > A[i - 1])
            {
                a = b + 1;
                b = 1;
            }
            else if (A[i] < A[i - 1])
            {
                b = a + 1;
                a = 1;
            }
            else
            {
                a = b = 1;
            }

            ret = std::max(ret, std::max(a, b));
        }

        return ret;
    }
};
