/**
 * 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
 */
#include <queue>
#include <vector>
#include "binaryTree.h"
using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> que;
        if (root) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
                swap(node->left, node->right);
            }
        }
        return root;
    }
};

class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

int main() {
    vector<int> root = {4, 2, 7, 1, 3, 6, 9};
    Solution solution;
    TreeNode* treeRoot = levelOrderBuild(root);
    TreeNode* newTreeRoot = solution.invertTree(treeRoot);
    levelOrderOutput(newTreeRoot);
}