/**
 * Submission ID: 88956676
 * Question ID: 513
 * Question Title: 找树左下角的值
 * Question URL: https://leetcode-cn.com/problems/find-bottom-left-tree-value/
 * Solution Time: 2020-07-18 12:22:21
 * Solution Test Result: 74 / 74
 * Solution Status: Accepted
 * Solution Memory: 22.2 MB
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

    int findBottomLeftValue(TreeNode* root) {
        int ret, depth = 0;
        std::queue<Node2> q;

        q.push({root, 0});

        for (; !q.empty(); q.pop())
        {
            const Node2 &ele = q.front();

            if (ele.depth == depth)
            {
                ret = ele.node->val;
                depth++;
            }

            if (ele.node->left)
                q.push({ele.node->left, ele.depth + 1});

            if (ele.node->right)
                q.push({ele.node->right, ele.depth + 1});
        }

        return ret;
    }
};
