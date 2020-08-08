/**
 * Submission ID: 89937308
 * Question ID: 1642
 * Question Title: 换酒问题
 * Question URL: https://leetcode-cn.com/problems/water-bottles/
 * Solution Time: 2020-07-21 12:25:37
 * Solution Test Result: 64 / 64
 * Solution Status: Accepted
 * Solution Memory: 5.9 MB
 * Solution Runtime: 0 ms
 */

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum = 0;
        div_t d;
        d.quot = numBottles;
        while (d.quot != 0)
        {
            sum += d.quot;
            d = div(d.quot + d.rem, numExchange);
        }
        return sum;
    }
};
