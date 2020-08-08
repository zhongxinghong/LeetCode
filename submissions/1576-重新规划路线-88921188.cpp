/**
 * Submission ID: 88921188
 * Question ID: 1576
 * Question Title: 重新规划路线
 * Question URL: https://leetcode-cn.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
 * Solution Time: 2020-07-18 10:25:15
 * Solution Test Result: 72 / 72
 * Solution Status: Accepted
 * Solution Memory: 83.5 MB
 * Solution Runtime: 620 ms
 */

class Solution {
public:

    int minReorder(int n, vector<vector<int>>& connections)
    {
        int i, j, nd, cnt = 0;
        std::vector<std::vector<int>> otb(n), itb(n);
        std::vector<bool> vis(n, false);
        std::stack<int> st;

        for (i = 0; i < connections.size(); ++i)
        {
            otb[connections[i][0]].push_back(connections[i][1]);
            itb[connections[i][1]].push_back(connections[i][0]);
        }

        st.push(0);
        vis[0] = true;

        while (!st.empty())
        {
            nd = st.top();
            st.pop();

            for (i = 0; i < itb[nd].size(); ++i)
            {
                if (vis[itb[nd][i]])
                    continue;

                st.push(itb[nd][i]);
                vis[itb[nd][i]] = true;
            }

            for (i = 0; i < otb[nd].size(); ++i)
            {
                if (vis[otb[nd][i]])
                    continue;

                st.push(otb[nd][i]);
                vis[otb[nd][i]] = true;

                cnt++;
            }
        }

        return cnt;
    }
};
