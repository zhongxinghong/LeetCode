/**
 * Submission ID: 86858993
 * Question ID: 18
 * Question Title: 四数之和
 * Question URL: https://leetcode-cn.com/problems/4sum/
 * Solution Time: 2020-07-11 20:26:34
 * Solution Test Result: 282 / 282
 * Solution Status: Accepted
 * Solution Memory: 7.4 MB
 * Solution Runtime: 128 ms
 */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int i, j, k, m, n = nums.size(), s;
        std::vector<std::vector<int> > ret;
        std::vector<int> v(4, 0);

        if (nums.size() < 4)
            return ret;

        std::sort(nums.begin(), nums.end());

        for (k = 0; k < n - 3; ++k)
        {
            // if (nums[k] > target)
            //     break;

            if (k > 0 && nums[k - 1] == nums[k])
                continue;

            for (m = k + 1; m < n - 2; ++m)
            {
                // if (nums[m] > target)
                //     break;

                if (m > k + 1 && nums[m - 1] == nums[m])
                    continue;

                i = m + 1;
                j = n - 1;

                while (i < j)
                {
                    s = nums[i] + nums[j] + nums[k] + nums[m];

                    if (s == target)
                    {
                        v[0] = nums[k];
                        v[1] = nums[m];
                        v[2] = nums[i];
                        v[3] = nums[j];
                        ret.push_back(v);

                        while (i < j && nums[i + 1] == nums[i])
                            ++i;

                        while (i < j && nums[j - 1] == nums[j])
                            --j;

                        ++i;
                        --j;
                    }
                    else if (s < target)
                        ++i;
                    else
                        --j;
                }
            }
        }

        return ret;
    }
};
