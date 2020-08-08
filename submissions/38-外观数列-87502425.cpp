/**
 * Submission ID: 87502425
 * Question ID: 38
 * Question Title: 外观数列
 * Question URL: https://leetcode-cn.com/problems/count-and-say/
 * Solution Time: 2020-07-13 21:41:36
 * Solution Test Result: 18 / 18
 * Solution Status: Accepted
 * Solution Memory: 6.7 MB
 * Solution Runtime: 4 ms
 */

class Solution {
public:
    string countAndSay(int n) {
        int cnt, i, j;
        char c;
        std::string s = "1";
        std::stringstream ss;

        for (j = 1; j < n; ++j)
        {
            ss.clear();
            ss.str("");

            cnt = 1;
            c = s[0];

            for (i = 1; i < s.size(); ++i)
            {
                if (s[i] == c)
                {
                    ++cnt;
                }
                else
                {
                    ss << cnt << c;
                    cnt = 1;
                    c = s[i];
                }
            }

            ss << cnt << c;

            s = ss.str();
        }

        return s;
    }
};
