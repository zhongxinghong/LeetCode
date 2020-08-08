/**
 * Submission ID: 88392714
 * Question ID: 1079
 * Question Title: 从根到叶的二进制数之和
 * Question URL: https://leetcode-cn.com/problems/sum-of-root-to-leaf-binary-numbers/
 * Solution Time: 2020-07-16 16:34:07
 * Solution Test Result: 63 / 63
 * Solution Status: Accepted
 * Solution Memory: 16.5 MB
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

    int __sumRootToLeaf(TreeNode *root, int num)
    {
        int sum = 0;

        num = (num << 1) + root->val;

        if (!root->left && !root->right)
            return num;

        if (root->left)
            sum += __sumRootToLeaf(root->left, num);

        if (root->right)
            sum += __sumRootToLeaf(root->right, num);

        return sum;
    }

    int sumRootToLeaf(TreeNode* root) {
        if (root == NULL)
            return 0;
        return __sumRootToLeaf(root, 0);
    }
};
