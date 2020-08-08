/**
 * Submission ID: 88640120
 * Question ID: 392
 * Question Title: 判断子序列
 * Question URL: https://leetcode-cn.com/problems/is-subsequence/
 * Solution Time: 2020-07-17 12:40:16
 * Solution Test Result: 15 / 15
 * Solution Status: Accepted
 * Solution Memory: 6.5 MB
 * Solution Runtime: 4 ms
 */

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (i < s.size() && j < t.size())
        {
            if (s[i] == t[j])
                i++;
            j++;
        }
        return i == s.size();
    }
};
