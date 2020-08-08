/**
 * Submission ID: 88162375
 * Question ID: 100176
 * Question Title: 检查平衡性
 * Question URL: https://leetcode-cn.com/problems/check-balance-lcci/
 * Solution Time: 2020-07-15 21:08:16
 * Solution Test Result: 227 / 227
 * Solution Status: Accepted
 * Solution Memory: 21.6 MB
 * Solution Runtime: 20 ms
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

    int iabs(int x)
    {
        return x < 0 ? -x : x;
    }

    int getTreeHeight(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return std::max(getTreeHeight(root->left), getTreeHeight(root->right)) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;

        if (iabs(getTreeHeight(root->left) - getTreeHeight(root->right)) > 1)
            return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};
