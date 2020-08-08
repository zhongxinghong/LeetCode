/**
 * Submission ID: 89600449
 * Question ID: 869
 * Question Title: 相似字符串组
 * Question URL: https://leetcode-cn.com/problems/similar-string-groups/
 * Solution Time: 2020-07-20 14:27:38
 * Solution Test Result: 63 / 63
 * Solution Status: Accepted
 * Solution Memory: 13.9 MB
 * Solution Runtime: 2868 ms
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

    int numSimilarGroups(vector<string>& A)
    {
        int n = A.size(), m = A[0].size(), i, j, k;
        disjoint_set djs(n);
        std::vector<int> diff(3);
        std::set<int> s;

        for (i = 0; i < n - 1; ++i)
        {
            for (j = i + 1; j < n; ++j)
            {
                diff.clear();

                for (k = 0; k < m && diff.size() != 3; ++k)
                {
                    if (A[i][k] == A[j][k])
                        continue;
                    diff.push_back(k);
                }

                if (diff.size() == 0)
                {
                    djs.merge(i, j);
                    continue;
                }

                if (diff.size() != 2)
                    continue;

                if (A[i][diff[0]] != A[j][diff[1]] || A[i][diff[1]] != A[j][diff[0]])
                    continue;

                djs.merge(i, j);
            }
        }

        for (i = 0; i < n; ++i)
            s.insert(djs.find(i));

        return s.size();
    }
};
