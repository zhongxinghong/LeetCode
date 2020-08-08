/**
 * Submission ID: 90956623
 * Question ID: 49
 * Question Title: 字母异位词分组
 * Question URL: https://leetcode-cn.com/problems/group-anagrams/
 * Solution Time: 2020-07-24 10:51:27
 * Solution Test Result: 101 / 101
 * Solution Status: Accepted
 * Solution Memory: 15 MB
 * Solution Runtime: 112 ms
 */

class Solution {
public:

    class disjoint_set
    {
    public:
        disjoint_set(int n) : ps(std::vector<int>(n))
        {
            for (int i = 0; i < n; ++i)
                ps[i] = i;
        }

        int find(int x)
        {
            if (x == ps[x])
                return x;
            return ps[x] = find(ps[x]);
        }

        void merge(int x, int y)
        {
            ps[find(y)] = find(x);
        }

    private:
        std::vector<int> ps;
    };

    struct node_s
    {
        int ix;
        std::string s;

        bool operator<(const node_s &other) const
        {
            return s < other.s;
        }
    };

    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        int n = strs.size(), i, j;
        std::vector<node_s> v(n);
        disjoint_set djs(n);
        std::vector<std::vector<int>> eqclz(n);
        std::vector<std::vector<std::string>> ret;

        for (i = 0; i < n; ++i)
        {
            v[i].ix = i;
            v[i].s = strs[i];
            std::sort(v[i].s.begin(), v[i].s.end());
        }

        std::sort(v.begin(), v.end());

        for (i = 0; i < n - 1; ++i)
        {
            if (v[i].s == v[i + 1].s)
                djs.merge(v[i].ix, v[i + 1].ix);
        }

        for (i = 0; i < n; ++i)
            eqclz[djs.find(i)].push_back(i);

        for (i = 0; i < n; ++i)
        {
            if (eqclz[i].empty())
                continue;

            ret.push_back(std::vector<std::string>());

            for (j = 0; j < eqclz[i].size(); ++j)
                ret.back().push_back(strs[eqclz[i][j]]);
        }

        return ret;
    }
};
