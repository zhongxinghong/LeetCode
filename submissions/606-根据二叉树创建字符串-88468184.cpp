/**
 * Submission ID: 88468184
 * Question ID: 606
 * Question Title: 根据二叉树创建字符串
 * Question URL: https://leetcode-cn.com/problems/construct-string-from-binary-tree/
 * Solution Time: 2020-07-16 20:40:33
 * Solution Test Result: 162 / 162
 * Solution Status: Accepted
 * Solution Memory: 23.6 MB
 * Solution Runtime: 20 ms
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

    void preorder_build(std::string &ret, TreeNode *root)
    {
        if (root == NULL)
            return;

        ret += std::to_string(root->val);

        if (!root->left && !root->right)
            return;

        ret.push_back('(');
        preorder_build(ret, root->left);
        ret.push_back(')');

        if (!root->right)
            return;

        ret.push_back('(');
        preorder_build(ret, root->right);
        ret.push_back(')');
    }

    string tree2str(TreeNode* t) {
        std::string ret;
        preorder_build(ret, t);
        return ret;
    }
};
