/**
 * Submission ID: 89476793
 * Question ID: 766
 * Question Title: 扁平化多级双向链表
 * Question URL: https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list/
 * Solution Time: 2020-07-20 01:14:02
 * Solution Test Result: 22 / 22
 * Solution Status: Accepted
 * Solution Memory: 7.9 MB
 * Solution Runtime: 8 ms
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:

    Node *__flatten(Node *head, Node *&tail)
    {
        Node *hd = new Node(), *p, *q, *r;

        hd->next = head;
        p = hd;

        do
        {
            p = p->next;

            if (!p->child)
                continue;

            q = p->next;

            p->next = __flatten(p->child, r);
            p->next->prev = p;
            p->child = NULL;

            p = r;

            r->next = q;

            if (q != NULL)
                q->prev = r;

        } while (p->next);

        delete hd;

        tail = p;
        return head;
    }

    Node* flatten(Node* head)
    {
        if (head == NULL)
            return NULL;

        Node *p;
        return __flatten(head, p);
    }
};
