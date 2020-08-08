/**
 * Submission ID: 88258742
 * Question ID: 101
 * Question Title: 对称二叉树
 * Question URL: https://leetcode-cn.com/problems/symmetric-tree/
 * Solution Time: 2020-07-16 09:32:49
 * Solution Test Result: 195 / 195
 * Solution Status: Accepted
 * Solution Memory: 12.4 MB
 * Solution Runtime: 4 ms
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

    bool isSymmetricNode(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;

        if ((!p && q) || (p && !q) || (p->val != q->val))
            return false;

        return isSymmetricNode(p->left, q->right) && isSymmetricNode(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;

        return isSymmetricNode(root->left, root->right);
    }
};
