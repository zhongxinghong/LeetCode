/**
 * Submission ID: 90594299
 * Question ID: 241
 * Question Title: 为运算表达式设计优先级
 * Question URL: https://leetcode-cn.com/problems/different-ways-to-add-parentheses/
 * Solution Time: 2020-07-23 09:58:58
 * Solution Test Result: 25 / 25
 * Solution Status: Accepted
 * Solution Memory: 7.1 MB
 * Solution Runtime: 4 ms
 */

class Solution {
public:

    void dfs(
        std::vector<char> &ops,
        std::vector<int> &nums,
        std::vector<std::vector<std::vector<int>>> &f,
        int st,
        int ed)
    {
        if (!f[st][ed].empty())
            return;

        if (st == ed)
        {
            f[st][ed].push_back(nums[st]);
            return;
        }

        int i, j, k;

        for (k = st; k < ed; ++k)
        {
            dfs(ops, nums, f, st, k);
            dfs(ops, nums, f, k + 1, ed);

            const auto &v1 = f[st][k];
            const auto &v2 = f[k + 1][ed];

            for (i = 0; i < v1.size(); ++i)
            {
                for (j = 0; j < v2.size(); ++j)
                {
                    switch (ops[k])
                    {
                    case '+':
                        f[st][ed].push_back(v1[i] + v2[j]);
                        break;
                    case '-':
                        f[st][ed].push_back(v1[i] - v2[j]);
                        break;
                    case '*':
                        f[st][ed].push_back(v1[i] * v2[j]);
                        break;
                    }
                }
            }
        }
    }

    std::vector<int> diffWaysToCompute(std::string input)
    {
        int i, n = input.size(), d = 0;
        std::vector<char> ops;
        std::vector<int> nums;

        for (i = 0; i < n; ++i)
        {
            if (input[i] >= '0' && input[i] <= '9')
            {
                d = d * 10 + input[i] - '0';
            }
            else
            {
                nums.push_back(d);
                ops.push_back(input[i]);
                d = 0;
            }
        }

        nums.push_back(d);

        n = nums.size();
        std::vector<std::vector<std::vector<int>>> f(n, std::vector<std::vector<int>>(n));

        dfs(ops, nums, f, 0, n - 1);

        return f[0][n - 1];
    }
};
