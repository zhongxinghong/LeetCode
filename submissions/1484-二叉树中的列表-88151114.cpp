/**
 * Submission ID: 88151114
 * Question ID: 1484
 * Question Title: 二叉树中的列表
 * Question URL: https://leetcode-cn.com/problems/linked-list-in-binary-tree/
 * Solution Time: 2020-07-15 20:34:34
 * Solution Test Result: 61 / 61
 * Solution Status: Accepted
 * Solution Memory: 22 MB
 * Solution Runtime: 40 ms
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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

    bool isMatch(ListNode *head, TreeNode *root)
    {
        if (head && !root)
            return false;

        if (head == NULL)
            return true;

        if (head->val != root->val)
            return false;

        if (isMatch(head->next, root->left))
            return true;

        if (isMatch(head->next, root->right))
            return true;

        return false;
    }

    bool isSubPath(ListNode* head, TreeNode* root)
    {
        if (isMatch(head, root))
            return true;

        if (root && isSubPath(head, root->left))
            return true;

        if (root && isSubPath(head, root->right))
            return true;

        return false;
    }
};
