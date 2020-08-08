/**
 * Submission ID: 88934839
 * Question ID: 721
 * Question Title: 账户合并
 * Question URL: https://leetcode-cn.com/problems/accounts-merge/
 * Solution Time: 2020-07-18 11:07:35
 * Solution Test Result: 49 / 49
 * Solution Status: Accepted
 * Solution Memory: 29.9 MB
 * Solution Runtime: 284 ms
 */

class Solution {
public:

    class disjoint_set
    {
    public:
        disjoint_set(int n)
        {
            ps = std::vector<int>(n);
            for (int i = 0; i < n; ++i)
                ps[i] = i;
        }

        int find(int x)
        {
            if (x == ps[x])
                return x;
            ps[x] = find(ps[x]);
            return ps[x];
        }

        void merge(int x, int y)
        {
            ps[find(y)] = find(x);
        }

    private:
        std::vector<int> ps;
    };

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
    {
        int i, j, k, n = accounts.size();
        std::map<std::string, std::vector<int>> invmp;
        disjoint_set djs(n);
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

        for (auto it = invmp.begin(); it != invmp.end(); ++it)
        {
            for (i = 1; i < it->second.size(); ++i)
            {
                djs.merge(it->second[0], it->second[i]);
            }
        }

        for (i = 0; i < n; ++i)
            eqclz[djs.find(i)].push_back(i);

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
