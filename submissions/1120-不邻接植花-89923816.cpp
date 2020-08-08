/**
 * Submission ID: 89923816
 * Question ID: 1120
 * Question Title: 不邻接植花
 * Question URL: https://leetcode-cn.com/problems/flower-planting-with-no-adjacent/
 * Solution Time: 2020-07-21 11:31:58
 * Solution Test Result: 51 / 51
 * Solution Status: Accepted
 * Solution Memory: 40.1 MB
 * Solution Runtime: 348 ms
 */

class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        int i, j, k;
        std::vector<std::vector<int>> g(N);
        std::vector<int> colors(N, 0);
        std::vector<bool> used(5);

        for (i = 0; i < paths.size(); ++i)
        {
            g[paths[i][0] - 1].push_back(paths[i][1] - 1);
            g[paths[i][1] - 1].push_back(paths[i][0] - 1);
        }

        for (i = 0; i < N; ++i)
        {
            for (j = 1; j < used.size(); ++j)
                used[j] = false;

            for (j = 0; j < g[i].size(); ++j)
            {
                k = g[i][j];

                if (k > i || colors[k] == 0)
                    continue;

                used[colors[k]] = true;
            }

            for (j = 1; j < used.size(); ++j)
            {
                if (!used[j])
                {
                    colors[i] = j;
                    break;
                }
            }
        }

        return colors;
    }
};
