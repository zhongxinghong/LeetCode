/**
 * Submission ID: 89384937
 * Question ID: 1493
 * Question Title: T 秒后青蛙的位置
 * Question URL: https://leetcode-cn.com/problems/frog-position-after-t-seconds/
 * Solution Time: 2020-07-19 19:06:12
 * Solution Test Result: 203 / 203
 * Solution Status: Accepted
 * Solution Memory: 11.3 MB
 * Solution Runtime: 36 ms
 */

class Solution {
public:

    struct node_s
    {
        int id;
        int pid;
        double prob;
        int time;
    };

    double frogPosition(int n, vector<vector<int>>& edges, int t, int target)
    {
        int i, j;
        double next_prob;
        std::vector<std::vector<int>> otable(n);
        std::queue<node_s> q;

        for (i = 0; i < edges.size(); ++i)
        {
            otable[edges[i][0] - 1].push_back(edges[i][1] - 1);
            otable[edges[i][1] - 1].push_back(edges[i][0] - 1);
        }

        q.push({0, -1, 1.0, 0});

        for (; !q.empty(); q.pop())
        {
            const node_s &node = q.front();

            if (node.id == target - 1)
            {
                if (node.time == t)
                    return node.prob;

                if (node.time > t)
                    return 0.0;

                if (node.pid != -1 && otable[node.id].size() == 1)
                    return node.prob;

                if (node.pid == -1 && otable[node.id].size() == 0)
                    return node.prob;

                return 0.0;
            }

            if (node.pid == -1)
                next_prob = node.prob / otable[node.id].size();
            else
                next_prob = node.prob / (otable[node.id].size() - 1);

            for (i = 0; i < otable[node.id].size(); ++i)
            {
                j = otable[node.id][i];

                if (j == node.pid)
                    continue;

                q.push({j, node.id, next_prob, node.time + 1});
            }
        }

        return 0.0;
    }
};
