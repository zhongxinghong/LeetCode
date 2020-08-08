/**
 * Submission ID: 88458528
 * Question ID: 1000019
 * Question Title: BiNode
 * Question URL: https://leetcode-cn.com/problems/binode-lcci/
 * Solution Time: 2020-07-16 20:11:25
 * Solution Test Result: 34 / 34
 * Solution Status: Accepted
 * Solution Memory: 32.4 MB
 * Solution Runtime: 124 ms
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

    void __convertBiNode(TreeNode *&hd)
    {
        TreeNode *p;

        if (hd == NULL)
            return;

        while (hd->left)
        {
            p = hd;
            hd = hd->left;
            p->left = hd->right;
            hd->right = p;
        }

        __convertBiNode(hd->right);
    }

    TreeNode* convertBiNode(TreeNode* root) {
        __convertBiNode(root);
        return root;
    }
};
