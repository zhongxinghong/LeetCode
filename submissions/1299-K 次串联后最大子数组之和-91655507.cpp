/**
 * Submission ID: 91655507
 * Question ID: 1299
 * Question Title: K 次串联后最大子数组之和
 * Question URL: https://leetcode-cn.com/problems/k-concatenation-maximum-sum/
 * Solution Time: 2020-07-26 18:10:20
 * Solution Test Result: 38 / 38
 * Solution Status: Accepted
 * Solution Memory: 28.4 MB
 * Solution Runtime: 84 ms
 */

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k)
    {
        static const long long M = 1e9 + 7;

        int i, j, n = arr.size();
        long long sum = 0, ret = 0, ret0;

        for (j = 0; j < k; ++j)
        {
            for (i = 0; i < n; ++i)
            {
                if (sum > 0)
                    sum += arr[i];
                else
                    sum = arr[i];

                if (sum > ret)
                    ret = sum;
            }

            if (j == 1)
                ret0 = ret;

            if (j == 2)
            {
                return (ret0 + (ret - ret0) * (k - 2)) % M;
            }
        }

        return ret % M;
    }
};
