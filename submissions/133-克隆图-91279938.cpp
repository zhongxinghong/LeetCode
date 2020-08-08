/**
 * Submission ID: 91279938
 * Question ID: 133
 * Question Title: 克隆图
 * Question URL: https://leetcode-cn.com/problems/clone-graph/
 * Solution Time: 2020-07-25 14:00:16
 * Solution Test Result: 21 / 21
 * Solution Status: Accepted
 * Solution Memory: 9 MB
 * Solution Runtime: 12 ms
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    Node *__cloneGraph(std::vector<Node *> &v, Node *node)
    {
        if (v[node->val])
            return v[node->val];

        v[node->val] = new Node(node->val);

        for (auto p : node->neighbors)
            v[node->val]->neighbors.push_back(__cloneGraph(v, p));

        return v[node->val];
    }

    Node* cloneGraph(Node* node)
    {
        std::vector<Node *> v(128);

        if (node == NULL)
            return NULL;

        return __cloneGraph(v, node);
    }
};
