/**
 * Submission ID: 88440553
 * Question ID: 1035
 * Question Title: 二叉树的堂兄弟节点
 * Question URL: https://leetcode-cn.com/problems/cousins-in-binary-tree/
 * Solution Time: 2020-07-16 19:14:41
 * Solution Test Result: 104 / 104
 * Solution Status: Accepted
 * Solution Memory: 10.8 MB
 * Solution Runtime: 4 ms
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void findParentWithDepth(TreeNode *root, int val, TreeNode *&parent, int curdep, int &retdep)
    {
        if (retdep != -1)
            return;

        if (root == NULL)
            return;

        if ((root->left && root->left->val == val) ||
            (root->right && root->right->val == val))
        {
            parent = root;
            retdep = curdep + 1;
            return;
        }

        findParentWithDepth(root->left, val, parent, curdep + 1, retdep);
        findParentWithDepth(root->right, val, parent, curdep + 1, retdep);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode *hd = new TreeNode(), *p;
        hd->left = root;

        int xdep = -1, ydep = -1;
        TreeNode *xp = NULL, *yp = NULL;

        findParentWithDepth(hd, x, xp, 0, xdep);
        findParentWithDepth(hd, y, yp, 0, ydep);

        delete hd;

        return (xp != yp) && (xdep == ydep);
    }
};
