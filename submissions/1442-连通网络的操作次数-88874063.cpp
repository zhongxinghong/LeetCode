/**
 * Submission ID: 88874063
 * Question ID: 1442
 * Question Title: 连通网络的操作次数
 * Question URL: https://leetcode-cn.com/problems/number-of-operations-to-make-network-connected/
 * Solution Time: 2020-07-18 02:29:03
 * Solution Test Result: 36 / 36
 * Solution Status: Accepted
 * Solution Memory: 59.1 MB
 * Solution Runtime: 280 ms
 */

class Solution {
public:

    void visitConnectedComponent(
        const std::vector<std::vector<int>> &g,
        std::vector<bool> &vis,
        const int &n,
        int node)
    {
        int i;
        std::stack<int> st;

        st.push(node);
        vis[node] = true;

        while (!st.empty())
        {
            node = st.top();
            st.pop();

            for (i = 0; i < g[node].size(); ++i)
            {
                if (vis[g[node][i]])
                    continue;

                st.push(g[node][i]);
                vis[g[node][i]] = true;
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections)
    {
        if (connections.size() < n - 1)
            return -1;

        int i, cnt = 0;
        std::vector<std::vector<int>> g(n);
        std::vector<bool> vis(n, false);

        for (i = 0; i < connections.size(); ++i)
        {
            g[connections[i][0]].push_back(connections[i][1]);
            g[connections[i][1]].push_back(connections[i][0]);
        }

        for (i = 0; i < n; ++i)
        {
            if (vis[i])
                continue;

            cnt++;
            visitConnectedComponent(g, vis, n, i);
        }

        return cnt - 1;
    }
};
