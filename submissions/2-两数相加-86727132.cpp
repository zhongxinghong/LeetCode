/**
 * Submission ID: 86727132
 * Question ID: 2
 * Question Title: 两数相加
 * Question URL: https://leetcode-cn.com/problems/add-two-numbers/
 * Solution Time: 2020-07-11 11:38:14
 * Solution Test Result: 1563 / 1563
 * Solution Status: Accepted
 * Solution Memory: 9.2 MB
 * Solution Runtime: 20 ms
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ret = NULL, *p;
        int s;
        bool cin = false;

        while (l1 != NULL || l2 != NULL || cin)
        {
            s = (l1 == NULL ? 0 : l1->val) + (l2 == NULL ? 0 : l2->val) + cin;

            if (s > 9)
            {
                cin = true;
                s -= 10;
            }
            else
            {
                cin = false;
            }

            if (ret == NULL)
            {
                p = ret = new ListNode(s);
            }
            else
            {
                p->next = new ListNode(s);
                p = p->next;
            }

            l1 = (l1 == NULL ? NULL : l1->next);
            l2 = (l2 == NULL ? NULL : l2->next);
        }

        if (ret == NULL)
        {
            ret = new ListNode(0);
        }

        return ret;
    }
};
