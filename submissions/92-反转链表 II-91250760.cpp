/**
 * Submission ID: 91250760
 * Question ID: 92
 * Question Title: 反转链表 II
 * Question URL: https://leetcode-cn.com/problems/reverse-linked-list-ii/
 * Solution Time: 2020-07-25 11:25:09
 * Solution Test Result: 44 / 44
 * Solution Status: Accepted
 * Solution Memory: 6.4 MB
 * Solution Runtime: 4 ms
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
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        int i;
        ListNode *hd = new ListNode(0);
        ListNode *prev, *cur, *p, *q;

        hd->next = head;
        p = hd;

        for (i = 1; i < m; ++i)
            p = p->next;

        prev = NULL;
        cur = p->next;

        for (i = m; i <= n; ++i)
        {
            q = cur->next;
            cur->next = prev;
            prev = cur;
            cur = q;
        }

        q = p->next;
        p->next = prev;
        q->next = cur;

        p = hd->next;
        delete hd;

        return p;
    }
};
