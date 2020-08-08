/**
 * Submission ID: 88391947
 * Question ID: 1079
 * Question Title: 从根到叶的二进制数之和
 * Question URL: https://leetcode-cn.com/problems/sum-of-root-to-leaf-binary-numbers/
 * Solution Time: 2020-07-16 16:32:24
 * Solution Test Result: 63 / 63
 * Solution Status: Accepted
 * Solution Memory: 16.8 MB
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

    int __sumRootToLeaf(TreeNode *root, int cur)
    {
        int sum = 0;

        cur = (cur << 1) + root->val;

        if (!root->left && !root->right)
            return cur;

        if (root->left)
            sum += __sumRootToLeaf(root->left, cur);

        if (root->right)
            sum += __sumRootToLeaf(root->right, cur);

        return sum;
    }

    int sumRootToLeaf(TreeNode* root) {
        if (root == NULL)
            return 0;
        return __sumRootToLeaf(root, 0);
    }
};
