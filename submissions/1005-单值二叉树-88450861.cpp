/**
 * Submission ID: 88450861
 * Question ID: 1005
 * Question Title: 单值二叉树
 * Question URL: https://leetcode-cn.com/problems/univalued-binary-tree/
 * Solution Time: 2020-07-16 19:47:56
 * Solution Test Result: 72 / 72
 * Solution Status: Accepted
 * Solution Memory: 9.7 MB
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
    bool isUnivalTree(TreeNode* root) {
        if (root == NULL)
            return true;

        if (root->left)
        {
            if (root->left->val != root->val)
                return false;
            if (!isUnivalTree(root->left))
                return false;
        }

        if (root->right)
        {
            if (root->right->val != root->val)
                return false;
            if (!isUnivalTree(root->right))
                return false;
        }

        return true;
    }
};
