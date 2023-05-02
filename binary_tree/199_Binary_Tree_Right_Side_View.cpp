/**
 * 给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
 */
#include <iostream>
#include <vector>
#include <queue>
#include "binaryTree.h"
using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                if (i == (size - 1)) result.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return result;
    }
};

int main() {
    vector<int> root = {1, 2, 3, null, 5, null, 4};
    Solution solution;
    TreeNode* treeRoot = levelOrderBuild(root);
    vector<int> result = solution.rightSideView(treeRoot);
    cout << result << endl;
}