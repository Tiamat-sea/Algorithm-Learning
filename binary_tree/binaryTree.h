#ifndef BINARY_TREE_BINARYTREE_H
#define BINARY_TREE_BINARYTREE_H

#include <queue>
#include "vector_output.h"
#define null INT_MAX//����nullΪint�����ֵ��ʾָ��ָ��nullptr
using namespace std;

//����������
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//�����������������,���ظ��ڵ�
TreeNode* levelOrderBuild(vector<int> levelOrder) {
    if (levelOrder.empty()) return nullptr;
    TreeNode* root = new TreeNode(levelOrder[0]);
    queue<TreeNode*> que;
    que.push(root);
    int i = 1;
    while (!que.empty() && i < levelOrder.size()) {
        TreeNode* node = que.front();
        que.pop();
        if (i < levelOrder.size() && levelOrder[i] != null) {
            node->left = new TreeNode(levelOrder[i]);
            que.push(node->left);
        }
        i++;
        if (i < levelOrder.size() && levelOrder[i] != null) {
            node->right = new TreeNode(levelOrder[i]);
            que.push(node->right);
        }
        i++;
    }
    return root;
}

//�������������,����vector����;
vector<int> myLevelOrder(TreeNode* root) {
    vector<int> result;
    queue<TreeNode*> que;
    if (root != nullptr) que.push(root);
    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* node = que.front();
            que.pop();
            if (node == nullptr) result.push_back(null);
            else {
                result.push_back(node->val);
                if (!node->left) que.push(nullptr);
                else que.push(node->left);

                if (!node->right) que.push(nullptr);
                else que.push(node->right);
            }
        }
    }
    int i = result.size() - 1;
    while (result[i] == null) {//ȥ��ĩβ�����null
        result.pop_back();
        i--;
    }
    return result;
}

void levelOrderOutput(TreeNode* root) {
    vector<int> levelOrder = myLevelOrder(root);
    cout << levelOrder << endl;
}

#endif //BINARY_TREE_BINARYTREE_H