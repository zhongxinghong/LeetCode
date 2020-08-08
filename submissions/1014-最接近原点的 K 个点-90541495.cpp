/**
 * Submission ID: 90541495
 * Question ID: 1014
 * Question Title: 最接近原点的 K 个点
 * Question URL: https://leetcode-cn.com/problems/k-closest-points-to-origin/
 * Solution Time: 2020-07-23 00:17:09
 * Solution Test Result: 83 / 83
 * Solution Status: Accepted
 * Solution Memory: 40.2 MB
 * Solution Runtime: 248 ms
 */

class Solution {
public:

    struct node_s
    {
        int d2;
        int ix;
    };

    void quick_sort(
        std::vector<node_s> &v,
        int st,
        int ed,
        int K)
    {
        if (st > ed)
            return;

        int i = st, j = ed;
        node_s p = v[i];

        while (i < j)
        {
            while (i < j && v[j].d2 > p.d2)
                j--;

            if (i < j)
                v[i++] = v[j];

            while (i < j && v[i].d2 <= p.d2)
                i++;

            if (i < j)
                v[j--] = v[i];
        }

        v[i] = p;

        if (i == K - 1)
            return;
        else if (i > K - 1)
            quick_sort(v, st, i - 1, K);
        else
            quick_sort(v, i + 1, ed, K);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K)
    {
        int i, j, x, y, n = points.size();
        std::vector<node_s> v(n);
        std::vector<std::vector<int>> ret(K);

        for (i = 0; i < n; ++i)
        {
            x = points[i][0];
            y = points[i][1];
            v[i].d2 = x * x + y * y;
            v[i].ix = i;
        }

        quick_sort(v, 0, n - 1, K);

        for (i = 0; i < K; ++i)
            ret[i] = points[v[i].ix];

        return ret;
    }
};
