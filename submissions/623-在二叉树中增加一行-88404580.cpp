/**
 * Submission ID: 88404580
 * Question ID: 623
 * Question Title: 在二叉树中增加一行
 * Question URL: https://leetcode-cn.com/problems/add-one-row-to-tree/
 * Solution Time: 2020-07-16 17:04:15
 * Solution Test Result: 109 / 109
 * Solution Status: Accepted
 * Solution Memory: 25.6 MB
 * Solution Runtime: 20 ms
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

    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (root == NULL)
            return root;

        std::queue<Node2> q;
        TreeNode *hd = new TreeNode(), *p;
        hd->left = root;

        q.push({hd, 0});

        for (; !q.empty(); q.pop())
        {
            const Node2 &ele = q.front();

            if (ele.depth == d)
                break;

            if (ele.depth == d - 1)
            {
                if (ele.node->left)
                {
                    p = ele.node->left;
                    ele.node->left = new TreeNode(v);
                    ele.node->left->left = p;
                }

                if (ele.node->right)
                {
                    p = ele.node->right;
                    ele.node->right = new TreeNode(v);
                    ele.node->right->right = p;
                }

                if (!ele.node->left)
                    ele.node->left = new TreeNode(v);

                if (!ele.node->right)
                    ele.node->right = new TreeNode(v);
            }

            if (ele.node->left)
                q.push({ele.node->left, ele.depth + 1});

            if (ele.node->right)
                q.push({ele.node->right, ele.depth + 1});
        }

        root = hd->left;
        delete hd;

        return root;
    }
};
