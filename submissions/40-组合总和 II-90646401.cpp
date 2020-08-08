/**
 * Submission ID: 90646401
 * Question ID: 40
 * Question Title: 组合总和 II
 * Question URL: https://leetcode-cn.com/problems/combination-sum-ii/
 * Solution Time: 2020-07-23 12:05:47
 * Solution Test Result: 172 / 172
 * Solution Status: Accepted
 * Solution Memory: 8.3 MB
 * Solution Runtime: 24 ms
 */

class Solution {
public:

    void dfs(
        const std::vector<int> &nums,
        std::vector<std::vector<int>> &ret,
        std::vector<int> &tmp,
        int bucket,
        int pos)
    {
        if (bucket == 0)
        {
            ret.push_back(tmp);
            return;
        }

        int i, n = nums.size();

        if (pos == n)
            return;

        for (i = pos; i < n; ++i)
        {
            if (bucket == nums[i] || bucket - nums[i] >= nums[0])
            {
                tmp.push_back(nums[i]);
                dfs(nums, ret, tmp, bucket - nums[i], i + 1);
                tmp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        std::vector<std::vector<int>> ret;
        std::vector<int> tmp;

        std::sort(candidates.begin(), candidates.end());

        if (candidates.empty() || candidates.front() > target)
            return ret;

        dfs(candidates, ret, tmp, target, 0);

        std::sort(ret.begin(), ret.end());
        ret.erase(std::unique(ret.begin(), ret.end()), ret.end());

        return ret;
    }
};
