/**
 * 给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 本题由于需要构造还原二叉树，故未实现能运行的代码，仅编写了核心逻辑部分
*/
#include <iostream>
#include <vector>
#include <queue>
#include "binaryTree.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(vec);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    vector<int> root = {3, 9, 20, null, null, 15, 7};
}