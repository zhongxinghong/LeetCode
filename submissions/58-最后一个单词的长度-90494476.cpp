/**
 * Submission ID: 90494476
 * Question ID: 58
 * Question Title: 最后一个单词的长度
 * Question URL: https://leetcode-cn.com/problems/length-of-last-word/
 * Solution Time: 2020-07-22 22:07:51
 * Solution Test Result: 59 / 59
 * Solution Status: Accepted
 * Solution Memory: 6.6 MB
 * Solution Runtime: 0 ms
 */

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i, j, n = s.size();

        for (i = n - 1; i > -1 && s[i] == ' '; --i)
            ;

        for (j = i; j > -1 && s[j] != ' '; --j)
            ;

        return i - j;
    }
};
