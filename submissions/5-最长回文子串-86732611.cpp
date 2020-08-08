/**
 * Submission ID: 86732611
 * Question ID: 5
 * Question Title: 最长回文子串
 * Question URL: https://leetcode-cn.com/problems/longest-palindromic-substring/
 * Solution Time: 2020-07-11 11:55:48
 * Solution Test Result: 103 / 103
 * Solution Status: Accepted
 * Solution Memory: 6.8 MB
 * Solution Runtime: 624 ms
 */

class Solution {
public:

    bool isPalindrome(const string &s, size_t i, size_t j)
    {
        for (; i < j; ++i, --j)
        {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }

    string longestPalindrome(string s) {
        size_t i, j, max_len = 0, pos = 0;

        for (i = 0; i < s.size(); ++i)
        {
            for (j = s.size() - 1; j >= i && j < s.size(); --j)
            {
                if (j - i + 1 <= max_len)
                    break;

                if (isPalindrome(s, i, j))
                {
                    max_len = j - i + 1;
                    pos = i;
                }
            }
        }

        return s.substr(pos, max_len);
    }
};
