/**
 * Submission ID: 90495268
 * Question ID: 742
 * Question Title: 转换成小写字母
 * Question URL: https://leetcode-cn.com/problems/to-lower-case/
 * Solution Time: 2020-07-22 22:10:01
 * Solution Test Result: 8 / 8
 * Solution Status: Accepted
 * Solution Memory: 6.1 MB
 * Solution Runtime: 0 ms
 */

class Solution {
public:
    string toLowerCase(string str) {
        int i, n = str.size();
        for (i = 0; i < n; ++i)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
                str[i] -= ('A' - 'a');
        }
        return str;
    }
};
