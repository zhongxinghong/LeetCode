/**
 * Submission ID: 86723378
 * Question ID: 1
 * Question Title: 两数之和
 * Question URL: https://leetcode-cn.com/problems/two-sum/
 * Solution Time: 2020-07-11 11:25:18
 * Solution Test Result: 29 / 29
 * Solution Status: Accepted
 * Solution Memory: 7.2 MB
 * Solution Runtime: 684 ms
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> ret;
        for (size_t i = 0; i < nums.size() - 1; ++i)
        {
            for (size_t j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] + nums[j] == target)
                {
                    ret.push_back(i);
                    ret.push_back(j);
                }
            }
        }
        return ret;
    }
};
