/**
 * Submission ID: 91263631
 * Question ID: 107
 * Question Title: 二叉树的层次遍历 II
 * Question URL: https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/
 * Solution Time: 2020-07-25 12:16:58
 * Solution Test Result: 34 / 34
 * Solution Status: Accepted
 * Solution Memory: 11.5 MB
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

    struct node_s
    {
        TreeNode *node;
        int depth;
    };

    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        std::vector<std::vector<int>> ret;
        std::queue<node_s> q;

        if (root == NULL)
            return ret;

        q.push({root, 0});

        for (; !q.empty(); q.pop())
        {
            const auto &ele = q.front();

            if (ele.depth == ret.size())
                ret.push_back({});

            ret.back().push_back(ele.node->val);

            if (ele.node->left)
                q.push({ele.node->left, ele.depth + 1});

            if (ele.node->right)
                q.push({ele.node->right, ele.depth + 1});
        }

        std::reverse(ret.begin(), ret.end());

        return ret;
    }
};
