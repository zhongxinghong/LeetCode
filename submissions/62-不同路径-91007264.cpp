/**
 * Submission ID: 91007264
 * Question ID: 62
 * Question Title: 不同路径
 * Question URL: https://leetcode-cn.com/problems/unique-paths/
 * Solution Time: 2020-07-24 13:53:37
 * Solution Test Result: 62 / 62
 * Solution Status: Accepted
 * Solution Memory: 5.9 MB
 * Solution Runtime: 0 ms
 */

class Solution {
public:
    int uniquePaths(int m, int n)
    {
        int i;
        double s = 1.0;

        if (n > m)
            std::swap(n, m);

        for (i = 1; i < n; ++i)
        {
            s *= (m - 1 + i);
            s /= i;
        }

        return s;
    }
};
