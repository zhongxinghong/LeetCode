/**
 * Submission ID: 89258319
 * Question ID: 116
 * Question Title: 填充每个节点的下一个右侧节点指针
 * Question URL: https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/
 * Solution Time: 2020-07-19 11:46:07
 * Solution Test Result: 58 / 58
 * Solution Status: Accepted
 * Solution Memory: 17.7 MB
 * Solution Runtime: 40 ms
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:

    struct Node2
    {
        Node *node;
        int depth;
    };

    Node* connect(Node* root)
    {
        if (root == NULL)
            return root;

        int i, depth = -1;
        std::queue<Node2> q;
        Node *last = NULL;

        q.push({root, 0});

        for (; !q.empty(); q.pop())
        {
            const Node2 &ele = q.front();

            if (ele.depth > depth)
            {
                depth = ele.depth;
                last = NULL;
            }

            ele.node->next = last;
            last = ele.node;

            if (ele.node->right)
                q.push({ele.node->right, ele.depth + 1});

            if (ele.node->left)
                q.push({ele.node->left, ele.depth + 1});
        }

        return root;
    }
};
