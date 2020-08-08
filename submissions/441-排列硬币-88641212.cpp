/**
 * Submission ID: 88641212
 * Question ID: 441
 * Question Title: 排列硬币
 * Question URL: https://leetcode-cn.com/problems/arranging-coins/
 * Solution Time: 2020-07-17 12:46:51
 * Solution Test Result: 1336 / 1336
 * Solution Status: Accepted
 * Solution Memory: 6 MB
 * Solution Runtime: 12 ms
 */

class Solution {
public:
    int arrangeCoins(int n) {
        long long i = 1, st = 0, ed = 1;
        for (;;)
        {
            if (st <= n && n < ed)
                return i - 1;

            st = ed;
            ed += (++i);
        }

        return -1;
    }
};
