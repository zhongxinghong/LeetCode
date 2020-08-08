/**
 * Submission ID: 88260982
 * Question ID: 101
 * Question Title: 对称二叉树
 * Question URL: https://leetcode-cn.com/problems/symmetric-tree/
 * Solution Time: 2020-07-16 09:37:41
 * Solution Test Result: 195 / 195
 * Solution Status: Accepted
 * Solution Memory: 12.7 MB
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

    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;

        TreeNode *n1, *n2;
        std::queue<TreeNode *> q;

        q.push(root->left);
        q.push(root->right);

        while (!q.empty())
        {
            n1 = q.front(); q.pop();
            n2 = q.front(); q.pop();

            if (!n1 && !n2)
                continue;

            if ((n1 && !n2) || (!n1 && n2) || (n1->val != n2->val))
                return false;

            q.push(n1->left);
            q.push(n2->right);

            q.push(n1->right);
            q.push(n2->left);
        }

        return true;
    }
};
