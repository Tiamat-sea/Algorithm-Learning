/**
 * 给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
 * 完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。
 * 若最底层为第 h 层，则该层包含 1~2h个节点。
 */
#include <iostream>
#include <queue>
#include <vector>
#include "binaryTree.h"
using namespace std;

class Solution {
public:
    int countNodes(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        int result = 0;
        while (!que.empty()) {
            int size = que.size();
            result += size;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
             }
        }
        return result;
    }
};

class Solution2 {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftNum = countNodes(root->left);
        int rightNum = countNodes(root->right);
        int result = leftNum + rightNum + 1;
        return result;
    }

//    int countNodes(TreeNode* root) {
//        if (root == nullptr) return 0;
//        return 1 + countNodes(root->left) + countNodes(root->right);
//    }
};

class Solution3 {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int leftDepth = 0, rightDepth = 0;
        while (left) {
            left = left->left;
            leftDepth++;
        }
        while (right) {
            right = right->right;
            rightDepth++;
        }
        if (leftDepth == rightDepth) return (2 << leftDepth) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

int main() {
    vector<int> root = {1, 2, 3, 4, 5, 6};
    Solution solution;
    TreeNode* treeRoot = levelOrderBuild(root);
    int result = solution.countNodes(treeRoot);
    cout << result << endl;
}