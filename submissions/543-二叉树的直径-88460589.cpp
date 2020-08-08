/**
 * Submission ID: 88460589
 * Question ID: 543
 * Question Title: 二叉树的直径
 * Question URL: https://leetcode-cn.com/problems/diameter-of-binary-tree/
 * Solution Time: 2020-07-16 20:17:51
 * Solution Test Result: 106 / 106
 * Solution Status: Accepted
 * Solution Memory: 20.6 MB
 * Solution Runtime: 72 ms
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

    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;

        int d = maxDepth(root->left) + maxDepth(root->right);
        d = std::max(d, diameterOfBinaryTree(root->left));
        d = std::max(d, diameterOfBinaryTree(root->right));
        return d;
    }
};
