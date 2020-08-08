/**
 * Submission ID: 89229203
 * Question ID: 547
 * Question Title: 朋友圈
 * Question URL: https://leetcode-cn.com/problems/friend-circles/
 * Solution Time: 2020-07-19 10:43:48
 * Solution Test Result: 113 / 113
 * Solution Status: Accepted
 * Solution Memory: 12.4 MB
 * Solution Runtime: 44 ms
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

    int findCircleNum(vector<vector<int>>& M)
    {
        int n = M.size(), i, j;
        disjoint_set djs(n);
        std::set<int> s;

        for (i = 0; i < n - 1; ++i)
        {
            for (j = i + 1; j < n; ++j)
            {
                if (M[i][j] == 1)
                    djs.merge(i, j);
            }
        }

        for (i = 0; i < n; ++i)
            s.insert(djs.find(i));

        return s.size();
    }
};
