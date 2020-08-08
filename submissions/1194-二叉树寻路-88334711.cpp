/**
 * Submission ID: 88334711
 * Question ID: 1194
 * Question Title: 二叉树寻路
 * Question URL: https://leetcode-cn.com/problems/path-in-zigzag-labelled-binary-tree/
 * Solution Time: 2020-07-16 13:52:41
 * Solution Test Result: 44 / 44
 * Solution Status: Accepted
 * Solution Memory: 6.2 MB
 * Solution Runtime: 4 ms
 */

class Solution {
public:

    int getExp(int x)
    {
        int i;
        for (i = -1; x; ++i, x >>= 1)
            ;
        return i;
    }

    vector<int> pathInZigZagTree(int label) {
        int exp;
        std::vector<int> ret;

        for (;;)
        {
            ret.push_back(label);
            if (label == 1)
                break;

            exp = getExp(label);
            label = (1 << exp) + (1 << (exp - 1)) - 1 - (label >> 1);
        }

        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};
