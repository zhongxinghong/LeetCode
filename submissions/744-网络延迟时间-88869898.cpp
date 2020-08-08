/**
 * Submission ID: 88869898
 * Question ID: 744
 * Question Title: 网络延迟时间
 * Question URL: https://leetcode-cn.com/problems/network-delay-time/
 * Solution Time: 2020-07-18 01:15:21
 * Solution Test Result: 51 / 51
 * Solution Status: Accepted
 * Solution Memory: 26.7 MB
 * Solution Runtime: 288 ms
 */

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K)
    {
        static const int INF = 1 << 24;

        int i, j, k, nd, maxt;
        std::vector<std::vector<int>> g(N, std::vector<int>(N, INF));
        std::vector<std::vector<int>> dist;

        K--;

        for (i = 0; i < times.size(); ++i)
            g[times[i][0] - 1][times[i][1] - 1] = times[i][2];

        dist = g;

        for (i = 0; i < N; ++i)
            dist[i][i] = 0;

        for (k = 0; k < N; ++k)
        {
            for (i = 0; i < N; ++i)
            {
                for (j = 0; j < N; ++j)
                {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        maxt = -1;

        for (i = 0; i < N; ++i)
        {
            if (dist[K][i] == INF)
                return -1;

            maxt = std::max(maxt, dist[K][i]);
        }

        return maxt;
    }
};
