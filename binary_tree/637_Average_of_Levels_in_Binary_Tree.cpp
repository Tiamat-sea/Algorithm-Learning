/**
 * 给定一个非空二叉树的根节点 root , 以数组的形式返回每一层节点的平均值。与实际答案相差 10-5 以内的答案可以被接受。
 * 本题由于需要构造还原二叉树，故未实现能运行的代码，仅编写了核心逻辑部分
 */
#include <iostream>
#include <vector>
#include <queue>
#include "binaryTree.h"
using namespace std;

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            double sum = 0;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                sum += node->val;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            double average = sum / size;
            result.push_back(average);
        }
        return result;
    }
};

int main() {
    vector<int> root = {3, 9, 20, null, null, 15, 7};
}