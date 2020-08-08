/**
 * Submission ID: 88344171
 * Question ID: 783
 * Question Title: 二叉搜索树中的搜索
 * Question URL: https://leetcode-cn.com/problems/search-in-a-binary-search-tree/
 * Solution Time: 2020-07-16 14:27:33
 * Solution Test Result: 36 / 36
 * Solution Status: Accepted
 * Solution Memory: 35.1 MB
 * Solution Runtime: 68 ms
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL)
            return NULL;

        if (root->val > val)
            return searchBST(root->left, val);

        if (root->val < val)
            return searchBST(root->right, val);

        return root;
    }
};
