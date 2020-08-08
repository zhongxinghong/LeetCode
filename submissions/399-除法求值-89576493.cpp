/**
 * Submission ID: 89576493
 * Question ID: 399
 * Question Title: 除法求值
 * Question URL: https://leetcode-cn.com/problems/evaluate-division/
 * Solution Time: 2020-07-20 12:40:24
 * Solution Test Result: 11 / 11
 * Solution Status: Accepted
 * Solution Memory: 7.5 MB
 * Solution Runtime: 0 ms
 */

class Solution {
public:

    struct edge
    {
        int ed;
        double weight;
    };

    double calc(
        std::vector<std::vector<edge>> &otable,
        std::vector<bool> &vis,
        int st, int ed)
    {
        static const double eps = 1e-5;

        int i;
        double ret = -1.0;

        for (i = 0; i < otable[st].size(); ++i)
        {
            const auto &e = otable[st][i];

            if (ed == e.ed)
                return e.weight;

            if (vis[e.ed])
                continue;

            vis[e.ed] = true;
            ret = calc(otable, vis, e.ed, ed);

            if (fabs(ret + 1.0) < eps) // ret == -1
                continue;

            ret *= e.weight;
            break;
        }

        // otable[st].push_back({ed, ret});

        // if (fabs(ret + 1.0) > eps && fabs(ret) > eps) // ret != -1 && ret != 0
        //     otable[ed].push_back({st, 1 / ret});

        return ret;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
    {
        static const double eps = 1e-5;

        int m = equations.size(), n, i, st, ed;
        std::unordered_map<std::string, int> indices;
        std::vector<std::vector<edge>> otable;
        std::vector<bool> vis;
        std::vector<double> ret(queries.size());

        for (i = 0; i < m; ++i)
        {
            const auto &var1 = equations[i][0];
            const auto &var2 = equations[i][1];

            if (indices.find(var1) == indices.end())
                indices.insert(std::make_pair(var1, indices.size()));

            if (indices.find(var2) == indices.end())
                indices.insert(std::make_pair(var2, indices.size()));
        }

        n = indices.size();
        otable.resize(n);

        for (i = 0; i < m; ++i)
        {
            const auto &var1 = equations[i][0];
            const auto &var2 = equations[i][1];
            st = indices[var1];
            ed = indices[var2];

            otable[st].push_back({ed, values[i]});

            if (fabs(values[i]) > eps) // ret != 0
                otable[ed].push_back({st, 1 / values[i]});
        }

        for (i = 0; i < queries.size(); ++i)
        {
            const auto &var1 = queries[i][0];
            const auto &var2 = queries[i][1];

            auto it1 = indices.find(var1);
            auto it2 = indices.find(var2);

            if (it1 == indices.end() || it2 == indices.end())
            {
                ret[i] = -1.0;
                continue;
            }

            st = it1->second;
            ed = it2->second;

            vis = std::vector<bool>(n, false);
            vis[st] = true;
            ret[i] = calc(otable, vis, st, ed);
        }

        return ret;
    }
};
