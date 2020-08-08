/**
 * Submission ID: 86867982
 * Question ID: 23
 * Question Title: 合并K个排序链表
 * Question URL: https://leetcode-cn.com/problems/merge-k-sorted-lists/
 * Solution Time: 2020-07-11 21:05:15
 * Solution Test Result: 131 / 131
 * Solution Status: Accepted
 * Solution Memory: 11.1 MB
 * Solution Runtime: 52 ms
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
        ListNode *p, *hd = new ListNode(0);

        for (size_t i = 0; i < lists.size(); ++i)
        {
            for (p = lists[i]; p != NULL; p = p->next)
            {
                pq.push(p->val);
            }
        }

        p = hd;

        while (!pq.empty())
        {
            p = p->next = new ListNode(pq.top());
            pq.pop();
        }

        p = hd->next;
        delete hd;

        return p;
    }
};
