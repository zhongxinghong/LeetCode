/**
 * Submission ID: 88956473
 * Question ID: 513
 * Question Title: 找树左下角的值
 * Question URL: https://leetcode-cn.com/problems/find-bottom-left-tree-value/
 * Solution Time: 2020-07-18 12:21:12
 * Solution Test Result: 74 / 74
 * Solution Status: Accepted
 * Solution Memory: 22.4 MB
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
        std::queue<Node2> q;
        std::vector<int> lmost;

        q.push({root, 0});

        for (; !q.empty(); q.pop())
        {
            const Node2 &ele = q.front();

            if (ele.depth == lmost.size())
                lmost.push_back(ele.node->val);

            if (ele.node->left)
                q.push({ele.node->left, ele.depth + 1});

            if (ele.node->right)
                q.push({ele.node->right, ele.depth + 1});
        }

        return lmost.back();
    }
};
