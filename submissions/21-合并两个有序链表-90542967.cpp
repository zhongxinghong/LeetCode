/**
 * Submission ID: 90542967
 * Question ID: 21
 * Question Title: 合并两个有序链表
 * Question URL: https://leetcode-cn.com/problems/merge-two-sorted-lists/
 * Solution Time: 2020-07-23 00:25:25
 * Solution Test Result: 208 / 208
 * Solution Status: Accepted
 * Solution Memory: 14.7 MB
 * Solution Runtime: 4 ms
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *hd = new ListNode(), *p = hd;

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
