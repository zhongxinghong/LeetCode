/**
 * Submission ID: 86833617
 * Question ID: 15
 * Question Title: 三数之和
 * Question URL: https://leetcode-cn.com/problems/3sum/
 * Solution Time: 2020-07-11 18:19:48
 * Solution Test Result: 313 / 313
 * Solution Status: Accepted
 * Solution Memory: 23.6 MB
 * Solution Runtime: 3364 ms
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i, j;
        std::set<std::vector<int> > ret;
        std::vector<int> v(3, 0);

        std::sort(nums.begin(), nums.end());

        for (i = 0; i + 2 < nums.size(); ++i)
        {
            for (j = i + 1; j + 1 < nums.size(); ++j)
            {
                if (nums[i] + nums[j] * 2 > 0)
                    break;

                if (binary_search(&nums[j + 1], &nums.back() + 1, -(nums[i] + nums[j])))
                {
                    v[0] = nums[i]; v[1] = nums[j]; v[2] = -(v[0] + v[1]);
                    ret.insert(v);
                }
            }
        }

        return std::vector<std::vector<int> >(ret.begin(), ret.end());
    }
};
