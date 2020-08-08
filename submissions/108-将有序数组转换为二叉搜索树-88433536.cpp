/**
 * Submission ID: 88433536
 * Question ID: 108
 * Question Title: 将有序数组转换为二叉搜索树
 * Question URL: https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/
 * Solution Time: 2020-07-16 18:38:57
 * Solution Test Result: 32 / 32
 * Solution Status: Accepted
 * Solution Memory: 23.3 MB
 * Solution Runtime: 44 ms
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    TreeNode *build_tree(const std::vector<int> &nums, int st, int ed)
    {
        if (st >= ed)
            return NULL;

        int mid = (st + ed) / 2;

        TreeNode *root = new TreeNode(nums[mid]);
        root->left = build_tree(nums, st, mid);
        root->right = build_tree(nums, mid + 1, ed);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build_tree(nums, 0, nums.size());
    }
};
