/**
 * Submission ID: 89658132
 * Question ID: 100171
 * Question Title: 节点间通路
 * Question URL: https://leetcode-cn.com/problems/route-between-nodes-lcci/
 * Solution Time: 2020-07-20 16:30:53
 * Solution Test Result: 32 / 32
 * Solution Status: Accepted
 * Solution Memory: 66.1 MB
 * Solution Runtime: 492 ms
 */

class Solution {
public:

    bool dfs(
        const std::vector<std::vector<int>> &otable,
        std::vector<bool> &vis,
        int st,
        const int &ed)
    {
        if (vis[st])
            return false;

        vis[st] = true;

        if (st == ed)
            return true;

        int i, j;

        for (i = 0; i < otable[st].size(); ++i)
        {
            j = otable[st][i];
            if (dfs(otable, vis, j, ed))
                return true;
        }

        return false;
    }

    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        int i;
        std::vector<std::vector<int>> otable(n);
        std::vector<bool> vis(n, false);

        for (i = 0; i < graph.size(); ++i)
            otable[graph[i][0]].push_back(graph[i][1]);

        return dfs(otable, vis, start, target);
    }
};
