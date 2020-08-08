/**
 * Submission ID: 91706482
 * Question ID: 514
 * Question Title: 自由之路
 * Question URL: https://leetcode-cn.com/problems/freedom-trail/
 * Solution Time: 2020-07-26 21:37:32
 * Solution Test Result: 302 / 302
 * Solution Status: Accepted
 * Solution Memory: 15.9 MB
 * Solution Runtime: 40 ms
 */

class Solution {
public:
    int findRotateSteps(string ring, string key)
    {
        static const int INF = 1 << 24;
        static const std::vector<int> v0hd = {0};

        int n = ring.size(), m = key.size(), i, j, k, st, ed, ret = INF;
        std::vector<std::vector<int>> indices(256);
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n, INF));

        for (i = 0; i < n; ++i)
            indices[ring[i]].push_back(i);

        dp[0][0] = 0;

        for (i = 1; i <= m; ++i)
        {
            const auto &v0 = (i == 1) ? v0hd : indices[key[i - 2]];
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

        const auto &v = indices[key.back()];

        for (k = 0; k < v.size(); ++k)
        {
            ed = v[k];
            ret = std::min(ret, dp[m][ed]);
        }

        return ret;
    }
};
