/**
 * Submission ID: 88313022
 * Question ID: 652
 * Question Title: 寻找重复的子树
 * Question URL: https://leetcode-cn.com/problems/find-duplicate-subtrees/
 * Solution Time: 2020-07-16 11:52:46
 * Solution Test Result: 169 / 169
 * Solution Status: Accepted
 * Solution Memory: 113.7 MB
 * Solution Runtime: 980 ms
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    std::string serialize(TreeNode *root)
    {
        std::string ret;
        TreeNode *p;
        std::stack<TreeNode *> st;

        if (root == NULL)
            return ret;

        st.push(root);

        while (!st.empty())
        {
            p = st.top();
            st.pop();

            if (p == NULL)
            {
                ret.push_back(',');
                continue;
            }

            ret += std::to_string(p->val);
            ret.push_back(',');

            st.push(p->left);
            st.push(p->right);
        }

        return ret;
    }

    void __findDuplicateSubtrees(std::vector<TreeNode *> &ret, std::map<std::string, int> &mp, TreeNode *root)
    {
        if (root == NULL)
            return;

        std::string s = serialize(root);

        switch (mp[s])
        {
        case 0:
            mp[s]++;
            break;
        case 1:
            mp[s]++;
            ret.push_back(root);
            break;
        default:
            break;
        }

        __findDuplicateSubtrees(ret, mp, root->left);
        __findDuplicateSubtrees(ret, mp, root->right);
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        std::vector<TreeNode *> ret;
        std::map<std::string, int> mp;
        __findDuplicateSubtrees(ret, mp, root);
        return ret;
    }
};
