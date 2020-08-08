/**
 * Submission ID: 90520972
 * Question ID: 100305
 * Question Title: 二叉搜索树与双向链表
 * Question URL: https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/
 * Solution Time: 2020-07-22 23:17:31
 * Solution Test Result: 50 / 50
 * Solution Status: Accepted
 * Solution Memory: 8 MB
 * Solution Runtime: 8 ms
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:

    void bst2vec(std::vector<Node *> &v, Node *root)
    {
        if (root == NULL)
            return;

        bst2vec(v, root->left);
        v.push_back(root);
        bst2vec(v, root->right);
    }

    Node* treeToDoublyList(Node* root)
    {
        if (root == NULL)
            return root;

        std::vector<Node *> v;
        bst2vec(v, root);

        int i, n = v.size();

        for (i = 1; i < n; ++i)
        {
            v[i - 1]->right = v[i];
            v[i]->left = v[i - 1];
        }

        v[0]->left = v[n - 1];
        v[n - 1]->right = v[0];

        return v[0];
    }
};
