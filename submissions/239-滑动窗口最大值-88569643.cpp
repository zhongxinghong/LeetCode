/**
 * Submission ID: 88569643
 * Question ID: 239
 * Question Title: 滑动窗口最大值
 * Question URL: https://leetcode-cn.com/problems/sliding-window-maximum/
 * Solution Time: 2020-07-17 09:16:49
 * Solution Test Result: 18 / 18
 * Solution Status: Accepted
 * Solution Memory: 28.3 MB
 * Solution Runtime: 96 ms
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> ret;
        std::deque<int> dq;
        int i;

        for (i = 0; i < nums.size(); ++i)
        {
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.push_back(i);

            if (i < k - 1)
                continue;

            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            ret.push_back(nums[dq.front()]);
        }

        return ret;
    }
};
