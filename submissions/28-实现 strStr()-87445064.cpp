/**
 * Submission ID: 87445064
 * Question ID: 28
 * Question Title: 实现 strStr()
 * Question URL: https://leetcode-cn.com/problems/implement-strstr/
 * Solution Time: 2020-07-13 18:30:21
 * Solution Test Result: 74 / 74
 * Solution Status: Accepted
 * Solution Memory: 6.9 MB
 * Solution Runtime: 4 ms
 */

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;

        if (needle.size() > haystack.size())
            return -1;

        for (int i = 0; i < haystack.size() - needle.size() + 1; ++i)
        {
            for (int j = 0; j < needle.size(); ++j)
            {
                if (haystack[i + j] != needle[j])
                    goto FAILED;
            }
            return i;

        FAILED:
            continue;
        }

        return -1;
    }
};
