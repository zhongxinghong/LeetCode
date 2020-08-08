/**
 * Submission ID: 89941706
 * Question ID: 1033
 * Question Title: 坏了的计算器
 * Question URL: https://leetcode-cn.com/problems/broken-calculator/
 * Solution Time: 2020-07-21 12:52:46
 * Solution Test Result: 84 / 84
 * Solution Status: Accepted
 * Solution Memory: 5.9 MB
 * Solution Runtime: 0 ms
 */

class Solution {
public:
    int brokenCalc(int X, int Y)
    {
        if (X >= Y)
            return X - Y;
        else if (Y % 2 == 0)
            return 1 + brokenCalc(X, Y / 2);
        else
            return 1 + brokenCalc(X, Y + 1);
    }
};
