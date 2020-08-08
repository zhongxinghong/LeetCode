/**
 * Submission ID: 90595018
 * Question ID: 100286
 * Question Title: 合并两个排序的链表
 * Question URL: https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/
 * Solution Time: 2020-07-23 10:00:54
 * Solution Test Result: 218 / 218
 * Solution Status: Accepted
 * Solution Memory: 20.4 MB
 * Solution Runtime: 48 ms
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *hd = new ListNode(0), *p = hd;

        while (l1 != NULL || l2 != NULL)
        {
            if (l2 == NULL || (l1 != NULL && l1->val < l2->val))
            {
                p = p->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else
            {
                p = p->next = new ListNode(l2->val);
                l2 = l2->next;
            }
        }

        p = hd->next;
        delete hd;

        return p;
    }
};
