/**
 * Submission ID: 91023865
 * Question ID: 69
 * Question Title: x 的平方根
 * Question URL: https://leetcode-cn.com/problems/sqrtx/
 * Solution Time: 2020-07-24 14:44:19
 * Solution Test Result: 1017 / 1017
 * Solution Status: Accepted
 * Solution Memory: 5.8 MB
 * Solution Runtime: 0 ms
 */

class Solution {
public:
    int mySqrt(int x)
    {
        static const double eps = 1e-5;

        if (x <= 1)
            return x;

        double pre = 2, cur = 1;

        while (fabs(pre - cur) > eps)
        {
            pre = cur;
            cur = 0.5 * (cur + x / cur);
        }

        return cur;
    }
};
