/**
 * Submission ID: 91230046
 * Question ID: 86
 * Question Title: 分隔链表
 * Question URL: https://leetcode-cn.com/problems/partition-list/
 * Solution Time: 2020-07-25 10:25:21
 * Solution Test Result: 166 / 166
 * Solution Status: Accepted
 * Solution Memory: 7 MB
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
    ListNode* partition(ListNode* head, int x)
    {
        ListNode *lt = new ListNode(0), *ge = new ListNode(0), *hdlt = lt, *hdge = ge;
        ListNode *p = head, *q;

        while (p)
        {
            if (p->val < x)
                lt = lt->next = p;
            else
                ge = ge->next = p;

            q = p->next;
            p->next = NULL;
            p = q;
        }

        lt->next = hdge->next;
        p = hdlt->next;

        delete hdlt;
        delete hdge;

        return p;
    }
};
