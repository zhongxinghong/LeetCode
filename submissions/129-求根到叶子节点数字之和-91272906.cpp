/**
 * Submission ID: 91272906
 * Question ID: 129
 * Question Title: 求根到叶子节点数字之和
 * Question URL: https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/
 * Solution Time: 2020-07-25 13:15:18
 * Solution Test Result: 110 / 110
 * Solution Status: Accepted
 * Solution Memory: 12.3 MB
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

    void dfs(TreeNode *root, int cur, int &sum)
    {
        cur = cur * 10 + root->val;

        if (!root->left && !root->right)
        {
            sum += cur;
            return;
        }

        if (root->left)
            dfs(root->left, cur, sum);

        if (root->right)
            dfs(root->right, cur, sum);
    }

    int sumNumbers(TreeNode* root)
    {
        int sum = 0;

        if (root == NULL)
            return 0;

        dfs(root, 0, sum);

        return sum;
    }
};
