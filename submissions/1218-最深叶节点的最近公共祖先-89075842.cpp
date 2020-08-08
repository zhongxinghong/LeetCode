/**
 * Submission ID: 89075842
 * Question ID: 1218
 * Question Title: 最深叶节点的最近公共祖先
 * Question URL: https://leetcode-cn.com/problems/lowest-common-ancestor-of-deepest-leaves/
 * Solution Time: 2020-07-18 18:22:18
 * Solution Test Result: 78 / 78
 * Solution Status: Accepted
 * Solution Memory: 21.6 MB
 * Solution Runtime: 16 ms
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

    // count deepest leaves and solve
    int dfs(TreeNode *root, const int &maxdep, int dep, const int &maxcnt, TreeNode *&ret)
    {
        int cnt = 0;

        if (ret != NULL)
            return cnt;

        if (dep == maxdep)
            cnt = 1;

        if (root->left)
            cnt += dfs(root->left, maxdep, dep + 1, maxcnt, ret);

        if (root->right)
            cnt += dfs(root->right, maxdep, dep + 1, maxcnt, ret);

        if (ret == NULL && cnt == maxcnt)
            ret = root;

        return cnt;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root)
    {
        int maxdep = -1, maxcnt = 0;
        std::queue<Node2> q;
        TreeNode *p, *ret = NULL;

        q.push({root, 0});

        for (; !q.empty(); q.pop())
        {
            const Node2 &ele = q.front();

            if (ele.depth == maxdep + 1)
            {
                maxcnt = 0;
                maxdep++;
            }

            maxcnt++;

            if (ele.node->left)
                q.push({ele.node->left, ele.depth + 1});

            if (ele.node->right)
                q.push({ele.node->right, ele.depth + 1});
        }

        dfs(root, maxdep, 0, maxcnt, ret);
        return ret;
    }
};
