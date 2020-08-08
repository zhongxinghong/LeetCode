/**
 * Submission ID: 88462133
 * Question ID: 543
 * Question Title: 二叉树的直径
 * Question URL: https://leetcode-cn.com/problems/diameter-of-binary-tree/
 * Solution Time: 2020-07-16 20:22:16
 * Solution Test Result: 106 / 106
 * Solution Status: Accepted
 * Solution Memory: 20.7 MB
 * Solution Runtime: 16 ms
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

    int getDepthAndSolve(TreeNode *root, int &ret)
    {
        if (root == NULL)
            return 0;

        int ldep = getDepthAndSolve(root->left, ret);
        int rdep = getDepthAndSolve(root->right, ret);

        ret = std::max(ret, ldep + rdep);

        return std::max(ldep, rdep) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;

        int ret = 0;
        getDepthAndSolve(root, ret);
        return ret;
    }
};
