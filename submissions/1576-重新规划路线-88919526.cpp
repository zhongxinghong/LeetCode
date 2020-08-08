/**
 * Submission ID: 88919526
 * Question ID: 1576
 * Question Title: 重新规划路线
 * Question URL: https://leetcode-cn.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
 * Solution Time: 2020-07-18 10:21:15
 * Solution Test Result: 72 / 72
 * Solution Status: Accepted
 * Solution Memory: 89.2 MB
 * Solution Runtime: 1744 ms
 */

class Solution {
public:

    int minReorder(int n, vector<vector<int>>& connections)
    {
        int i, j, nd, cur = 0, cnt = 0;
        std::vector<std::vector<int>> otb(n), itb(n);
        std::vector<bool> vis(n, false);
        std::vector<int> visnode;
        std::stack<int> st;

        for (i = 0; i < connections.size(); ++i)
        {
            otb[connections[i][0]].push_back(connections[i][1]);
            itb[connections[i][1]].push_back(connections[i][0]);
        }

        while (visnode.size() < n)
        {
            st.push(cur);

            if (!vis[cur])
            {
                vis[cur] = true;
                visnode.push_back(cur);
            }

            while (!st.empty())
            {
                nd = st.top();
                st.pop();

                for (i = itb[nd].size() - 1; i > -1; --i)
                {
                    if (vis[itb[nd][i]])
                        continue;

                    st.push(itb[nd][i]);
                    vis[itb[nd][i]] = true;
                    visnode.push_back(itb[nd][i]);
                }
            }

            if (visnode.size() == n)
                break;

            for (i = visnode.size() - 1; i > -1; --i)
            {
                nd = visnode[i];
                for (j = 0; j < otb[nd].size(); ++j)
                {
                    if (vis[otb[nd][j]])
                        continue;

                    itb[nd].push_back(otb[nd][j]);
                    cnt++;

                    cur = nd;
                    goto OUTER_CONTINUE;
                }
            }

        OUTER_CONTINUE:
            continue;
        }

        return cnt;
    }
};
