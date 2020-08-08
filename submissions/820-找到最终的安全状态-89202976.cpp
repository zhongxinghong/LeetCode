/**
 * Submission ID: 89202976
 * Question ID: 820
 * Question Title: 找到最终的安全状态
 * Question URL: https://leetcode-cn.com/problems/find-eventual-safe-states/
 * Solution Time: 2020-07-19 09:06:08
 * Solution Test Result: 111 / 111
 * Solution Status: Accepted
 * Solution Memory: 49 MB
 * Solution Runtime: 456 ms
 */

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size(), i, j, k;
        std::vector<int> ret;
        std::vector<std::vector<int>> otable(n);
        std::vector<int> idegree(n, 0);
        std::queue<int> q;

        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < graph[i].size(); ++j)
            {
                k = graph[i][j];
                otable[k].push_back(i);
                idegree[i]++;
            }
        }

        for (i = 0; i < n; ++i)
        {
            if (idegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            i = q.front();
            q.pop();

            ret.push_back(i);

            for (j = 0; j < otable[i].size(); ++j)
            {
                k = otable[i][j];
                if (--idegree[k] == 0)
                    q.push(k);
            }
        }

        std::sort(ret.begin(), ret.end());
        return ret;
    }
};
