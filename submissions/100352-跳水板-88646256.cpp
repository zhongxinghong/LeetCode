/**
 * Submission ID: 88646256
 * Question ID: 100352
 * Question Title: 跳水板
 * Question URL: https://leetcode-cn.com/problems/diving-board-lcci/
 * Solution Time: 2020-07-17 13:15:47
 * Solution Test Result: 60 / 60
 * Solution Status: Accepted
 * Solution Memory: 20.3 MB
 * Solution Runtime: 20 ms
 */

class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        std::vector<int> ret;
        int i, st = k * shorter, ed = k * longer, di = longer - shorter;

        if (st == ed)
        {
            if (k > 0)
                ret.push_back(st);
            return ret;
        }

        for (i = st; i <= ed; i += di)
            ret.push_back(i);

        return ret;
    }
};
