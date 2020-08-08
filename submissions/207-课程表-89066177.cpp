/**
 * Submission ID: 89066177
 * Question ID: 207
 * Question Title: 课程表
 * Question URL: https://leetcode-cn.com/problems/course-schedule/
 * Solution Time: 2020-07-18 17:50:21
 * Solution Test Result: 46 / 46
 * Solution Status: Accepted
 * Solution Memory: 12 MB
 * Solution Runtime: 40 ms
 */

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses, i, x, y;
        std::vector<std::vector<int>> otable(n);
        std::vector<int> idegree(n, 0);
        std::queue<int> q;

        for (i = 0; i < prerequisites.size(); ++i)
        {
            otable[prerequisites[i][1]].push_back(prerequisites[i][0]);
            idegree[prerequisites[i][0]]++;
        }

        for (i = 0; i < n; ++i)
        {
            if (idegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            x = q.front();
            q.pop();

            for (i = 0; i < otable[x].size(); ++i)
            {
                y = otable[x][i];

                if (--idegree[y] == 0)
                    q.push(y);
            }
        }

        for (i = 0; i < n; ++i)
        {
            if (idegree[i] != 0)
                return false;
        }

        return true;
    }
};
