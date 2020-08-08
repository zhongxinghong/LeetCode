/**
 * Submission ID: 88362695
 * Question ID: 111
 * Question Title: 二叉树的最小深度
 * Question URL: https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
 * Solution Time: 2020-07-16 15:20:48
 * Solution Test Result: 41 / 41
 * Solution Status: Accepted
 * Solution Memory: 17.6 MB
 * Solution Runtime: 8 ms
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
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;

        if (!root->left && !root->right)
            return 1;
        else if (root->left && !root->right)
            return minDepth(root->left) + 1;
        else if (!root->left && root->right)
            return minDepth(root->right) + 1;
        else
            return std::min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
