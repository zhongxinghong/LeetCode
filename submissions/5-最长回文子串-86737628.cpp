/**
 * Submission ID: 86737628
 * Question ID: 5
 * Question Title: 最长回文子串
 * Question URL: https://leetcode-cn.com/problems/longest-palindromic-substring/
 * Solution Time: 2020-07-11 12:20:50
 * Solution Test Result: 103 / 103
 * Solution Status: Accepted
 * Solution Memory: 6.8 MB
 * Solution Runtime: 56 ms
 */

class Solution {
public:

    size_t maxPalindromeLength(const string &s, int st, int ed)
    {
        for (; st >= 0 && ed < s.size(); --st, ++ed)
        {
            if (s[st] != s[ed])
                break;
        }
        return ed - st - 1;
    }

    string longestPalindrome(string s) {
        int pos = 0, len, max_len = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            if ((len = maxPalindromeLength(s, i, i)) > max_len)
            {
                pos = i - len / 2;
                max_len = len;
            }

            if (i != s.size() - 1 && (len = maxPalindromeLength(s, i, i + 1)) > max_len)
            {
                pos = i + 1 - len / 2;
                max_len = len;
            }
        }

        return s.substr(pos, max_len);
    }
};
