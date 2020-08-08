/**
 * Submission ID: 90636467
 * Question ID: 1000021
 * Question Title: 最小K个数
 * Question URL: https://leetcode-cn.com/problems/smallest-k-lcci/
 * Solution Time: 2020-07-23 11:34:39
 * Solution Test Result: 29 / 29
 * Solution Status: Accepted
 * Solution Memory: 17.9 MB
 * Solution Runtime: 52 ms
 */

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        int n = arr.size(), st = 0, ed = n - 1, i, j, p;

        if (n == 0 || k == 0)
            return {};

        if (n == k)
            return arr;

        for (;;)
        {
            i = st;
            j = ed;
            p = arr[st];

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
                break;
            else if (i > k - 1)
                ed = i - 1;
            else
                st = i + 1;
        }

        return std::vector<int>(&arr[0], &arr[k]);
    }
};
