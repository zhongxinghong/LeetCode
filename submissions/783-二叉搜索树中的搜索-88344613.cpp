/**
 * Submission ID: 88344613
 * Question ID: 783
 * Question Title: 二叉搜索树中的搜索
 * Question URL: https://leetcode-cn.com/problems/search-in-a-binary-search-tree/
 * Solution Time: 2020-07-16 14:29:06
 * Solution Test Result: 36 / 36
 * Solution Status: Accepted
 * Solution Memory: 35.1 MB
 * Solution Runtime: 104 ms
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
        while (root)
        {
            if (root->val > val)
                root = root->left;
            else if (root->val < val)
                root = root->right;
            else
                return root;
        }
        return NULL;
    }
};
