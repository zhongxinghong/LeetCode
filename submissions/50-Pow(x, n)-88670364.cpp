/**
 * Submission ID: 88670364
 * Question ID: 50
 * Question Title: Pow(x, n)
 * Question URL: https://leetcode-cn.com/problems/powx-n/
 * Solution Time: 2020-07-17 14:51:18
 * Solution Test Result: 304 / 304
 * Solution Status: Accepted
 * Solution Memory: 6 MB
 * Solution Runtime: 0 ms
 */

class Solution {
public:
    double myPow(double x, int n) {
        double ret = 1;
        for (long long i = llabs(n); i; i >>= 1)
        {
            if (i % 2)
                ret *= x;
            x *= x;
        }
        return n < 0 ? (1 / ret) : ret;
    }
};
