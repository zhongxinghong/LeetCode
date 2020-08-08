/**
 * Submission ID: 91259777
 * Question ID: 103
 * Question Title: 二叉树的锯齿形层次遍历
 * Question URL: https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/
 * Solution Time: 2020-07-25 11:57:14
 * Solution Test Result: 33 / 33
 * Solution Status: Accepted
 * Solution Memory: 11.2 MB
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

    struct node_s
    {
        TreeNode *node;
        int depth;
    };

    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        int i;
        std::vector<std::vector<int>> ret;
        std::queue<node_s> q;

        if (root == NULL)
            return ret;

        q.push({root, 0});

        for (; !q.empty(); q.pop())
        {
            const auto &ele = q.front();

            if (ele.depth == ret.size())
                ret.push_back(std::vector<int>());

            ret.back().push_back(ele.node->val);

            if (ele.node->left)
                q.push({ele.node->left, ele.depth + 1});

            if (ele.node->right)
                q.push({ele.node->right, ele.depth + 1});
        }

        for (i = 0; i < ret.size(); ++i)
        {
            if (i % 2 == 1)
                std::reverse(ret[i].begin(), ret[i].end());
        }

        return ret;
    }
};
