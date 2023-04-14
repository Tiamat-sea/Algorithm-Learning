/**
 * 给定一个二叉树，找出其最小深度。
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 说明：叶子节点是指没有子节点的节点。
 * 本题由于需要构造还原二叉树，故未实现能运行的代码，仅编写了核心逻辑部分
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
                if (!node->left && !node->right) return depth;
            }
        }
        return depth;
    }
};

int main() {
    vector<int> root = {3, 9, 20, null, null, 15, 7};
}