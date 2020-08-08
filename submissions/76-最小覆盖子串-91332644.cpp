/**
 * Submission ID: 91332644
 * Question ID: 76
 * Question Title: 最小覆盖子串
 * Question URL: https://leetcode-cn.com/problems/minimum-window-substring/
 * Solution Time: 2020-07-25 16:47:56
 * Solution Test Result: 268 / 268
 * Solution Status: Accepted
 * Solution Memory: 8.8 MB
 * Solution Runtime: 68 ms
 */

class Solution {
public:

    string minWindow(string s, string t)
    {
        if (s.empty() || t.empty())
            return "";

        int i, st = -1, sz, len;
        std::unordered_set<char> tset;
        std::unordered_map<char, int> tcnt, dqcnt;
        std::deque<int> dq;

        for (i = 0; i < t.size(); ++i)
        {
            tset.insert(t[i]);
            tcnt[t[i]]++;
            dqcnt[t[i]] = 0;
        }

        for (i = 0; i < s.size(); ++i)
        {
            auto it = dqcnt.find(s[i]);

            if (it == dqcnt.end())
                continue;

            dq.push_back(i);
            it->second++;

            if (!tset.empty() && it->second == tcnt[s[i]])
            {
                tset.erase(tset.find(s[i]));

                if (tset.empty())
                {
                    st = dq.front();
                    len = i - st + 1;
                }
            }

            if (!tset.empty())
                continue;

            while ((it = dqcnt.find(s[dq.front()]))->second > tcnt[s[dq.front()]])
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

        return st == -1 ? "" : s.substr(st, len);
    }
};
