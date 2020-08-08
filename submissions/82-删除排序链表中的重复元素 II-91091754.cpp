/**
 * Submission ID: 91091754
 * Question ID: 82
 * Question Title: 删除排序链表中的重复元素 II
 * Question URL: https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/
 * Solution Time: 2020-07-24 17:18:36
 * Solution Test Result: 166 / 166
 * Solution Status: Accepted
 * Solution Memory: 7.4 MB
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

        ListNode *hd = new ListNode(0);
        hd->next = head;

        ListNode *p, *prev = hd, *cur = prev->next;
        int cnt = 1;

        for (p = head->next; p; p = p->next)
        {
            if (p->val == cur->val)
            {
                cnt++;
            }
            else
            {
                if (cnt == 1)
                    prev = prev->next = cur;
                else
                    prev->next = p;

                cur = p;
                cnt = 1;
            }
        }

        if (cnt == 1)
            prev = prev->next = cur;
        else
            prev->next = p;

        p = hd->next;
        delete hd;

        return p;
    }
};
