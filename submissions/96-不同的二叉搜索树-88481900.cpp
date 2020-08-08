/**
 * Submission ID: 88481900
 * Question ID: 96
 * Question Title: 不同的二叉搜索树
 * Question URL: https://leetcode-cn.com/problems/unique-binary-search-trees/
 * Solution Time: 2020-07-16 21:22:42
 * Solution Test Result: 19 / 19
 * Solution Status: Accepted
 * Solution Memory: 6.2 MB
 * Solution Runtime: 0 ms
 */

class Solution {
public:

    int __numTrees(std::vector<int> &f, int n)
    {
        if (f[n] != -1)
            return f[n];

        if (n == 0 || n == 1)
            return (f[n] = 1);

        int sum = 0;

        for (int i = 0; i < n; ++i)
            sum += __numTrees(f, i) * __numTrees(f, n - 1 - i);

        return (f[n] = sum);
    }

    int numTrees(int n) {
        std::vector<int> f(n + 1, -1);
        return __numTrees(f, n);
    }
};
