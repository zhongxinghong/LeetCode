/**
 * Submission ID: 88335058
 * Question ID: 1194
 * Question Title: 二叉树寻路
 * Question URL: https://leetcode-cn.com/problems/path-in-zigzag-labelled-binary-tree/
 * Solution Time: 2020-07-16 13:54:20
 * Solution Test Result: 44 / 44
 * Solution Status: Accepted
 * Solution Memory: 6.4 MB
 * Solution Runtime: 0 ms
 */

class Solution {
public:

    vector<int> pathInZigZagTree(int label) {
        int exp;
        std::vector<int> ret;

        for (;;)
        {
            ret.push_back(label);
            if (label == 1)
                break;

            exp = log2(label);
            label = (1 << exp) + (1 << (exp - 1)) - 1 - (label >> 1);
        }

        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};
