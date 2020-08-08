/**
 * Submission ID: 88711534
 * Question ID: 799
 * Question Title: 二叉搜索树节点最小距离
 * Question URL: https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/
 * Solution Time: 2020-07-17 16:36:52
 * Solution Test Result: 45 / 45
 * Solution Status: Accepted
 * Solution Memory: 9.8 MB
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

    int iabs(int x)
    {
        return x < 0 ? -x : x;
    }

    void __minDiffInBST(const TreeNode *root, const TreeNode *p, int &mindiff)
    {
        if (!p || !root)
            return;

        if (root != p)
            mindiff = std::min(mindiff, iabs(root->val - p->val));

        __minDiffInBST(root, p->left, mindiff);
        __minDiffInBST(root, p->right, mindiff);
    }

    int minDiffInBST(TreeNode* root) {
        if (!root)
            return 0;

        int mindiff = 1 << 30;
        __minDiffInBST(root, root, mindiff);

        if (root->left)
            mindiff = std::min(mindiff, minDiffInBST(root->left));

        if (root->right)
            mindiff = std::min(mindiff, minDiffInBST(root->right));

        return mindiff;
    }
};
