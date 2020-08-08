/**
 * Submission ID: 88872524
 * Question ID: 1093
 * Question Title: 从先序遍历还原二叉树
 * Question URL: https://leetcode-cn.com/problems/recover-a-tree-from-preorder-traversal/
 * Solution Time: 2020-07-18 01:47:23
 * Solution Test Result: 104 / 104
 * Solution Status: Accepted
 * Solution Memory: 19.5 MB
 * Solution Runtime: 36 ms
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
    TreeNode* recoverFromPreorder(string S) {
        if (S.empty())
            return NULL;

        int i = 0, n = S.size(), x, dep;
        std::vector<TreeNode *> st;
        TreeNode *p;

        while (i < n)
        {
            for (dep = 0; i < n && S[i] == '-'; ++i, ++dep)
                ;

            sscanf(&S[i], "%d", &x);
            for (; i < n && isdigit(S[i]); ++i)
                ;

            while (st.size() > dep)
                st.pop_back();

            p = new TreeNode(x);

            if (!st.empty())
            {
                if (!st.back()->left)
                    st.back()->left = p;
                else
                    st.back()->right = p;
            }

            st.push_back(p);
        }

        return st.front();
    }
};
