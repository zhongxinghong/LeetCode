/**
 * Submission ID: 89223981
 * Question ID: 1554
 * Question Title: 收集树上所有苹果的最少时间
 * Question URL: https://leetcode-cn.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
 * Solution Time: 2020-07-19 10:34:44
 * Solution Test Result: 54 / 54
 * Solution Status: Accepted
 * Solution Memory: 60.6 MB
 * Solution Runtime: 396 ms
 */

class Solution {
public:

    typedef std::pair<bool, int> return_t;

    return_t dfs(
        std::vector<std::vector<int>> &g,
        std::vector<bool> &vis,
        std::vector<bool> &hasApple,
        int vertex)
    {
        int i, j;
        return_t ret, oret;

        vis[vertex] = true;

        ret.first = false;
        ret.second = 1;

        if (hasApple[vertex])
            ret.first = true;

        for (i = 0; i < g[vertex].size(); ++i)
        {
            j = g[vertex][i];

            if (vis[j])
                continue;

            oret = dfs(g, vis, hasApple, j);

            if (!oret.first)
                continue;

            ret.first = true;
            ret.second += oret.second;
        }

        return ret;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple)
    {
        int i;
        std::vector<std::vector<int>> g(n);
        std::vector<bool> vis(n, false);

        for (i = 0; i < edges.size(); ++i)
        {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }

        auto ret = dfs(g, vis, hasApple, 0);
        return (ret.second - 1) * 2;
    }
};
