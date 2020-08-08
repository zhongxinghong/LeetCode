/**
 * Submission ID: 89125220
 * Question ID: 801
 * Question Title: 判断二分图
 * Question URL: https://leetcode-cn.com/problems/is-graph-bipartite/
 * Solution Time: 2020-07-18 21:48:19
 * Solution Test Result: 78 / 78
 * Solution Status: Accepted
 * Solution Memory: 11.5 MB
 * Solution Runtime: 48 ms
 */

class Solution {
public:

    bool fillSet(
        const std::vector<std::vector<int>> &graph,
        std::vector<bool> &S1,
        std::vector<bool> &S2,
        int node)
    {
        int i, j;

        if (S1[node])
            return false;

        if (S2[node])
            return true;

        S2[node] = true;

        for (i = 0; i < graph[node].size(); ++i)
        {
            j = graph[node][i];

            if (!fillSet(graph, S2, S1, j))
                return false;
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(), i;
        std::vector<bool> S1(n, false), S2(n, false);

        for (i = 0; i < n; ++i)
        {
            if (S1[i] || S2[i])
                continue;

            if (!S1[i])
            {
                if (!fillSet(graph, S2, S1, i))
                    return false;
            }
            else
            {
                if (!fillSet(graph, S1, S2, i))
                    return false;
            }
        }

        return true;
    }
};
