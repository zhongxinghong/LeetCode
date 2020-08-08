/**
 * Submission ID: 90806562
 * Question ID: 1503
 * Question Title: 做菜顺序
 * Question URL: https://leetcode-cn.com/problems/reducing-dishes/
 * Solution Time: 2020-07-23 20:26:17
 * Solution Test Result: 59 / 59
 * Solution Status: Accepted
 * Solution Memory: 6.7 MB
 * Solution Runtime: 8 ms
 */

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction)
    {
        int n = satisfaction.size(), i, j, ret = 0, sum = 0;

        std::sort(satisfaction.begin(), satisfaction.end());

        for (i = n - 1; i != -1; --i)
        {
            for (j = i; j < n; ++j)
                sum += satisfaction[j];

            ret = std::max(ret, sum);
        }

        return ret;
    }
};
