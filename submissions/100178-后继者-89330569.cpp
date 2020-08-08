/**
 * Submission ID: 89330569
 * Question ID: 100178
 * Question Title: 后继者
 * Question URL: https://leetcode-cn.com/problems/successor-lcci/
 * Solution Time: 2020-07-19 16:08:15
 * Solution Test Result: 24 / 24
 * Solution Status: Accepted
 * Solution Memory: 23 MB
 * Solution Runtime: 44 ms
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

    void __inorderSuccessor(TreeNode *root, const TreeNode *p, TreeNode *&last, TreeNode *&ret)
    {
        if (!root || ret)
            return;

        __inorderSuccessor(root->left, p, last, ret);

        if (last == p)
        {
            last = NULL;
            ret = root;
            return;
        }
        last = root;

        __inorderSuccessor(root->right, p, last, ret);
    }

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *last = NULL, *ret = NULL;
        __inorderSuccessor(root, p, last, ret);
        return ret;
    }
};
