/**
 * Submission ID: 88370991
 * Question ID: 530
 * Question Title: 二叉搜索树的最小绝对差
 * Question URL: https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/
 * Solution Time: 2020-07-16 15:43:09
 * Solution Test Result: 186 / 186
 * Solution Status: Accepted
 * Solution Memory: 25.2 MB
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

    int iabs(int x)
    {
        return x < 0 ? -x : x;
    }

    void __getMinimumDifference(const TreeNode *root, const TreeNode *p, int &mindiff)
    {
        if (!p || !root)
            return;

        if (root != p)
            mindiff = std::min(mindiff, iabs(root->val - p->val));

        __getMinimumDifference(root, p->left, mindiff);
        __getMinimumDifference(root, p->right, mindiff);
    }

    int getMinimumDifference(TreeNode* root) {
        if (!root)
            return 0;

        int mindiff = 1 << 30;
        __getMinimumDifference(root, root, mindiff);

        if (root->left)
            mindiff = std::min(mindiff, getMinimumDifference(root->left));

        if (root->right)
            mindiff = std::min(mindiff, getMinimumDifference(root->right));

        return mindiff;
    }
};
