/**
 * Submission ID: 89898679
 * Question ID: 770
 * Question Title: 情侣牵手
 * Question URL: https://leetcode-cn.com/problems/couples-holding-hands/
 * Solution Time: 2020-07-21 10:38:31
 * Solution Test Result: 56 / 56
 * Solution Status: Accepted
 * Solution Memory: 7.5 MB
 * Solution Runtime: 4 ms
 */

class Solution {
public:
    int minSwapsCouples(vector<int>& row)
    {
        int i, j, k, x, y, n = row.size(), cnt = 0;

        for (i = 0; i < n; i += 2)
        {
            x = row[i];

            if (x % 2 == 0)
                y = x + 1;
            else
                y = x - 1;

            if (row[i + 1] == y)
                continue;

            for (k = i + 2; k < n && row[k] != y; ++k)
                ;

            std::swap(row[i + 1], row[k]);
            cnt++;
        }

        return cnt;
    }
};
