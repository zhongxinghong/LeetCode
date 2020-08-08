/**
 * Submission ID: 89561728
 * Question ID: 1558
 * Question Title: 课程安排 IV
 * Question URL: https://leetcode-cn.com/problems/course-schedule-iv/
 * Solution Time: 2020-07-20 11:41:52
 * Solution Test Result: 68 / 68
 * Solution Status: Accepted
 * Solution Memory: 68.2 MB
 * Solution Runtime: 808 ms
 */

class Solution {
public:

    void build_pcs(
        std::vector<std::set<int>> &pcs,
        const std::vector<std::vector<int>> &itable,
        std::vector<bool> &vis,
        int course)
    {
        if (vis[course])
            return;

        vis[course] = true;

        int i, j;

        for (i = 0; i < itable[course].size(); ++i)
        {
            j = itable[course][i];

            pcs[course].insert(j);
            build_pcs(pcs, itable, vis, j);
            pcs[course].insert(pcs[j].begin(), pcs[j].end());
        }
    }

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries)
    {
        int i;
        std::vector<std::set<int>> pcs(n);
        std::vector<std::vector<int>> itable(n);
        std::vector<int> odeg(n, 0);
        std::vector<bool> vis(n, false), ret(queries.size());

        for (i = 0; i < prerequisites.size(); ++i)
        {
            itable[prerequisites[i][1]].push_back(prerequisites[i][0]);
            odeg[prerequisites[i][0]]++;
        }

        for (i = 0; i < n; ++i)
        {
            if (odeg[i] == 0)
                build_pcs(pcs, itable, vis, i);
        }

        for (i = 0; i < queries.size(); ++i)
            ret[i] = (pcs[queries[i][1]].find(queries[i][0]) != pcs[queries[i][1]].end());

        return ret;
    }
};
