/**
 * Submission ID: 88438553
 * Question ID: 669
 * Question Title: 修剪二叉搜索树
 * Question URL: https://leetcode-cn.com/problems/trim-a-binary-search-tree/
 * Solution Time: 2020-07-16 19:04:58
 * Solution Test Result: 77 / 77
 * Solution Status: Accepted
 * Solution Memory: 24.1 MB
 * Solution Runtime: 28 ms
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

    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (root == NULL)
            return root;

        if (root->val < L)
            return trimBST(root->right, L, R);

        if (root->val > R)
            return trimBST(root->left, L, R);

        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);

        return root;
    }
};
