/**
 * Submission ID: 88903557
 * Question ID: 473
 * Question Title: 火柴拼正方形
 * Question URL: https://leetcode-cn.com/problems/matchsticks-to-square/
 * Solution Time: 2020-07-18 09:25:42
 * Solution Test Result: 174 / 174
 * Solution Status: Accepted
 * Solution Memory: 9.7 MB
 * Solution Runtime: 16 ms
 */

class Solution {
public:

    bool dfs(const std::vector<int> &nums, std::vector<int> &buckets, int cur)
    {
        if (cur < 0)
            return true;

        for (int i = 0; i < buckets.size(); ++i)
        {
            if (buckets[i] == nums[cur] || cur != 0 && buckets[i] - nums[cur] >= nums[0])
            {
                buckets[i] -= nums[cur];
                if (dfs(nums, buckets, cur - 1))
                    return true;
                buckets[i] += nums[cur];
            }
        }

        return false;
    }

    bool makesquare(vector<int>& nums)
    {
        if (nums.size() < 4)
            return false;

        int sum = 0;

        for (int i = 0; i < nums.size(); ++i)
            sum += nums[i];

        if (sum % 4)
            return false;

        sum /= 4;

        std::sort(nums.begin(), nums.end());

        if (nums.back() > sum)
            return false;

        std::vector<int> buckets(4, sum);

        return dfs(nums, buckets, nums.size() - 1);
    }
};
