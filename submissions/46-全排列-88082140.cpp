/**
 * Submission ID: 88082140
 * Question ID: 46
 * Question Title: 全排列
 * Question URL: https://leetcode-cn.com/problems/permutations/
 * Solution Time: 2020-07-15 16:43:08
 * Solution Test Result: 25 / 25
 * Solution Status: Accepted
 * Solution Memory: 7.3 MB
 * Solution Runtime: 4 ms
 */

class Solution {
public:

    void dfs_build(
        std::vector<std::vector<int> > &ret,
        std::vector<int> &nums,
        std::vector<int> &tmp,
        std::vector<bool> &mask)
    {
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (mask[i])
                continue;

            mask[i] = true;
            tmp.push_back(nums[i]);

            if (tmp.size() == nums.size())
                ret.push_back(tmp);
            else
                dfs_build(ret, nums, tmp, mask);

            tmp.pop_back();
            mask[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int> > ret;
        std::vector<int> tmp;
        std::vector<bool> mask(nums.size(), false);

        dfs_build(ret, nums, tmp, mask);

        return ret;
    }
};
