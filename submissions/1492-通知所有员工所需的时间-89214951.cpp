/**
 * Submission ID: 89214951
 * Question ID: 1492
 * Question Title: 通知所有员工所需的时间
 * Question URL: https://leetcode-cn.com/problems/time-needed-to-inform-all-employees/
 * Solution Time: 2020-07-19 10:08:10
 * Solution Test Result: 39 / 39
 * Solution Status: Accepted
 * Solution Memory: 55.3 MB
 * Solution Runtime: 444 ms
 */

class Solution {
public:

    struct vertex_s
    {
        int id;
        int time;
    };

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int i, maxt = -1;
        std::vector<std::vector<vertex_s>> otable(n);
        std::queue<vertex_s> q;
        vertex_s v1, v2;

        for (i = 0; i < n; ++i)
        {
            if (i == headID)
                continue;
            otable[manager[i]].push_back({i, informTime[i]});
        }

        q.push({headID, informTime[headID]});

        while (!q.empty())
        {
            v1 = q.front();
            q.pop();

            maxt = std::max(maxt, v1.time);

            for (i = 0; i < otable[v1.id].size(); ++i)
            {
                v2 = otable[v1.id][i];
                q.push({v2.id, v1.time + v2.time});
            }
        }

        return maxt;
    }
};
