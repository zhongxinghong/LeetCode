/**
 * Submission ID: 88295502
 * Question ID: 235
 * Question Title: 二叉搜索树的最近公共祖先
 * Question URL: https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 * Solution Time: 2020-07-16 11:05:06
 * Solution Test Result: 27 / 27
 * Solution Status: Accepted
 * Solution Memory: 23.4 MB
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

    bool __findPath(std::vector<TreeNode *> &ret, TreeNode *root, TreeNode *p)
    {
        if (root == NULL)
            return false;

        if (root == p)
        {
            ret.push_back(root);
            return true;
        }

        if (__findPath(ret, root->left, p) || __findPath(ret, root->right, p))
        {
            ret.push_back(root);
            return true;
        }

        return false;
    }

    void findPath(std::vector<TreeNode *> &ret, TreeNode *root, TreeNode *p)
    {
        __findPath(ret, root, p);
        std::reverse(ret.begin(), ret.end());
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::vector<TreeNode *> p_path, q_path;

        findPath(p_path, root, p);
        findPath(q_path, root, q);

        int i, n = std::min(p_path.size(), q_path.size());

        for (i = 0; i < n - 1; ++i)
        {
            if (p_path[i + 1]->val != q_path[i + 1]->val)
                return p_path[i];
        }

        return p_path[n - 1];
    }
};
