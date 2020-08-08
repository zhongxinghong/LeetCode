/**
 * Submission ID: 91681200
 * Question ID: 551
 * Question Title: 学生出勤记录 I
 * Question URL: https://leetcode-cn.com/problems/student-attendance-record-i/
 * Solution Time: 2020-07-26 20:13:36
 * Solution Test Result: 113 / 113
 * Solution Status: Accepted
 * Solution Memory: 6.2 MB
 * Solution Runtime: 0 ms
 */

class Solution {
public:
    bool checkRecord(string s)
    {
        int i, n = s.size(), Acnt = 0, Lcnt = 0;

        for (i = 0; i < n; ++i)
        {
            if (s[i] == 'A' && Acnt++ == 1)
                return false;

            if (s[i] == 'L')
            {
                if (Lcnt++ == 2)
                    return false;
            }
            else
            {
                Lcnt = 0;
            }
        }

        return true;
    }
};
