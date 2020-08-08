/**
 * Submission ID: 89368403
 * Question ID: 922
 * Question Title: 可能的二分法
 * Question URL: https://leetcode-cn.com/problems/possible-bipartition/
 * Solution Time: 2020-07-19 17:57:25
 * Solution Test Result: 70 / 70
 * Solution Status: Accepted
 * Solution Memory: 65.1 MB
 * Solution Runtime: 492 ms
 */

class Solution {
public:

    bool fillSet(
        const std::vector<std::vector<int>> &g,
        std::vector<bool> &S1,
        std::vector<bool> &S2,
        int i)
    {
        if (S1[i])
            return false;

        if (S2[i])
            return true;

        S2[i] = true;

        int j, k;

        for (j = 0; j < g[i].size(); ++j)
        {
            k = g[i][j];
            if (!fillSet(g, S2, S1, k))
                return false;
        }

        return true;
    }

    bool possibleBipartition(int N, vector<vector<int>>& dislikes)
    {
        int i;
        std::vector<std::vector<int>> g(N);
        std::vector<bool> S1(N, false), S2(N, false);

        for (i = 0; i < dislikes.size(); ++i)
        {
            g[dislikes[i][0] - 1].push_back(dislikes[i][1] - 1);
            g[dislikes[i][1] - 1].push_back(dislikes[i][0] - 1);
        }

        for (i = 0; i < N; ++i)
        {
            if (S1[i] || S2[i])
                continue;

            if (!fillSet(g, S1, S2, i))
                return false;
        }

        return true;
    }
};
