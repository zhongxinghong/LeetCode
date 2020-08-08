/**
 * Submission ID: 91703628
 * Question ID: 514
 * Question Title: 自由之路
 * Question URL: https://leetcode-cn.com/problems/freedom-trail/
 * Solution Time: 2020-07-26 21:28:21
 * Solution Test Result: 302 / 302
 * Solution Status: Accepted
 * Solution Memory: 15.9 MB
 * Solution Runtime: 36 ms
 */

class Solution {
public:
    int findRotateSteps(string ring, string key)
    {
        static const int INF = 1 << 24;

        int n = ring.size(), m = key.size(), i, j, k, st, ed, ret = INF;
        std::vector<std::vector<int>> indices(256);
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n, INF));

        for (i = 0; i < n; ++i)
            indices[ring[i]].push_back(i);

        st = 0;
        dp[0][st] = 0;

        i = 1;
        const auto &v1 = indices[key[i - 1]];

        for (k = 0; k < v1.size(); ++k)
        {
            ed = v1[k];
            dp[i][ed] = dp[i - 1][st] + std::min((n + st - ed) % n, (n + ed - st) % n) + 1;
        }

        for (i = 2; i <= m; ++i)
        {
            const auto &v0 = indices[key[i - 2]];
            const auto &v1 = indices[key[i - 1]];

            for (k = 0; k < v1.size(); ++k)
            {
                ed = v1[k];

                for (j = 0; j < v0.size(); ++j)
                {
                    st = v0[j];
                    dp[i][ed] = std::min(dp[i][ed],
                                         dp[i - 1][st] + std::min((n + st - ed) % n, (n + ed - st) % n) + 1);
                }
            }
        }

        const auto &v0 = indices[key.back()];

        for (k = 0; k < v0.size(); ++k)
        {
            ed = v0[k];
            ret = std::min(ret, dp[m][ed]);
        }

        return ret;
    }
};
