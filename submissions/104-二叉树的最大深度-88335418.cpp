/**
 * Submission ID: 88335418
 * Question ID: 104
 * Question Title: 二叉树的最大深度
 * Question URL: https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
 * Solution Time: 2020-07-16 13:56:09
 * Solution Test Result: 39 / 39
 * Solution Status: Accepted
 * Solution Memory: 17.2 MB
 * Solution Runtime: 12 ms
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
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
