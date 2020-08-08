/**
 * Submission ID: 86860570
 * Question ID: 19
 * Question Title: 删除链表的倒数第N个节点
 * Question URL: https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
 * Solution Time: 2020-07-11 20:33:40
 * Solution Test Result: 208 / 208
 * Solution Status: Accepted
 * Solution Memory: 6.5 MB
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *hd = new ListNode(0);
        hd->next = head;

        ListNode *p = hd, *q = p;

        while (n--)
            q = q->next;

        while (q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }

        q = p->next;
        p->next = q->next;
        delete q;

        p = hd->next;
        delete hd;

        return p;
    }
};
