/**
 * Submission ID: 88359755
 * Question ID: 100287
 * Question Title: 树的子结构
 * Question URL: https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/
 * Solution Time: 2020-07-16 15:12:13
 * Solution Test Result: 48 / 48
 * Solution Status: Accepted
 * Solution Memory: 36.5 MB
 * Solution Runtime: 80 ms
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
    struct NodePair
    {
        TreeNode *p;
        TreeNode *q;
    };

    bool isMatch(TreeNode *A, TreeNode *B)
    {
        std::queue<NodePair> q;

        for (q.push({A, B}); !q.empty(); q.pop())
        {
            const NodePair &ele = q.front();

            if (!ele.q)
                continue;

            if (!ele.p)
                return false;

            if (ele.p->val != ele.q->val)
                return false;

            q.push({ele.p->left, ele.q->left});
            q.push({ele.p->right, ele.q->right});
        }

        return true;
    }

    bool __isSubStructure(TreeNode* A, TreeNode* B) {
        if (!B)
            return true;

        if (!A)
            return false;

        if (A->val == B->val && isMatch(A, B))
            return true;

        return __isSubStructure(A->left, B) || __isSubStructure(A->right, B);
    }

    bool isSubStructure(TreeNode* A, TreeNode* B)
    {
        if (!B)
            return false;
        return __isSubStructure(A, B);
    }
};
