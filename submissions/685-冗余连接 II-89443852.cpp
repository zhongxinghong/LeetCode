/**
 * Submission ID: 89443852
 * Question ID: 685
 * Question Title: 冗余连接 II
 * Question URL: https://leetcode-cn.com/problems/redundant-connection-ii/
 * Solution Time: 2020-07-19 22:40:46
 * Solution Test Result: 52 / 52
 * Solution Status: Accepted
 * Solution Memory: 40.4 MB
 * Solution Runtime: 36 ms
 */

class Solution {
public:

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges)
    {
        int n = edges.size(), i, j, k, st, ed, root;
        std::vector<std::vector<int>> itable(n), otable(n);
        std::vector<std::vector<int>> g(n, std::vector<int>(n, 0));
        std::vector<int> ideg(n, 0), odeg(n, 0), deg(n, 0);
        std::queue<int> q;
        bool found_root;

        for (i = 0; i < n; ++i)
        {
            st = edges[i][0] - 1;
            ed = edges[i][1] - 1;

            g[st][ed] = 1;
            itable[ed].push_back(st);
            otable[st].push_back(ed);
            ideg[ed]++;
            odeg[st]++;
        }

        for (i = 0; i < n; ++i)
            deg[i] = ideg[i] + odeg[i];

        for (i = 0; i < n; ++i)
        {
            if (deg[i] == 1)
                q.push(i);
        }

        while (!q.empty())
        {
            i = q.front();
            q.pop();

            for (j = 0; j < otable[i].size(); ++j)
            {
                k = otable[i][j];

                g[i][k] = 0;
                deg[i]--;
                deg[k]--;

                if (deg[k] == 1)
                    q.push(k);
            }

            for (j = 0; j < itable[i].size(); ++j)
            {
                k = itable[i][j];

                g[k][i] = 0;
                deg[i]--;
                deg[k]--;

                if (deg[k] == 1)
                    q.push(k);
            }
        }

        for (k = n - 1; k > -1; --k)
        {
            st = edges[k][0] - 1;
            ed = edges[k][1] - 1;

            if (g[st][ed] == 0)
                continue;

            found_root = false;
            odeg[st]--;
            ideg[ed]--;

            for (i = 0; i < n; ++i)
            {
                if (ideg[i] != 0)
                    continue;

                if (!found_root)
                {
                    root = i;
                    found_root = true;
                }
                else
                {
                    goto FAILED;
                }
            }

            if (!found_root)
                goto FAILED;

            if (odeg[root] == 0)
                goto FAILED;

            return edges[k];

        FAILED:
            odeg[st]++;
            ideg[ed]++;
        }

        return {-1, -1};
    }
};
