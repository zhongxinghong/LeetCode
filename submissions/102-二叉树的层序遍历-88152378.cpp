/**
 * Submission ID: 88152378
 * Question ID: 102
 * Question Title: 二叉树的层序遍历
 * Question URL: https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
 * Solution Time: 2020-07-15 20:38:38
 * Solution Test Result: 34 / 34
 * Solution Status: Accepted
 * Solution Memory: 11.5 MB
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

    struct NodeWithDepth
    {
        TreeNode *node;
        int depth;
    };

    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int> > ret;

        if (root == NULL)
            return ret;

        std::queue<NodeWithDepth> q;
        q.push({root, 0});

        while (!q.empty())
        {
            const NodeWithDepth &ele = q.front();

            if (ret.size() == ele.depth)
                ret.push_back(std::vector<int>());

            ret[ele.depth].push_back(ele.node->val);

            if (ele.node->left)
                q.push({ele.node->left, ele.depth + 1});

            if (ele.node->right)
                q.push({ele.node->right, ele.depth + 1});

            q.pop();
        }

        return ret;
    }
};
