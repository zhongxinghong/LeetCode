/**
 * Submission ID: 91328781
 * Question ID: 76
 * Question Title: 最小覆盖子串
 * Question URL: https://leetcode-cn.com/problems/minimum-window-substring/
 * Solution Time: 2020-07-25 16:37:55
 * Solution Test Result: 268 / 268
 * Solution Status: Accepted
 * Solution Memory: 8.9 MB
 * Solution Runtime: 56 ms
 */

class Solution {
public:

    string minWindow(string s, string t)
    {
        if (s.empty() || t.empty())
            return "";

        int i, st = -1, sz, len;
        std::unordered_map<char, int> tcnt, tcnttmp, cnt;
        std::deque<int> dq;

        for (i = 0; i < t.size(); ++i)
            tcnt[t[i]]++;

        tcnttmp = tcnt;
        sz = tcnt.size();

        for (i = 0; i < s.size(); ++i)
        {
            if (sz != 0)
            {
                auto it = tcnttmp.find(s[i]);

                if (it == tcnttmp.end())
                    continue;

                dq.push_back(i);
                cnt[s[i]]++;

                if (--it->second == 0)
                {
                    if (--sz == 0)
                    {
                        while ((it = cnt.find(s[dq.front()]))->second > tcnt[s[dq.front()]])
                        {
                            dq.pop_front();
                            it->second--;
                        }

                        st = dq.front();
                        len = i - st + 1;
                    }
                }
            }
            else
            {
                auto it = cnt.find(s[i]);

                if (it == cnt.end())
                    continue;

                dq.push_back(i);
                it->second++;

                while ((it = cnt.find(s[dq.front()]))->second > tcnt[s[dq.front()]])
                {
                    dq.pop_front();
                    it->second--;
                }

                if (i - dq.front() + 1 < len)
                {
                    st = dq.front();
                    len = i - st + 1;
                }
            }
        }

        return st == -1 ? "" : s.substr(st, len);
    }
};
