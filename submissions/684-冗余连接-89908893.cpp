/**
 * Submission ID: 89908893
 * Question ID: 684
 * Question Title: 冗余连接
 * Question URL: https://leetcode-cn.com/problems/redundant-connection/
 * Solution Time: 2020-07-21 10:59:00
 * Solution Test Result: 39 / 39
 * Solution Status: Accepted
 * Solution Memory: 9.2 MB
 * Solution Runtime: 20 ms
 */

class Solution {
public:

    struct node_s
    {
        int id;
        int pid;
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        int n = edges.size(), i, j;
        std::vector<std::vector<int>> g(n);
        std::vector<int> deg(n, 0);
        std::queue<node_s> q;

        for (i = 0; i < n; ++i)
        {
            g[edges[i][0] - 1].push_back(edges[i][1] - 1);
            g[edges[i][1] - 1].push_back(edges[i][0] - 1);
            deg[edges[i][0] - 1]++;
            deg[edges[i][1] - 1]++;
        }

        for (i = 0; i < n; ++i)
        {
            if (deg[i] == 1)
                q.push({i, -1});
        }

        for (; !q.empty(); q.pop())
        {
            const auto &node = q.front();

            for (i = 0; i < g[node.id].size(); ++i)
            {
                j = g[node.id][i];

                if (j == node.pid)
                    continue;

                deg[node.id]--;
                deg[j]--;

                if (deg[j] == 1)
                    q.push({j, node.id});
            }
        }

        for (i = n - 1; i > -1; --i)
        {
            if (deg[edges[i][0] - 1] == 2 && deg[edges[i][1] - 1] == 2)
                return edges[i];
        }

        return {-1, -1};
    }
};
