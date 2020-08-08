/**
 * Submission ID: 88350675
 * Question ID: 222
 * Question Title: 完全二叉树的节点个数
 * Question URL: https://leetcode-cn.com/problems/count-complete-tree-nodes/
 * Solution Time: 2020-07-16 14:46:43
 * Solution Test Result: 18 / 18
 * Solution Status: Accepted
 * Solution Memory: 31.8 MB
 * Solution Runtime: 52 ms
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
    int countNodes(TreeNode* root) {
        int sum = 0;
        std::queue<TreeNode *> q;
        TreeNode *p;

        if (root == NULL)
            return sum;

        q.push(root);

        while (!q.empty())
        {
            p = q.front();
            q.pop();

            sum++;

            if (p->left)
                q.push(p->left);

            if (p->right)
                q.push(p->right);
        }

        return sum;
    }
};
