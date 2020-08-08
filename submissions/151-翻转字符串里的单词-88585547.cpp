/**
 * Submission ID: 88585547
 * Question ID: 151
 * Question Title: 翻转字符串里的单词
 * Question URL: https://leetcode-cn.com/problems/reverse-words-in-a-string/
 * Solution Time: 2020-07-17 10:02:39
 * Solution Test Result: 25 / 25
 * Solution Status: Accepted
 * Solution Memory: 7.5 MB
 * Solution Runtime: 12 ms
 */

class Solution {
public:

    void reverse(std::string &s, int st, int ed)
    {
        for (; st < ed; ++st, --ed)
            std::swap(s[st], s[ed]);
    }

    string reverseWords(string s) {
        int i, n, st, ed;

        if (s.empty())
            return s;

        for (i = 0, n = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ' && (n == 0 || s[n - 1] == ' '))
                continue;
            s[n++] = s[i];
        }

        if (n > 0 && s[n - 1] == ' ')
            n--;

        s.resize(n);

        st = 0;
        do
        {
            for (ed = st + 1; ed < s.size() && s[ed] != ' '; ++ed)
                ;

            reverse(s, st, ed - 1);
            st = ed + 1;
        }
        while (st < s.size());

        std::reverse(s.begin(), s.end());
        return s;
    }
};
