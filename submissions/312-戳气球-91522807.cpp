/**
 * Submission ID: 91522807
 * Question ID: 312
 * Question Title: 戳气球
 * Question URL: https://leetcode-cn.com/problems/burst-balloons/
 * Solution Time: 2020-07-26 10:57:10
 * Solution Test Result: 70 / 70
 * Solution Status: Accepted
 * Solution Memory: 8.8 MB
 * Solution Runtime: 48 ms
 */

class Solution {
public:

    int dfs(
        std::vector<std::vector<int>> &f,
        const std::vector<int> &nums,
        int st,
        int ed)
    {
        if (f[st][ed] != -1)
            return f[st][ed];

        if (st + 2 > ed)
            return f[st][ed] = 0;

        int k, coins, max_coins = -1;

        for (k = st + 1; k < ed; ++k)
        {
            coins = dfs(f, nums, st, k) + dfs(f, nums, k, ed)
                    + nums[st] * nums[k] * nums[ed];

            if (coins > max_coins)
                max_coins = coins;
        }

        return f[st][ed] = max_coins;
    }

    int maxCoins(vector<int>& nums)
    {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);

        int n = nums.size();
        std::vector<std::vector<int>> f(n, std::vector<int>(n, -1));

        return dfs(f, nums, 0, n - 1);
    }
};
