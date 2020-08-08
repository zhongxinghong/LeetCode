/**
 * Submission ID: 91094230
 * Question ID: 83
 * Question Title: 删除排序链表中的重复元素
 * Question URL: https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
 * Solution Time: 2020-07-24 17:24:35
 * Solution Test Result: 165 / 165
 * Solution Status: Accepted
 * Solution Memory: 7.6 MB
 * Solution Runtime: 8 ms
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == NULL)
            return head;

        ListNode *cur = head, *p;

        for (p = head->next; p; p = p->next)
        {
            if (cur->val == p->val)
                continue;

            cur = cur->next = p;
        }

        cur->next = NULL;

        return head;
    }
};
