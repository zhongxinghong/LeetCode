/**
 * Submission ID: 88651775
 * Question ID: 1236
 * Question Title: 第 N 个泰波那契数
 * Question URL: https://leetcode-cn.com/problems/n-th-tribonacci-number/
 * Solution Time: 2020-07-17 13:43:40
 * Solution Test Result: 39 / 39
 * Solution Status: Accepted
 * Solution Memory: 6.4 MB
 * Solution Runtime: 0 ms
 */

class Solution {
public:

    int tribonacci(int n)
    {
        if (n < f.size())
            return f[n];

        f.push_back(tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3));
        return f[n];
    }

private:
    std::vector<int> f = {0, 1, 1};
};
