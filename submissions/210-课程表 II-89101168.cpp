/**
 * Submission ID: 89101168
 * Question ID: 210
 * Question Title: 课程表 II
 * Question URL: https://leetcode-cn.com/problems/course-schedule-ii/
 * Solution Time: 2020-07-18 20:16:53
 * Solution Test Result: 44 / 44
 * Solution Status: Accepted
 * Solution Memory: 12.4 MB
 * Solution Runtime: 40 ms
 */

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses, i, j, k;
        std::vector<int> ret;
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

        for (i = 0; i < n; ++i)
        {
            if (idegree[i] != 0)
                return {};
        }

        return ret;
    }
};
