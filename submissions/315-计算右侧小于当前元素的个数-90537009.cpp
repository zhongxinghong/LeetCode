/**
 * Submission ID: 90537009
 * Question ID: 315
 * Question Title: 计算右侧小于当前元素的个数
 * Question URL: https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/
 * Solution Time: 2020-07-22 23:57:19
 * Solution Test Result: 16 / 16
 * Solution Status: Accepted
 * Solution Memory: 10.3 MB
 * Solution Runtime: 24 ms
 */

class Solution {
public:

    struct node_s
    {
        int x;
        int ix;
    };

    void merge_sort(
        std::vector<node_s> &v,
        std::vector<node_s> &tmp,
        int st,
        int ed,
        std::vector<int> &cnt)
    {
        if (st >= ed)
            return;

        int mid = (st + ed) / 2;
        int i = st, j = mid + 1, m = i, k;

        merge_sort(v, tmp, i, mid, cnt);
        merge_sort(v, tmp, j, ed, cnt);

        for (k = st; k <= ed; ++k)
            tmp[k] = v[k];

        while (i <= mid || j <= ed)
        {
            if (j > ed || (i <= mid && tmp[i].x <= tmp[j].x))
            {
                cnt[tmp[i].ix] += j - mid - 1;
                v[m++] = tmp[i++];
            }
            else
                v[m++] = tmp[j++];
        }
    }

    vector<int> countSmaller(vector<int>& nums)
    {
        int i, n = nums.size();
        std::vector<node_s> v(n), tmp(n);
        std::vector<int> cnt(n);

        for (i = 0; i < n; ++i)
        {
            v[i].x = nums[i];
            v[i].ix = i;
        }

        merge_sort(v, tmp, 0, nums.size() - 1, cnt);
        return cnt;
    }
};
