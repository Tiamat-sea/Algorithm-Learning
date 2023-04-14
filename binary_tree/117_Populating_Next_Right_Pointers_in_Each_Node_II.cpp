/**
 * ����һ����������
 * �������ÿ�� next ָ�룬�����ָ��ָ������һ���Ҳ�ڵ㡣����Ҳ�����һ���Ҳ�ڵ㣬�� next ָ������Ϊ NULL ��
 * ��ʼ״̬�£�����next ָ�붼������Ϊ NULL ��
 * ����������Ҫ���컹ԭ����������δʵ�������еĴ��룬����д�˺����߼�����
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