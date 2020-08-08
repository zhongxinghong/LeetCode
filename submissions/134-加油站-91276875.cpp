/**
 * Submission ID: 91276875
 * Question ID: 134
 * Question Title: 加油站
 * Question URL: https://leetcode-cn.com/problems/gas-station/
 * Solution Time: 2020-07-25 13:41:59
 * Solution Test Result: 31 / 31
 * Solution Status: Accepted
 * Solution Memory: 10 MB
 * Solution Runtime: 16 ms
 */

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int n = gas.size(), i, j = -1, rem = -1;
        gas.insert(gas.end(), gas.begin(), gas.end());

        while (j < n * 2)
        {
            if (rem < 0)
            {
                i = ++j;

                if (j == n * 2)
                    break;

                rem = gas[j] - cost[j % n];
                continue;
            }

            if (j - i == n)
                return i;

            j++;

            if (j == n * 2)
                break;

            rem += gas[j] - cost[j % n];
        }

        return -1;
    }
};
