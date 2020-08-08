/**
 * Submission ID: 91270509
 * Question ID: 125
 * Question Title: 验证回文串
 * Question URL: https://leetcode-cn.com/problems/valid-palindrome/
 * Solution Time: 2020-07-25 13:03:01
 * Solution Test Result: 481 / 481
 * Solution Status: Accepted
 * Solution Memory: 7.2 MB
 * Solution Runtime: 12 ms
 */

class Solution {
public:
    bool isPalindrome(string s)
    {
        int st = 0, ed = s.size() - 1;

        while (st <= ed)
        {
            while (st < ed && !isdigit(s[st]) && !isalpha(s[st]))
                st++;

            while (st < ed && !isdigit(s[ed]) && !isalpha(s[ed]))
                ed--;

            if (tolower(s[st]) != tolower(s[ed]))
                return false;

            st++;
            ed--;
        }

        return true;
    }
};
