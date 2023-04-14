/**
 * 给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。
 * 树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。
 * 本题由于需要构造还原二叉树，故未实现能运行的代码，仅编写了核心逻辑部分
 */
#include <iostream>
#include <vector>
#include <queue>
#define null INT_MAX
using namespace std;

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

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        queue<Node*> que;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            for (int i = 0; i < size; ++i) {
                Node* node = que.front();
                que.pop();
                vec.push_back(node->val);
                for (int j = 0; j < node->children.size(); ++j) {
                    if (node->children[j]) que.push(node->children[j]);
                }
            }
            result.push_back(vec);
        }
        return result;
    }
};

int main() {
    vector<int> root = {1, null, 2, 3, 4, 5, null, null, 6, 7, null, 8, null, 9, 10, null, null, 11, null, 12, null, 13, null, null, 14};
}