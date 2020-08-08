/**
 * Submission ID: 90542722
 * Question ID: 100301
 * Question Title: 最小的k个数
 * Question URL: https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/
 * Solution Time: 2020-07-23 00:23:55
 * Solution Test Result: 38 / 38
 * Solution Status: Accepted
 * Solution Memory: 18.5 MB
 * Solution Runtime: 56 ms
 */

class Solution {
public:

    void quick_sort(std::vector<int> &arr, int st, int ed, int k)
    {
        if (st > ed)
            return;

        int i = st, j = ed, p = arr[st];

        while (i < j)
        {
            while (i < j && arr[j] > p)
                j--;

            if (i < j)
                arr[i++] = arr[j];

            while (i < j && arr[i] <= p)
                i++;

            if (i < j)
                arr[j--] = arr[i];
        }

        arr[i] = p;

        if (i == k - 1)
            return;

        else if (i > k - 1)
            quick_sort(arr, st, i - 1, k);
        else
            quick_sort(arr, i + 1, ed, k);
    }

    vector<int> getLeastNumbers(vector<int>& arr, int k)
    {
        int i, n = arr.size();
        std::vector<int> ret(k);

        quick_sort(arr, 0, n - 1, k);

        for (i = 0; i < k; ++i)
            ret[i] = arr[i];

        return ret;
    }
};
