/**
 * Submission ID: 88575486
 * Question ID: 338
 * Question Title: 比特位计数
 * Question URL: https://leetcode-cn.com/problems/counting-bits/
 * Solution Time: 2020-07-17 09:35:26
 * Solution Test Result: 15 / 15
 * Solution Status: Accepted
 * Solution Memory: 8 MB
 * Solution Runtime: 4 ms
 */

class Solution {
public:
    vector<int> countBits(int num) {
        std::vector<int> ret(num + 1);
        ret[0] = 0;

        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i >> 1] + (i & 0x1);

        return ret;
    }
};
