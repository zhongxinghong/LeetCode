/**
 * Submission ID: 89068601
 * Question ID: 494
 * Question Title: 目标和
 * Question URL: https://leetcode-cn.com/problems/target-sum/
 * Solution Time: 2020-07-18 17:58:26
 * Solution Test Result: 139 / 139
 * Solution Status: Accepted
 * Solution Memory: 9 MB
 * Solution Runtime: 1832 ms
 */

class Solution {
public:

    void dfs(const std::vector<int> &nums, const int &S, int ix, int sum, int &cnt)
    {
        if (ix == nums.size())
        {
            if (sum == S)
                cnt++;
            return;
        }

        dfs(nums, S, ix + 1, sum + nums[ix], cnt);
        dfs(nums, S, ix + 1, sum - nums[ix], cnt);
    }

    int findTargetSumWays(vector<int>& nums, int S)
    {
        int i, sum = 0, cnt = 0;
        for (i = 0; i < nums.size(); ++i)
            sum += nums[i];

        if (sum < S)
            return 0;

        dfs(nums, S, 0, 0, cnt);
        return cnt;
    }
};
