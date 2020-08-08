/**
 * Submission ID: 91298859
 * Question ID: 3
 * Question Title: 无重复字符的最长子串
 * Question URL: https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
 * Solution Time: 2020-07-25 15:20:54
 * Solution Test Result: 987 / 987
 * Solution Status: Accepted
 * Solution Memory: 7.7 MB
 * Solution Runtime: 8 ms
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty())
            return 0;

        int n = s.size(), st = 0, ed, ret = 1;
        std::vector<int> mp(128, -1);

        mp[s[st]] = st;

        for (ed = 1; ed < n; ++ed)
        {
            if (mp[s[ed]] != -1 && mp[s[ed]] + 1 > st)
                st = mp[s[ed]] + 1;

            mp[s[ed]] = ed;

            ret = std::max(ret, ed - st + 1);
        }

        return ret;
    }
};
