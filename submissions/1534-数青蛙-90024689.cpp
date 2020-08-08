/**
 * Submission ID: 90024689
 * Question ID: 1534
 * Question Title: 数青蛙
 * Question URL: https://leetcode-cn.com/problems/minimum-number-of-frogs-croaking/
 * Solution Time: 2020-07-21 16:52:50
 * Solution Test Result: 55 / 55
 * Solution Status: Accepted
 * Solution Memory: 9.2 MB
 * Solution Runtime: 44 ms
 */

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs)
    {
        int i, n = croakOfFrogs.size(), cur = 0, maxi = -1;
        std::vector<int> v(4, 0);

        if (n % 5 != 0)
            return -1;

        for (i = 0; i < n; ++i)
        {
            switch (croakOfFrogs[i])
            {
            case 'c':
                v[0]++;
                maxi = std::max(++cur, maxi);
                break;
            case 'r':
                if (v[0] == 0)
                    return -1;
                v[0]--;
                v[1]++;
                break;
            case 'o':
                if (v[1] == 0)
                    return -1;
                v[1]--;
                v[2]++;
                break;
            case 'a':
                if (v[2] == 0)
                    return -1;
                v[2]--;
                v[3]++;
                break;
            case 'k':
                if (v[3] == 0)
                    return -1;
                v[3]--;
                cur--;
                break;
            }
        }

        if (cur != 0)
            return -1;

        return maxi;
    }
};
