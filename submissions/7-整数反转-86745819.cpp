/**
 * Submission ID: 86745819
 * Question ID: 7
 * Question Title: 整数反转
 * Question URL: https://leetcode-cn.com/problems/reverse-integer/
 * Solution Time: 2020-07-11 13:07:31
 * Solution Test Result: 1032 / 1032
 * Solution Status: Accepted
 * Solution Memory: 6 MB
 * Solution Runtime: 8 ms
 */

class Solution {
public:
    int reverse(int x) {
        bool lt0 = (x < 0);
        long long ret = 0;
        long long y = (lt0 ? -(long long)(x) : (long long)x);

        while (y > 0)
        {
            ret = ret * 10 + y % 10;
            y /= 10;
        }

        ret = (lt0 ? -ret : ret);

        if (ret > (1LL << 31) - 1 || ret < -(1LL << 31))
            return 0;

        return ret;
    }
};
