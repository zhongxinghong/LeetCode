/**
 * Submission ID: 90565042
 * Question ID: 4
 * Question Title: 寻找两个正序数组的中位数
 * Question URL: https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
 * Solution Time: 2020-07-23 08:11:57
 * Solution Test Result: 2085 / 2085
 * Solution Status: Accepted
 * Solution Memory: 7 MB
 * Solution Runtime: 16 ms
 */

class Solution {
public:

    int findKth(const std::vector<int> &nums1, const std::vector<int> &nums2, int k)
    {
        int n = nums1.size(), m = nums2.size(), i = 0, j = 0, ni, nj;

        for (;;)
        {
            if (i == n)
                return nums2[j + k - 1];

            if (j == m)
                return nums1[i + k - 1];

            if (k == 1)
                return std::min(nums1[i], nums2[j]);

            ni = std::min(i + k / 2, n) - 1;
            nj = std::min(j + k / 2, m) - 1;

            if (nums1[ni] <= nums2[nj])
            {
                k -= (ni + 1 - i);
                i = ni + 1;
            }
            else
            {
                k -= (nj + 1 - j);
                j = nj + 1;
            }
        }

        return -1;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), mid = (n + m) / 2;
        if ((n + m) % 2 == 1)
            return findKth(nums1, nums2, mid + 1);
        else
            return (findKth(nums1, nums2, mid) + findKth(nums1, nums2, mid + 1)) / 2.0;
    }
};
