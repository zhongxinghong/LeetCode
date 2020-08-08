/**
 * Submission ID: 88394578
 * Question ID: 226
 * Question Title: 翻转二叉树
 * Question URL: https://leetcode-cn.com/problems/invert-binary-tree/
 * Solution Time: 2020-07-16 16:39:17
 * Solution Test Result: 68 / 68
 * Solution Status: Accepted
 * Solution Memory: 9.1 MB
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return root;
        TreeNode *p = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(p);
        return root;
    }
};
