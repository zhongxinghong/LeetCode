/**
 * Submission ID: 88319450
 * Question ID: 1243
 * Question Title: 祖父节点值为偶数的节点和
 * Question URL: https://leetcode-cn.com/problems/sum-of-nodes-with-even-valued-grandparent/
 * Solution Time: 2020-07-16 12:26:53
 * Solution Test Result: 14 / 14
 * Solution Status: Accepted
 * Solution Memory: 38 MB
 * Solution Runtime: 64 ms
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
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;

        if (root == NULL)
            return 0;

        sum += sumEvenGrandparent(root->left) + sumEvenGrandparent(root->right);

        if (root->val % 2)
            return sum;

        if (root->left)
        {
            if (root->left->left)
                sum += root->left->left->val;
            if (root->left->right)
                sum += root->left->right->val;
        }

        if (root->right)
        {
            if (root->right->left)
                sum += root->right->left->val;
            if (root->right->right)
                sum += root->right->right->val;
        }

        return sum;
    }
};
