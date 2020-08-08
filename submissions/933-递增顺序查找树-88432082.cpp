/**
 * Submission ID: 88432082
 * Question ID: 933
 * Question Title: 递增顺序查找树
 * Question URL: https://leetcode-cn.com/problems/increasing-order-search-tree/
 * Solution Time: 2020-07-16 18:30:55
 * Solution Test Result: 35 / 35
 * Solution Status: Accepted
 * Solution Memory: 7.3 MB
 * Solution Runtime: 4 ms
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

    void bst2list(TreeNode *root, TreeNode *&p)
    {
        if (root == NULL)
            return;

        bst2list(root->left, p);
        p = p->right = new TreeNode(root->val);
        bst2list(root->right, p);
    }

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *hd = new TreeNode(), *p = hd;
        bst2list(root, p);

        p = hd->right;
        delete hd;

        return p;
    }
};
