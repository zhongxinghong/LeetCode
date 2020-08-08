/**
 * Submission ID: 86847345
 * Question ID: 16
 * Question Title: 最接近的三数之和
 * Question URL: https://leetcode-cn.com/problems/3sum-closest/
 * Solution Time: 2020-07-11 19:31:35
 * Solution Test Result: 131 / 131
 * Solution Status: Accepted
 * Solution Memory: 10 MB
 * Solution Runtime: 12 ms
 */

class Solution {
public:

    int iabs(int x)
    {
        return x < 0 ? -x : x;
    }

    int threeSumClosest(vector<int>& nums, int target) {
        int i, j, k, n = nums.size(), s, dist = (1 << 30), ret = -1;

        std::sort(nums.begin(), nums.end());

        for (k = 0; k < n - 2; ++k)
        {
            i = k + 1;
            j = n - 1;

            while (i < j)
            {
                s = nums[i] + nums[j] + nums[k];

                if (s == target)
                    return s;

                if (iabs(s - target) < dist)
                {
                    dist = iabs(s - target);
                    ret = s;
                }

                if (s < target)
                    ++i;

                if (s > target)
                    --j;
            }
        }

        return ret;
    }
};
