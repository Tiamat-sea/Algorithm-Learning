/**
 * ����һ�����������ҳ��������ȡ�
 * �����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
 * ˵��:Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
 * ʾ����
 * ���������� [3,9,20,null,null,15,7]��
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * ��������������3 ��
 * ����������Ҫ���컹ԭ����������δʵ�������еĴ��룬����д�˺����߼�����
 */
#include <iostream>
#include <queue>
#include <vector>
#include "binaryTree.h"
using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> que;
        if (root) que.push(root);
        int depth = 0;
        while (!que.empty()) {
            int size = que.size();
            depth++;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return depth;
    }
};

int main() {
    vector<int> root = {3, 9, 20, null, null, 15, 7};
}