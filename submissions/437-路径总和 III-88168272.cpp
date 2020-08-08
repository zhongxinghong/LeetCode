/**
 * Submission ID: 88168272
 * Question ID: 437
 * Question Title: 路径总和 III
 * Question URL: https://leetcode-cn.com/problems/path-sum-iii/
 * Solution Time: 2020-07-15 21:26:59
 * Solution Test Result: 126 / 126
 * Solution Status: Accepted
 * Solution Memory: 16.1 MB
 * Solution Runtime: 44 ms
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

    void dfs_solve(TreeNode *root, int cumsum, int target, int &cnt)
    {
        if (root == NULL)
            return;

        cumsum += root->val;

        if (cumsum == target)
            cnt++;

        dfs_solve(root->left, cumsum, target, cnt);
        dfs_solve(root->right, cumsum, target, cnt);
    }

    int pathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return 0;

        int cnt = 0;
        dfs_solve(root, 0, sum, cnt);

        return cnt + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};
