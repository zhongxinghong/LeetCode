/**
 * Submission ID: 91678273
 * Question ID: 1020
 * Question Title: 最长湍流子数组
 * Question URL: https://leetcode-cn.com/problems/longest-turbulent-subarray/
 * Solution Time: 2020-07-26 19:59:52
 * Solution Test Result: 86 / 86
 * Solution Status: Accepted
 * Solution Memory: 38.1 MB
 * Solution Runtime: 184 ms
 */

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A)
    {
        if (A.size() == 1)
            return 1;

        int i, n = A.size(), cur = (A[0] != A[1]) ? 2 : 1, ret = cur;

        for (i = 2; i < n; ++i)
        {
            if (A[i - 2] > A[i - 1] && A[i - 1] < A[i] ||
                A[i - 2] < A[i - 1] && A[i - 1] > A[i])
            {
                ret = std::max(ret, ++cur);
            }
            else
            {
                cur = (A[i - 1] != A[i]) ? 2 : 1;
            }
        }

        return ret;
    }
};
