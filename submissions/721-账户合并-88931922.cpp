/**
 * Submission ID: 88931922
 * Question ID: 721
 * Question Title: 账户合并
 * Question URL: https://leetcode-cn.com/problems/accounts-merge/
 * Solution Time: 2020-07-18 10:58:45
 * Solution Test Result: 49 / 49
 * Solution Status: Accepted
 * Solution Memory: 29.9 MB
 * Solution Runtime: 328 ms
 */

class Solution {
public:

    int djs_find(std::vector<int> &djs, int x)
    {
        if (x == djs[x])
            return x;
        djs[x] = djs_find(djs, djs[x]);
        return djs[x];
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
    {
        int i, j, k, n = accounts.size(), px, py;
        std::map<std::string, std::vector<int>> invmp;
        std::vector<int> djs(n);
        std::vector<std::vector<int>> eqclz(n);
        std::vector<std::vector<std::string>> ret;
        std::set<std::string> emails;
        std::vector<std::string> tmp;
        std::string name;

        for (i = 0; i < n; ++i)
        {
            for (j = 1; j < accounts[i].size(); ++j)
            {
                invmp[accounts[i][j]].push_back(i);
            }
        }

        for (i = 0; i < n; ++i)
            djs[i] = i;

        for (auto it = invmp.begin(); it != invmp.end(); ++it)
        {
            px = djs_find(djs, it->second[0]);

            for (i = 1; i < it->second.size(); ++i)
            {
                py = djs_find(djs, it->second[i]);

                if (px != py)
                    djs[py] = px;
            }
        }

        for (i = 0; i < n; ++i)
            eqclz[djs_find(djs, i)].push_back(i);

        for (i = 0; i < n; ++i)
        {
            if (eqclz[i].empty())
                continue;

            name = accounts[eqclz[i][0]][0];

            emails.clear();

            for (j = 0; j < eqclz[i].size(); ++j)
            {
                for (k = 1; k < accounts[eqclz[i][j]].size(); ++k)
                {
                    emails.insert(accounts[eqclz[i][j]][k]);
                }
            }

            tmp.clear();
            tmp.push_back(name);

            for (auto it = emails.begin(); it != emails.end(); ++it)
                tmp.push_back(*it);

            ret.push_back(tmp);
        }

        return ret;
    }
};
