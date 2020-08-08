/**
 * Submission ID: 89370384
 * Question ID: 515
 * Question Title: 在每个树行中找最大值
 * Question URL: https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/
 * Solution Time: 2020-07-19 18:04:57
 * Solution Test Result: 78 / 78
 * Solution Status: Accepted
 * Solution Memory: 22.5 MB
 * Solution Runtime: 24 ms
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

    struct Node2
    {
        TreeNode *node;
        int depth;
    };

    vector<int> largestValues(TreeNode* root)
    {
        std::vector<int> ret;
        std::queue<Node2> q;

        if (root == NULL)
            return ret;

        q.push({root, 0});

        for (; !q.empty(); q.pop())
        {
            const Node2 &ele = q.front();

            if (ele.depth == ret.size())
                ret.push_back(INT_MIN);

            ret[ret.size() - 1] = std::max(ret[ret.size() - 1], ele.node->val);

            if (ele.node->left)
                q.push({ele.node->left, ele.depth + 1});

            if (ele.node->right)
                q.push({ele.node->right, ele.depth + 1});
        }

        return ret;
    }
};
