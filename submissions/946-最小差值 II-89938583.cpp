/**
 * Submission ID: 89938583
 * Question ID: 946
 * Question Title: 最小差值 II
 * Question URL: https://leetcode-cn.com/problems/smallest-range-ii/
 * Solution Time: 2020-07-21 12:34:26
 * Solution Test Result: 68 / 68
 * Solution Status: Accepted
 * Solution Memory: 15.2 MB
 * Solution Runtime: 60 ms
 */

class Solution {
public:

    int smallestRangeII(vector<int>& A, int K)
    {
        std::sort(A.begin(), A.end());

        int n = A.size(), i, ret = A[n - 1] - A[0], mini, maxi;

        for (i = 1; i < n; ++i)
        {
            mini = std::min(A[0] + K, A[i] - K);
            maxi = std::max(A[i - 1] + K, A[n - 1] - K);
            ret = std::min(ret, maxi - mini);
        }

        return ret;
    }
};
