/**
 * Submission ID: 88663001
 * Question ID: 687
 * Question Title: 最长同值路径
 * Question URL: https://leetcode-cn.com/problems/longest-univalue-path/
 * Solution Time: 2020-07-17 14:28:25
 * Solution Test Result: 71 / 71
 * Solution Status: Accepted
 * Solution Memory: 72.2 MB
 * Solution Runtime: 304 ms
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

    int findPath(const TreeNode *root, const int &target)
    {
        if (root->val != target)
            return 0;

        int ret = 1;

        if (root->left)
            ret = std::max(ret, findPath(root->left, target) + 1);

        if (root->right)
            ret = std::max(ret, findPath(root->right, target) + 1);

        return ret;
    }

    int __longestUnivaluePath(const TreeNode *root, int &ret)
    {
        int s = 1, ls, rs;

        if (root->left)
        {
            s += findPath(root->left, root->val);
            __longestUnivaluePath(root->left, ret);
        }

        if (root->right)
        {
            s += findPath(root->right, root->val);
            __longestUnivaluePath(root->right, ret);
        }

        ret = std::max(ret, s - 1);
        return s - 1;
    }

    int longestUnivaluePath(TreeNode* root) {
        int ret = 0;

        if (root == NULL)
            return ret;

        __longestUnivaluePath(root, ret);

        return ret;
    }
};
