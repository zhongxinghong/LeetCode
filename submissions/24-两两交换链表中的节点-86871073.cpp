/**
 * Submission ID: 86871073
 * Question ID: 24
 * Question Title: 两两交换链表中的节点
 * Question URL: https://leetcode-cn.com/problems/swap-nodes-in-pairs/
 * Solution Time: 2020-07-11 21:17:20
 * Solution Test Result: 55 / 55
 * Solution Status: Accepted
 * Solution Memory: 6.5 MB
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *p, *q, *hd;

        if (head == NULL)
            return head;

        hd = new ListNode(0);
        hd->next = head;

        for (p = hd, q = p->next; q != NULL && q->next != NULL; p = q, q = p->next)
        {
            p->next = q->next;
            q->next = p->next->next;
            p->next->next = q;
        }

        p = hd->next;
        delete hd;

        return p;
    }
};
