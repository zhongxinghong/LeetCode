/**
 * Submission ID: 91277668
 * Question ID: 134
 * Question Title: 加油站
 * Question URL: https://leetcode-cn.com/problems/gas-station/
 * Solution Time: 2020-07-25 13:46:33
 * Solution Test Result: 31 / 31
 * Solution Status: Accepted
 * Solution Memory: 10 MB
 * Solution Runtime: 8 ms
 */

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int n = gas.size(), i = 0, j = 0, rem = 0;
        gas.insert(gas.end(), gas.begin(), gas.end());

        for (j = 0; j < n * 2; ++j)
        {
            rem += gas[j] - cost[j % n];

            if (rem < 0)
            {
                i = j + 1;
                rem = 0;
            }

            if (j - i == n)
                return i;
        }

        return -1;
    }
};
