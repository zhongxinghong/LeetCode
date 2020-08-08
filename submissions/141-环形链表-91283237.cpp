/**
 * Submission ID: 91283237
 * Question ID: 141
 * Question Title: 环形链表
 * Question URL: https://leetcode-cn.com/problems/linked-list-cycle/
 * Solution Time: 2020-07-25 14:18:05
 * Solution Test Result: 17 / 17
 * Solution Status: Accepted
 * Solution Memory: 7.5 MB
 * Solution Runtime: 12 ms
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
    bool hasCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return false;

        ListNode *slow = head, *fast = head->next;

        while (fast != slow)
        {
            if (fast->next == NULL || fast->next->next == NULL)
                return false;

            fast = fast->next->next;
            slow = slow->next;
        }

        return true;
    }
};
