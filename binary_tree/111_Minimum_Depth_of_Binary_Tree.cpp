/**
 * ����һ�����������ҳ�����С��ȡ�
 * ��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�������
 * ˵����Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
 */
#include <iostream>
#include <queue>
#include <vector>
#include "binaryTree.h"
using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        int depth = 0;
        while (!que.empty()) {
            int size = que.size();
            depth++;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
                if (node->left == nullptr && node->right == nullptr) return depth;
            }
        }
        return depth;
    }
};

class Solution2 {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);
        if (root->left == nullptr && root->right != nullptr) return 1 + rightDepth;
        if (root->left != nullptr && root->right == nullptr) return 1 + leftDepth;
        int result = 1 + min(leftDepth, rightDepth);
        return result;
    }
};


int main() {
    vector<int> root = {3, 9, 20, null, null, 15, 7};
    Solution solution;
    TreeNode* treeRoot = levelOrderBuild(root);
    int result = solution.minDepth(treeRoot);
    cout << result << endl;
}