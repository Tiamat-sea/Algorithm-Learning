/**
 * 给定一个 N 叉树，找到其最大深度。
 * 最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。
 * N 叉树输入按层序遍历序列化表示，每组子节点由空值分隔（请参见示例）。
 * 本题由于需要构造还原n叉树，故未实现能运行的代码，仅编写了核心逻辑部分
 */
#include <iostream>
#include <queue>
#include <vector>
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
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        int depth = 0;
        for (int i = 0; i < root->children.size(); ++i) {
            depth = max(depth, maxDepth(root->children[i]));
        }
        return depth + 1;
    }
};

class Solution2 {
public:
    int maxDepth(Node* root) {
        queue<Node*> que;
        if (root != nullptr) que.push(root);
        int depth = 0;
        while (!que.empty()) {
            int size = que.size();
            depth++;
            for (int i = 0; i < size; ++i) {
                Node* node = que.front();
                que.pop();
                for (int j = 0; j < node->children.size(); ++j) {
                    if (node->children[j]) que.push(node->children[j]);
                }
            }
        }
        return depth;
    }
};

int main() {
    vector<int> root = {1, null, 3, 2, 4, null, 5, 6};
}