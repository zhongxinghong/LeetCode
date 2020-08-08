/**
 * Submission ID: 88268765
 * Question ID: 776
 * Question Title: N叉树的后序遍历
 * Question URL: https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/
 * Solution Time: 2020-07-16 10:02:46
 * Solution Test Result: 37 / 37
 * Solution Status: Accepted
 * Solution Memory: 11.9 MB
 * Solution Runtime: 48 ms
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

    struct Node2
    {
        Node *node;
        bool visited;

        Node2() : Node2(nullptr) {}
        Node2(Node *node) : node(node), visited(false) {}
    };

    vector<int> postorder(Node* root) {
        std::vector<int> ret;
        std::stack<Node2> st;

        if (root == NULL)
            return ret;

        st.push(Node2(root));

        while (!st.empty())
        {
            Node2 &ele = st.top();
            if (!ele.visited)
            {
                for (size_t i = ele.node->children.size() - 1; i < ele.node->children.size(); --i)
                    st.push(ele.node->children[i]);
                ele.visited = true;
            }
            else
            {
                ret.push_back(ele.node->val);
                st.pop();
            }
        }

        return ret;
    }
};
