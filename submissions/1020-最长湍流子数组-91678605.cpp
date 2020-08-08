/**
 * Submission ID: 91678605
 * Question ID: 1020
 * Question Title: 最长湍流子数组
 * Question URL: https://leetcode-cn.com/problems/longest-turbulent-subarray/
 * Solution Time: 2020-07-26 20:01:38
 * Solution Test Result: 86 / 86
 * Solution Status: Accepted
 * Solution Memory: 39.6 MB
 * Solution Runtime: 200 ms
 */

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A)
    {
        if (A.size() == 1)
            return 1;

        int i, n = A.size(), cur = (A[0] != A[1]) ? 2 : 1, ret = cur;
        std::vector<int> dA(n);

        for (i = 1; i < n; ++i)
            dA[i] = A[i] - A[i - 1];

        for (i = 2; i < n; ++i)
        {
            if (dA[i - 1] > 0 && dA[i] < 0 ||
                dA[i - 1] < 0 && dA[i] > 0)
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
