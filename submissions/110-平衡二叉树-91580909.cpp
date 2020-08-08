/**
 * Submission ID: 91580909
 * Question ID: 110
 * Question Title: 平衡二叉树
 * Question URL: https://leetcode-cn.com/problems/balanced-binary-tree/
 * Solution Time: 2020-07-26 14:14:55
 * Solution Test Result: 227 / 227
 * Solution Status: Accepted
 * Solution Memory: 14.9 MB
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

    int __isBalanced(TreeNode *root, bool &balanced)
    {
        if (root == NULL)
            return 0;

        int ldep = __isBalanced(root->left, balanced);
        int rdep = __isBalanced(root->right, balanced);

        if (abs(ldep - rdep) > 1)
            balanced = false;

        return std::max(ldep, rdep) + 1;
    }

    bool isBalanced(TreeNode* root)
    {
        bool balanced = true;
        __isBalanced(root, balanced);
        return balanced;
    }
};
