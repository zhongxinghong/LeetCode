/**
 * Submission ID: 88385237
 * Question ID: 1114
 * Question Title: 从二叉搜索树到更大和树
 * Question URL: https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/
 * Solution Time: 2020-07-16 16:15:40
 * Solution Test Result: 28 / 28
 * Solution Status: Accepted
 * Solution Memory: 8.7 MB
 * Solution Runtime: 0 ms
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

        bst2vec(v, root->right);
        v.push_back(root);
        bst2vec(v, root->left);
    }

    TreeNode* bstToGst(TreeNode* root) {
        std::vector<TreeNode *> v;
        bst2vec(v, root);

        for (int i = 1; i < v.size(); ++i)
            v[i]->val += v[i - 1]->val;

        return root;
    }
};
