/**
 * Submission ID: 88347484
 * Question ID: 1092
 * Question Title: 节点与其祖先之间的最大差值
 * Question URL: https://leetcode-cn.com/problems/maximum-difference-between-node-and-ancestor/
 * Solution Time: 2020-07-16 14:37:58
 * Solution Test Result: 27 / 27
 * Solution Status: Accepted
 * Solution Memory: 10.8 MB
 * Solution Runtime: 200 ms
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

    void __maxAncestorDiff(TreeNode *root, TreeNode *p, int &maxdiff)
    {
        if (!root || !p)
            return;

        int diff = iabs(root->val - p->val);
        if (diff > maxdiff)
            maxdiff = diff;

        __maxAncestorDiff(root, p->left, maxdiff);
        __maxAncestorDiff(root, p->right, maxdiff);
    }

    int maxAncestorDiff(TreeNode* root) {
        int maxdiff = 0;

        if (root == NULL)
            return maxdiff;

        __maxAncestorDiff(root, root, maxdiff);

        maxdiff = std::max(maxdiff, maxAncestorDiff(root->left));
        maxdiff = std::max(maxdiff, maxAncestorDiff(root->right));

        return maxdiff;
    }
};
