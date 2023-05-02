/**
 * 给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
 * 假设二叉树中至少有一个节点。
*/
#include <iostream>
#include <queue>
#include <vector>
#include "binaryTree.h"
using namespace std;

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        int result;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                if (i == 0) result = node->val;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return result;
    }
};

class Solution2 {
public:
    int maxDepth = INT_MIN;
    int result;

    void traversal(TreeNode* root, int depth) {
        if (root->left == nullptr && root->right == nullptr) {
            if (depth > maxDepth) {
                maxDepth = depth;
                result = root->val;
            }
            return;
        }
        if (root->left) {
            depth++;
            traversal(root->left, depth);
            depth--;
        }
        if (root->right) {
            depth++;
            traversal(root->right, depth);
            depth--;
        }
        return;
    }

    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 0);
        return result;
    }
};

int main() {
    vector<int> root = {1, 2, 3, 4, null, 5, 6, null, null, 7};
    Solution solution;
    TreeNode* treeRoot = levelOrderBuild(root);
    int result = solution.findBottomLeftValue(treeRoot);
    cout << result << endl;
}