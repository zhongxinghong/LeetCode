/**
 * Submission ID: 88465702
 * Question ID: 112
 * Question Title: 路径总和
 * Question URL: https://leetcode-cn.com/problems/path-sum/
 * Solution Time: 2020-07-16 20:33:25
 * Solution Test Result: 114 / 114
 * Solution Status: Accepted
 * Solution Memory: 17.3 MB
 * Solution Runtime: 12 ms
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

    void __hasPathSum(TreeNode *root, int sum, bool &found)
    {
        if (root == NULL || found)
            return;

        if (!root->left && !root->right && root->val == sum)
        {
            found = true;
            return;
        }

        __hasPathSum(root->left, sum - root->val, found);
        __hasPathSum(root->right, sum - root->val, found);
    }

    bool hasPathSum(TreeNode* root, int sum) {
        bool found = false;
        __hasPathSum(root, sum, found);
        return found;
    }
};
