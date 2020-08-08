/**
 * Submission ID: 88071496
 * Question ID: 199
 * Question Title: 二叉树的右视图
 * Question URL: https://leetcode-cn.com/problems/binary-tree-right-side-view/
 * Solution Time: 2020-07-15 16:19:36
 * Solution Test Result: 211 / 211
 * Solution Status: Accepted
 * Solution Memory: 11.8 MB
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

    struct NodeWithDepth
    {
        TreeNode *node;
        int depth;
    };

    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> ret;
        std::queue<NodeWithDepth> q;

        if (root == NULL)
            return ret;

        q.push({root, 0});
        ret.push_back(root->val);

        while (!q.empty())
        {
            const NodeWithDepth &ele = q.front();

            if (ele.depth == ret.size())
                ret.push_back(ele.node->val);

            if (ele.node->right != NULL)
                q.push({ele.node->right, ele.depth + 1});
            if (ele.node->left != NULL)
                q.push({ele.node->left, ele.depth + 1});

            q.pop();
        }

        return ret;
    }
};
