/**
 * Submission ID: 88430804
 * Question ID: 557
 * Question Title: 反转字符串中的单词 III
 * Question URL: https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/
 * Solution Time: 2020-07-16 18:24:25
 * Solution Test Result: 30 / 30
 * Solution Status: Accepted
 * Solution Memory: 9.5 MB
 * Solution Runtime: 16 ms
 */

class Solution {
public:

    void reverse(std::string &s, int st, int ed)
    {
        for (; st < ed; ++st, --ed)
            std::swap(s[st], s[ed]);
    }

    string reverseWords(string s) {
        if (s.empty())
            return s;

        int st = 0, ed;

        do
        {
            for (ed = st; ed < s.size() && s[ed] != ' '; ++ed)
                ;
            reverse(s, st, ed - 1);
            st = ed + 1;
        }
        while (st < s.size());

        return s;
    }
};
