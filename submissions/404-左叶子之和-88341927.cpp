/**
 * Submission ID: 88341927
 * Question ID: 404
 * Question Title: 左叶子之和
 * Question URL: https://leetcode-cn.com/problems/sum-of-left-leaves/
 * Solution Time: 2020-07-16 14:18:51
 * Solution Test Result: 102 / 102
 * Solution Status: Accepted
 * Solution Memory: 13.4 MB
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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;

        if (root == NULL)
            return sum;

        if (root->left && !root->left->left && !root->left->right)
            sum += root->left->val;

        return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};
