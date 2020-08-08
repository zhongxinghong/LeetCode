/**
 * Submission ID: 91233897
 * Question ID: 88
 * Question Title: 合并两个有序数组
 * Question URL: https://leetcode-cn.com/problems/merge-sorted-array/
 * Solution Time: 2020-07-25 10:31:57
 * Solution Test Result: 59 / 59
 * Solution Status: Accepted
 * Solution Memory: 9.1 MB
 * Solution Runtime: 4 ms
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1, p1 = m - 1, p2 = n - 1;

        while (p1 != -1 || p2 != -1)
        {
            if (p2 == -1 || (p1 != -1 && nums1[p1] > nums2[p2]))
                nums1[k--] = nums1[p1--];
            else
                nums1[k--] = nums2[p2--];
        }
    }
};
