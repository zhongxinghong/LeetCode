/**
 * Submission ID: 90678992
 * Question ID: 47
 * Question Title: 全排列 II
 * Question URL: https://leetcode-cn.com/problems/permutations-ii/
 * Solution Time: 2020-07-23 14:13:24
 * Solution Test Result: 30 / 30
 * Solution Status: Accepted
 * Solution Memory: 7.7 MB
 * Solution Runtime: 8 ms
 */

class Solution {
public:

    void dfs(
        const std::vector<int> &nums,
        std::unordered_map<int, int> &cnt,
        std::vector<std::vector<int>> &ret,
        std::vector<int> &tmp,
        int ix)
    {
        int i, n = nums.size();

        if (ix == n)
        {
            ret.push_back(tmp);
            return;
        }

        for (auto it = cnt.begin(); it != cnt.end(); ++it)
        {
            if (it->second == 0)
                continue;

            it->second--;
            tmp[ix] = it->first;

            dfs(nums, cnt, ret, tmp, ix + 1);

            it->second++;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        int i, n = nums.size();
        std::unordered_map<int, int> cnt;
        std::vector<std::vector<int>> ret;
        std::vector<int> tmp(n);

        for (i = 0; i < n; ++i)
            cnt[nums[i]]++;

        dfs(nums, cnt, ret, tmp, 0);

        return ret;
    }
};
