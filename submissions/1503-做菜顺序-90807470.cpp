/**
 * Submission ID: 90807470
 * Question ID: 1503
 * Question Title: 做菜顺序
 * Question URL: https://leetcode-cn.com/problems/reducing-dishes/
 * Solution Time: 2020-07-23 20:28:53
 * Solution Test Result: 59 / 59
 * Solution Status: Accepted
 * Solution Memory: 6.9 MB
 * Solution Runtime: 4 ms
 */

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction)
    {
        int n = satisfaction.size(), i, ret = 0, sum = 0;
        std::vector<int> cumsum(n);

        std::sort(satisfaction.begin(), satisfaction.end());

        cumsum[n - 1] = satisfaction[n - 1];

        for (i = n - 1; i != 0; --i)
            cumsum[i - 1] = cumsum[i] + satisfaction[i - 1];

        for (i = n - 1; i != -1; --i)
        {
            sum += cumsum[i];
            ret = std::max(ret, sum);
        }

        return ret;
    }
};
