/**
 * 给定一个二叉树：
 * 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL 。
 * 初始状态下，所有next 指针都被设置为 NULL 。
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
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if (root) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            Node* preNode, * node;
            for (int i = 0; i < size; ++i) {
                if (i == 0) {
                    preNode = que.front();
                    que.pop();
                    node = preNode;
                }
                else {
                    node = que.front();
                    que.pop();
                    preNode->next = node;
                    preNode = preNode->next;
                }
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            preNode->next = nullptr;
        }
        return root;
    }
};

int main() {
    vector<int> root = {1, 2, 3, 4, 5, null, 7};
}