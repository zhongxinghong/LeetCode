/**
 * Submission ID: 88475234
 * Question ID: 671
 * Question Title: 二叉树中第二小的节点
 * Question URL: https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree/
 * Solution Time: 2020-07-16 21:02:57
 * Solution Test Result: 35 / 35
 * Solution Status: Accepted
 * Solution Memory: 6.9 MB
 * Solution Runtime: 0 ms
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
    int findSecondMinimumValue(TreeNode* root) {
        int ret = -1, lret = -1, rret = -1;

        if (root == NULL || (!root->left && !root->right))
            return ret;

        if (root->left->val < root->right->val)
        {
            lret = findSecondMinimumValue(root->left);
            if (lret == -1)
                return root->right->val;
            else
                return std::min(lret, root->right->val);
        }

        if (root->right->val < root->left->val)
        {
            rret = findSecondMinimumValue(root->right);
            if (rret == -1)
                return root->left->val;
            else
                return std::min(rret, root->left->val);
        }

        lret = findSecondMinimumValue(root->left);
        rret = findSecondMinimumValue(root->right);

        if (lret != -1 || rret != -1)
        {
            if (rret == -1)
                return lret;
            if (lret == -1)
                return rret;
            return std::min(lret, rret);
        }

        return ret;
    }
};
