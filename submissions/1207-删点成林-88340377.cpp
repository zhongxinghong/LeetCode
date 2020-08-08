/**
 * Submission ID: 88340377
 * Question ID: 1207
 * Question Title: 删点成林
 * Question URL: https://leetcode-cn.com/problems/delete-nodes-and-return-forest/
 * Solution Time: 2020-07-16 14:12:28
 * Solution Test Result: 111 / 111
 * Solution Status: Accepted
 * Solution Memory: 26.7 MB
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        std::set<TreeNode *> ret;
        std::set<int> to_delete_set(to_delete.begin(), to_delete.end());
        std::stack<TreeNode *> st;
        TreeNode *p, *q, *hd;

        hd = new TreeNode();
        hd->left = root;
        st.push(hd);
        ret.insert(root);

        while (!st.empty())
        {
            p = st.top();
            st.pop();

            if ((q = p->left) && to_delete_set.find(q->val) != to_delete_set.end())
            {
                if (q->left)
                    ret.insert(q->left);
                if (q->right)
                    ret.insert(q->right);
                ret.erase(q);
                st.push(q);
                p->left = NULL;
            }

            if ((q = p->right) && to_delete_set.find(q->val) != to_delete_set.end())
            {
                if (q->left)
                    ret.insert(q->left);
                if (q->right)
                    ret.insert(q->right);
                ret.erase(q);
                st.push(q);
                p->right = NULL;
            }

            if (p->left)
                st.push(p->left);

            if (p->right)
                st.push(p->right);
        }

        return std::vector<TreeNode *>(ret.begin(), ret.end());
    }
};
