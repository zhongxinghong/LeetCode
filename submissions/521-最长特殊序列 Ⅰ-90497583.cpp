/**
 * Submission ID: 90497583
 * Question ID: 521
 * Question Title: 最长特殊序列 Ⅰ
 * Question URL: https://leetcode-cn.com/problems/longest-uncommon-subsequence-i/
 * Solution Time: 2020-07-22 22:15:53
 * Solution Test Result: 39 / 39
 * Solution Status: Accepted
 * Solution Memory: 6.1 MB
 * Solution Runtime: 4 ms
 */

class Solution {
public:
    int findLUSlength(string a, string b) {
        return a == b ? -1 : std::max(a.size(), b.size());
    }
};
