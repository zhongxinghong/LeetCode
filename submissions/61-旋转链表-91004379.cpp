/**
 * Submission ID: 91004379
 * Question ID: 61
 * Question Title: 旋转链表
 * Question URL: https://leetcode-cn.com/problems/rotate-list/
 * Solution Time: 2020-07-24 13:39:13
 * Solution Test Result: 231 / 231
 * Solution Status: Accepted
 * Solution Memory: 7.1 MB
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
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (head == NULL)
            return head;

        int i, n = 1;
        ListNode *p = head, *q;

        while (p->next)
        {
            p = p->next;
            n++;
        }

        p->next = q = head;

        for (i = n - k % n; i; --i)
        {
            p = q;
            q = q->next;
        }

        p->next = NULL;

        return q;
    }
};
