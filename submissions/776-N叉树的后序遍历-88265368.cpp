/**
 * Submission ID: 88265368
 * Question ID: 776
 * Question Title: N叉树的后序遍历
 * Question URL: https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/
 * Solution Time: 2020-07-16 09:52:21
 * Solution Test Result: 37 / 37
 * Solution Status: Accepted
 * Solution Memory: 11.6 MB
 * Solution Runtime: 64 ms
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

    void _postorder(std::vector<int> &ret, Node *root)
    {
        if (root == NULL)
            return;

        for (size_t i = 0; i < root->children.size(); ++i)
            _postorder(ret, root->children[i]);
        ret.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        std::vector<int> ret;
        _postorder(ret, root);

        return ret;
    }
};
