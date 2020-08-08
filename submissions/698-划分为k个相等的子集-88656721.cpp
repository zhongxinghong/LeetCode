/**
 * Submission ID: 88656721
 * Question ID: 698
 * Question Title: 划分为k个相等的子集
 * Question URL: https://leetcode-cn.com/problems/partition-to-k-equal-sum-subsets/
 * Solution Time: 2020-07-17 14:05:33
 * Solution Test Result: 149 / 149
 * Solution Status: Accepted
 * Solution Memory: 9.3 MB
 * Solution Runtime: 4 ms
 */

class Solution {
public:

    bool dfs(const std::vector<int> &nums, std::vector<int> &bucket, int k, int cur)
    {
        if (cur < 0)
            return true;

        for (int i = 0; i < k; ++i)
        {
            if (bucket[i] == nums[cur] || bucket[i] - nums[cur] >= nums[0])
            {
                bucket[i] -= nums[cur];
                if (dfs(nums, bucket, k, cur - 1))
                    return true;
                bucket[i] += nums[cur];
            }
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (k == 1)
            return true;

        int sum = 0;

        for (int i = 0; i < nums.size(); ++i)
            sum += nums[i];

        if (sum % k)
            return false;

        sum /= k;

        std::sort(nums.begin(), nums.end());

        if (nums.back() > sum)
            return false;

        std::vector<int> bucket(k, sum);

        return dfs(nums, bucket, k, nums.size() - 1);
    }
};
