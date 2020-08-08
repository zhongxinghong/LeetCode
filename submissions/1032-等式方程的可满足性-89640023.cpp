/**
 * Submission ID: 89640023
 * Question ID: 1032
 * Question Title: 等式方程的可满足性
 * Question URL: https://leetcode-cn.com/problems/satisfiability-of-equality-equations/
 * Solution Time: 2020-07-20 16:01:35
 * Solution Test Result: 181 / 181
 * Solution Status: Accepted
 * Solution Memory: 11 MB
 * Solution Runtime: 12 ms
 */

class Solution {
public:

    class disjoint_set
    {
    public:
        disjoint_set(int n)
        {
            ps.resize(n);
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

    struct cmp_s
    {
        bool operator()(const std::string &s1, const std::string &s2) const
        {
            return s1[1] > s2[1]; // '=' > '!'
        }
    };

    bool equationsPossible(vector<string>& equations)
    {
        int i, x, y;
        disjoint_set djs(26);

        std::sort(equations.begin(), equations.end(), cmp_s());

        for (i = 0; i < equations.size(); ++i)
        {
            const auto &s = equations[i];

            x = s[0] - 'a';
            y = s[3] - 'a';

            if (s[1] == '=')
                djs.merge(x, y);
            else
            {
                if (djs.find(x) == djs.find(y))
                    return false;
            }
        }

        return true;
    }
};
