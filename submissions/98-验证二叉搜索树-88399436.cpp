/**
 * Submission ID: 88399436
 * Question ID: 98
 * Question Title: 验证二叉搜索树
 * Question URL: https://leetcode-cn.com/problems/validate-binary-search-tree/
 * Solution Time: 2020-07-16 16:51:33
 * Solution Test Result: 75 / 75
 * Solution Status: Accepted
 * Solution Memory: 19 MB
 * Solution Runtime: 16 ms
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

    void bst2vec(std::vector<TreeNode *> &v, TreeNode *root)
    {
        if (!root)
            return;

        bst2vec(v, root->left);
        v.push_back(root);
        bst2vec(v, root->right);
    }

    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;

        std::vector<TreeNode *> v;
        bst2vec(v, root);

        for (size_t i = 0; i < v.size() - 1; ++i)
        {
            if (v[i]->val >= v[i + 1]->val)
                return false;
        }

        return true;
    }
};
