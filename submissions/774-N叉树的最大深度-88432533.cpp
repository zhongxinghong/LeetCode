/**
 * Submission ID: 88432533
 * Question ID: 774
 * Question Title: N叉树的最大深度
 * Question URL: https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree/
 * Solution Time: 2020-07-16 18:33:25
 * Solution Test Result: 37 / 37
 * Solution Status: Accepted
 * Solution Memory: 10.9 MB
 * Solution Runtime: 40 ms
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL)
            return 0;

        int depth = 1;

        for (size_t i = 0; i < root->children.size(); ++i)
            depth = std::max(depth, maxDepth(root->children[i]) + 1);

        return depth;
    }
};
