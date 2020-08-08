/**
 * Submission ID: 86837169
 * Question ID: 15
 * Question Title: 三数之和
 * Question URL: https://leetcode-cn.com/problems/3sum/
 * Solution Time: 2020-07-11 18:36:10
 * Solution Test Result: 313 / 313
 * Solution Status: Accepted
 * Solution Memory: 19.7 MB
 * Solution Runtime: 128 ms
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i, j, k, s, n = nums.size();
        std::vector<std::vector<int> > ret;
        std::vector<int> v(3, 0);

        if (n < 3)
            return ret;

        std::sort(nums.begin(), nums.end());

        for (k = 0; k < n - 2; ++k)
        {
            if (nums[k] > 0)
                break;

            if (k > 0 && nums[k - 1] == nums[k])
                continue;

            i = k + 1;
            j = n - 1;

            while (i < j)
            {
                s = nums[i] + nums[j] + nums[k];

                if (s == 0)
                {
                    v[0] = nums[k];
                    v[1] = nums[i];
                    v[2] = nums[j];
                    ret.push_back(v);

                    while (i < j && nums[i] == nums[i + 1])
                        ++i;

                    while (i < j && nums[j - 1] == nums[j])
                        --j;

                    ++i;
                    --j;
                }
                else if (s > 0)
                    --j;
                else
                    ++i;
            }
        }

        return ret;
    }
};
