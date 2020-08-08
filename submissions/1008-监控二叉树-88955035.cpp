/**
 * Submission ID: 88955035
 * Question ID: 1008
 * Question Title: 监控二叉树
 * Question URL: https://leetcode-cn.com/problems/binary-tree-cameras/
 * Solution Time: 2020-07-18 12:13:05
 * Solution Test Result: 170 / 170
 * Solution Status: Accepted
 * Solution Memory: 21.2 MB
 * Solution Runtime: 28 ms
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

    // return value:
    //   0 -- this node has a camera
    //   1 -- this node can be visited, but it doesn't have a camera
    //   2 -- this node can't be visited

    int dfs(TreeNode *root, int &cnt)
    {
        if (root == NULL)
            return 1;

        int lstate = dfs(root->left, cnt);
        int rstate = dfs(root->right, cnt);

        if (lstate == 2 || rstate == 2)
        {
            cnt++;
            return 0;
        }

        if (lstate == 0 || rstate == 0)
            return 1;

        return 2;
    }

    int minCameraCover(TreeNode* root)
    {
        int cnt = 0, state;

        if (root == NULL)
            return cnt;

        state = dfs(root, cnt);

        if (state == 2)
            cnt++;

        return cnt;
    }
};
