/**
 * Submission ID: 89914883
 * Question ID: 1456
 * Question Title: 阈值距离内邻居最少的城市
 * Question URL: https://leetcode-cn.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
 * Solution Time: 2020-07-21 11:11:01
 * Solution Test Result: 52 / 52
 * Solution Status: Accepted
 * Solution Memory: 10.7 MB
 * Solution Runtime: 104 ms
 */

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
    {
        static const int INF = 1 << 24;

        int i, j, k, mincnt = INF, minix = -1;
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, INF));
        std::vector<int> cnt(n, 0);

        for (i = 0; i < edges.size(); ++i)
        {
            dp[edges[i][0]][edges[i][1]] = edges[i][2];
            dp[edges[i][1]][edges[i][0]] = edges[i][2];
        }

        for (i = 0; i < n; ++i)
            dp[i][i] = 0;

        for (k = 0; k < n; ++k)
        {
            for (i = 0; i < n; ++i)
            {
                for (j = 0; j < n; ++j)
                {
                    if (dp[i][j] > dp[i][k] + dp[k][j])
                    {
                        dp[i][j] = dp[j][i] = dp[i][k] + dp[k][j];
                    }
                }
            }
        }

        for (i = 0; i < n - 1; ++i)
        {
            for (j = i + 1; j < n; ++j)
            {
                if (dp[i][j] > distanceThreshold)
                    continue;

                cnt[i]++;
                cnt[j]++;
            }
        }

        for (i = n - 1; i > -1; --i)
        {
            if (cnt[i] < mincnt)
            {
                mincnt = cnt[i];
                minix = i;
            }
        }

        return minix;
    }
};
