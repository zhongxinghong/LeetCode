/**
 * Submission ID: 89400997
 * Question ID: 893
 * Question Title: 二叉树中所有距离为 K 的结点
 * Question URL: https://leetcode-cn.com/problems/all-nodes-distance-k-in-binary-tree/
 * Solution Time: 2020-07-19 20:20:06
 * Solution Test Result: 57 / 57
 * Solution Status: Accepted
 * Solution Memory: 14.1 MB
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

    void build_g(std::vector<std::vector<int>> &g, TreeNode *root, TreeNode *parent)
    {
        g[root->val].push_back(parent->val);
        g[parent->val].push_back(root->val);

        if (root->left)
            build_g(g, root->left, root);

        if (root->right)
            build_g(g, root->right, root);
    }

    void dfs(
        const std::vector<std::vector<int>> &g,
        std::vector<int> &ret,
        int ix,
        int pix,
        int dep,
        const int &K)
    {
        int i, j;

        if (dep == K)
        {
            ret.push_back(ix);
            return;
        }

        for (i = 0; i < g[ix].size(); ++i)
        {
            j = g[ix][i];

            if (j == pix)
                continue;

            dfs(g, ret, j, ix, dep + 1, K);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K)
    {
        std::vector<std::vector<int>> g(512);
        std::vector<int> ret;

        if (root->left)
            build_g(g, root->left, root);

        if (root->right)
            build_g(g, root->right, root);

        dfs(g, ret, target->val, -1, 0, K);
        return ret;
    }
};
