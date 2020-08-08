/**
 * Submission ID: 89933082
 * Question ID: 1488
 * Question Title: 将整数按权重排序
 * Question URL: https://leetcode-cn.com/problems/sort-integers-by-the-power-value/
 * Solution Time: 2020-07-21 12:02:42
 * Solution Test Result: 333 / 333
 * Solution Status: Accepted
 * Solution Memory: 7.6 MB
 * Solution Runtime: 40 ms
 */

class Solution {
public:

    int getWeight(int x)
    {
        int step = 0;
        while (x != 1)
        {
            if (x % 2 == 0)
                x = x / 2;
            else
                x = 3 * x + 1;
            ++step;
        }
        return step;
    }

    struct node_s
    {
        int x;
        int w;

        bool operator<(const node_s &nd) const
        {
            return w != nd.w ? w < nd.w : x < nd.x;
        }
    };

    int getKth(int lo, int hi, int k)
    {
        int i;
        std::vector<node_s> v(hi - lo + 1);

        for (i = 0; i < v.size(); ++i)
        {
            v[i].x = lo + i;
            v[i].w = getWeight(lo + i);
        }

        std::sort(v.begin(), v.end());

        return v[k - 1].x;
    }
};
