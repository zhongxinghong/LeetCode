/**
 * Submission ID: 86752084
 * Question ID: 9
 * Question Title: 回文数
 * Question URL: https://leetcode-cn.com/problems/palindrome-number/
 * Solution Time: 2020-07-11 13:40:18
 * Solution Test Result: 11509 / 11509
 * Solution Status: Accepted
 * Solution Memory: 5.8 MB
 * Solution Runtime: 24 ms
 */

class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0)
            return false;

        long long y = x, z = 0;

        while (y)
        {
            z = z * 10 + y % 10;
            y /= 10;
        }
        return x == z;
    }
};
