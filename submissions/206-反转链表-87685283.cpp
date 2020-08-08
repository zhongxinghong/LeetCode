/**
 * Submission ID: 87685283
 * Question ID: 206
 * Question Title: 反转链表
 * Question URL: https://leetcode-cn.com/problems/reverse-linked-list/
 * Solution Time: 2020-07-14 14:05:09
 * Solution Test Result: 27 / 27
 * Solution Status: Accepted
 * Solution Memory: 8.3 MB
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
    ListNode* reverseList(ListNode* head) {
        ListNode *p = NULL, *q = head, *t;
        while (q != NULL)
        {
            t = q->next;
            q->next = p;
            p = q;
            q = t;
        }
        return p;
    }
};
